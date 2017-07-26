#include <iostream>
#include <algorithm>
#include <vector>
#include <set> 
#include <queue>
#include <deque> 
#include <list> 

using namespace std;

/*利用Kruskal演算法或Prim演算法來從圖形中找出minimum spanning tree*/

struct Edge
{
	int p1,p2; //代表兩端點 
	int weight;//代表weight
	bool operator>(const Edge&e) const
	{
		if(this->weight > e.weight)
			return true;
		else
			return false;
	}
	bool operator==(const Edge&e) const
	{
		if(this->weight == e.weight)
		{
			if(this->p1 == e.p1 && this->p2 == e.p2)
				return true;	 
			else if(this->p1 == e.p2 && this->p2 == e.p1)
				return true;
			else
				return false; 
		} 	
		else
			return false;
	}
	bool operator<(const Edge&e) const
	{
		if(this->weight < e.weight)
			return true;
		else if(*this > e || *this == e)
			return false;
		else
			return true;
	}
};

struct Cmp
{
	bool operator()(const Edge&e1,const Edge&e2)
	{
		if(e1.weight < e2.weight)
			return true;
		else
			return false;
	}
};


long long int Kruskal(vector<Edge>,int n);
long long int Prim(vector<Edge>,int n);
int find_root(int*set,int point);//找出disjoint sets forest中，端點為point的root頂點為何 

int main()
{
	vector<Edge> v;
	int n,m;     //n代表有幾個點、m代表有幾個邊 
	long long int ans; 
	int i,j,k;
	while(cin>>n>>m)
	{
		
			
		for(i=0;i<m;i++) //依序加入各個邊 
		{
			v.push_back(Edge()); 
			cin>>v[i].p1>>v[i].p2>>v[i].weight; 
		}
		
		ans = Kruskal(v,n); 
		//亦可用Prim algorithm 
		//ans = Prim(v,n); 
		
		cout<<ans<<endl; 
		
		v.clear(); 
	}
	return 0; 
	
	
	
}

long long int Kruskal(vector<Edge> v,int n) // v代表全部"邊"的集合、n代表有幾個端點 
{
	int i,j,k;
	int count=0;                       // 紀錄加入幾次"邊"，因為有n個邊，所以要加入n-1個"邊"才會變成spanning tree 
	int root1,root2;
	long long int total_weight=0;      // 紀錄minimum spanning tree的total weight 
	int*set_forest = new int[100000];  // disjoint sets forest (這是用來判斷圖形是否出現cycle)
	int*set_num = new int[100000];     // 紀錄disjoint sets forest的set有多少元素 
	
	for(i=0;i<n;i++)                   // 初始化disjoint sets forest
	{
		set_forest[i] = i;
		set_num[i] = 1;                //一開始的每個集合都只有一個元素 
	}	    
		
		
	sort(v.begin(),v.end(),Cmp());		//按照邊的weight大小來排序
	
	for(i=0;i<v.size();i++)
	{
		// 加入邊之前，先判斷加入該邊後是否會出現cycle
		root1 = find_root(set_forest,v[i].p1);
		root2 = find_root(set_forest,v[i].p2);
		if(root1 != root2) // 不發生cycle，所以可加入此邊 
		{
			count++;
			// 要注意一件事，若集合1的元素比集合2多
			// 則集合2的root請指向集合1  
			if(set_num[root1] >= set_num[root2])  
			{
				set_forest[root2] = root1;
				set_num[root1]+=set_num[root2];
			}
			else
			{
				set_forest[root1] = root2;
				set_num[root2]+=set_num[root1];
			}
			total_weight += v[i].weight;  //統計total_weight 
		} 
		 
	}
	delete [] set_forest;
	delete [] set_num; 
	if(count == n-1)	
		return total_weight;
	else  //如果不是spanning tree 
		return -1; 
}

long long int Prim(vector<Edge> v,int n)   // v代表全部"邊"的集合、n代表有幾個端點
{
	int i,j,k;
	vector<list<Edge> > adj_list;
	list<Edge>::iterator iter;
	// 我用了兩種寫法來完成此演算法，一種是利用priority_queue，另一種是用set容器 
	priority_queue<Edge, deque<Edge>, greater<Edge> >  p; //用來紀錄與"已選取的頂點" 所 "相鄰的邊"的集合 
	set<Edge, less<Edge> > s;  							  //用來紀錄與"已選取的頂點" 所 "相鄰的邊"的集合  
	int root1,root2; 
	int temp_p1,temp_p2;
	int count = 0;                     // 紀錄選取了多少個邊 
	int*set_forest = new int[100000];  // disjoint sets forest (這是用來判斷圖形是否出現cycle)
	long long int total_weight=0;      // 紀錄minimum spanning tree的total weight
	int*set_num = new int[100000];     // 紀錄disjoint sets forest的set有多少元素
	
	for(i=0;i<n;i++)                   // 初始化disjoint sets forest
	{
		set_forest[i] = i;
		set_num[i] = 1;                // 一開始的每個集合都只有一個元素 
	}	    
	
	// 先建立好圖形的adjacency list
	for(i=0;i<n;i++)
		adj_list.push_back(list<Edge>());
	for(i=0;i<v.size();i++)
	{
		adj_list[v[i].p1].push_back(v[i]); //代表p1頂點存在 邊v[i] 
		adj_list[v[i].p2].push_back(v[i]); //代表p2頂點存在 邊v[i] 
	} 
	
	//從頂點0開始建立minimum spanning tree
	//先將與頂點0相鄰的"邊"全部丟到priority_queue中 
	for(iter=adj_list[0].begin();iter!=adj_list[0].end();iter++)
	{
		//p.push(*iter);
		s.insert(*iter); 
	} 
		
		
	while(1)
	{
		//if(p.size()==0)
		//	break;	
		if(s.size()==0)
			break; 
		
		//加入邊之前先判斷是否會產生cycle 
		//root1 = find_root(set_forest,p.top().p1);
		//root2 = find_root(set_forest,p.top().p2);
		root1 = find_root(set_forest,s.begin()->p1);
		root2 = find_root(set_forest,s.begin()->p2);
		
		if(root1 != root2) // 不發生cycle，所以可加入此邊 
		{
			count++;
			
			//total_weight += p.top().weight;  //統計total_weight 
			total_weight += s.begin()->weight;  //統計total_weight 
			//p.pop(); 
			s.erase(s.begin()); 
			
			// 因為新加入一個端點，所以要把與該端點相鄰的邊丟到priority_queue中
			if(set_num[root1] == 1 && root1 != 0) // 若新加入的點為root1 
			{
				for(iter=adj_list[root1].begin();iter!=adj_list[root1].end();iter++)
					//p.push(*iter);
					s.insert(*iter); 
					
				// 要注意一件事，若集合2的元素比集合1多
				// 則集合1的root請指向集合2
				set_forest[root1] = root2;
				set_num[root2]+=set_num[root1];
			}
			else if(set_num[root2] == 1 && root2 != 0) // 若新加入的點為root2 
			{
				for(iter=adj_list[root2].begin();iter!=adj_list[root2].end();iter++)
					//p.push(*iter);
					s.insert(*iter); 
					
				// 要注意一件事，若集合1的元素比集合2多
				// 則集合2的root請指向集合1 
				set_forest[root2] = root1;
				set_num[root1]+=set_num[root2];
			}
			
		} 
		else 
			//p.pop(); 
			s.erase(s.begin()); 
	}	
	delete [] set_forest; 
	delete [] set_num; 
	if(count == n-1)	
		return total_weight;
	else  //如果不是spanning tree 
		return -1; 

}

int find_root(int*set_forest,int point)//找出disjoint sets forest中，端點為point的root頂點為何 
{
	while(1)
	{
		if(set_forest[point] != point)
			point = set_forest[point];
		else
			return point;
	}
} 













