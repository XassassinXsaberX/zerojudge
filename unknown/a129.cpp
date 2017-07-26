#include <iostream>
#include <algorithm>
#include <vector>
#include <set> 
#include <queue>
#include <deque> 
#include <list> 

using namespace std;

/*�Q��Kruskal�t��k��Prim�t��k�ӱq�ϧΤ���Xminimum spanning tree*/

struct Edge
{
	int p1,p2; //�N�����I 
	int weight;//�N��weight
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
int find_root(int*set,int point);//��Xdisjoint sets forest���A���I��point��root���I���� 

int main()
{
	vector<Edge> v;
	int n,m;     //n�N���X���I�Bm�N���X���� 
	long long int ans; 
	int i,j,k;
	while(cin>>n>>m)
	{
		
			
		for(i=0;i<m;i++) //�̧ǥ[�J�U���� 
		{
			v.push_back(Edge()); 
			cin>>v[i].p1>>v[i].p2>>v[i].weight; 
		}
		
		ans = Kruskal(v,n); 
		//��i��Prim algorithm 
		//ans = Prim(v,n); 
		
		cout<<ans<<endl; 
		
		v.clear(); 
	}
	return 0; 
	
	
	
}

long long int Kruskal(vector<Edge> v,int n) // v�N�����"��"�����X�Bn�N���X�Ӻ��I 
{
	int i,j,k;
	int count=0;                       // �����[�J�X��"��"�A�]����n����A�ҥH�n�[�Jn-1��"��"�~�|�ܦ�spanning tree 
	int root1,root2;
	long long int total_weight=0;      // ����minimum spanning tree��total weight 
	int*set_forest = new int[100000];  // disjoint sets forest (�o�O�ΨӧP�_�ϧάO�_�X�{cycle)
	int*set_num = new int[100000];     // ����disjoint sets forest��set���h�֤��� 
	
	for(i=0;i<n;i++)                   // ��l��disjoint sets forest
	{
		set_forest[i] = i;
		set_num[i] = 1;                //�@�}�l���C�Ӷ��X���u���@�Ӥ��� 
	}	    
		
		
	sort(v.begin(),v.end(),Cmp());		//�����䪺weight�j�p�ӱƧ�
	
	for(i=0;i<v.size();i++)
	{
		// �[�J�䤧�e�A���P�_�[�J�����O�_�|�X�{cycle
		root1 = find_root(set_forest,v[i].p1);
		root2 = find_root(set_forest,v[i].p2);
		if(root1 != root2) // ���o��cycle�A�ҥH�i�[�J���� 
		{
			count++;
			// �n�`�N�@��ơA�Y���X1�������񶰦X2�h
			// �h���X2��root�Ы��V���X1  
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
			total_weight += v[i].weight;  //�έptotal_weight 
		} 
		 
	}
	delete [] set_forest;
	delete [] set_num; 
	if(count == n-1)	
		return total_weight;
	else  //�p�G���Ospanning tree 
		return -1; 
}

long long int Prim(vector<Edge> v,int n)   // v�N�����"��"�����X�Bn�N���X�Ӻ��I
{
	int i,j,k;
	vector<list<Edge> > adj_list;
	list<Edge>::iterator iter;
	// �ڥΤF��ؼg�k�ӧ������t��k�A�@�جO�Q��priority_queue�A�t�@�جO��set�e�� 
	priority_queue<Edge, deque<Edge>, greater<Edge> >  p; //�ΨӬ����P"�w��������I" �� "�۾F����"�����X 
	set<Edge, less<Edge> > s;  							  //�ΨӬ����P"�w��������I" �� "�۾F����"�����X  
	int root1,root2; 
	int temp_p1,temp_p2;
	int count = 0;                     // ��������F�h�֭��� 
	int*set_forest = new int[100000];  // disjoint sets forest (�o�O�ΨӧP�_�ϧάO�_�X�{cycle)
	long long int total_weight=0;      // ����minimum spanning tree��total weight
	int*set_num = new int[100000];     // ����disjoint sets forest��set���h�֤���
	
	for(i=0;i<n;i++)                   // ��l��disjoint sets forest
	{
		set_forest[i] = i;
		set_num[i] = 1;                // �@�}�l���C�Ӷ��X���u���@�Ӥ��� 
	}	    
	
	// ���إߦn�ϧΪ�adjacency list
	for(i=0;i<n;i++)
		adj_list.push_back(list<Edge>());
	for(i=0;i<v.size();i++)
	{
		adj_list[v[i].p1].push_back(v[i]); //�N��p1���I�s�b ��v[i] 
		adj_list[v[i].p2].push_back(v[i]); //�N��p2���I�s�b ��v[i] 
	} 
	
	//�q���I0�}�l�إ�minimum spanning tree
	//���N�P���I0�۾F��"��"�������priority_queue�� 
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
		
		//�[�J�䤧�e���P�_�O�_�|����cycle 
		//root1 = find_root(set_forest,p.top().p1);
		//root2 = find_root(set_forest,p.top().p2);
		root1 = find_root(set_forest,s.begin()->p1);
		root2 = find_root(set_forest,s.begin()->p2);
		
		if(root1 != root2) // ���o��cycle�A�ҥH�i�[�J���� 
		{
			count++;
			
			//total_weight += p.top().weight;  //�έptotal_weight 
			total_weight += s.begin()->weight;  //�έptotal_weight 
			//p.pop(); 
			s.erase(s.begin()); 
			
			// �]���s�[�J�@�Ӻ��I�A�ҥH�n��P�Ӻ��I�۾F������priority_queue��
			if(set_num[root1] == 1 && root1 != 0) // �Y�s�[�J���I��root1 
			{
				for(iter=adj_list[root1].begin();iter!=adj_list[root1].end();iter++)
					//p.push(*iter);
					s.insert(*iter); 
					
				// �n�`�N�@��ơA�Y���X2�������񶰦X1�h
				// �h���X1��root�Ы��V���X2
				set_forest[root1] = root2;
				set_num[root2]+=set_num[root1];
			}
			else if(set_num[root2] == 1 && root2 != 0) // �Y�s�[�J���I��root2 
			{
				for(iter=adj_list[root2].begin();iter!=adj_list[root2].end();iter++)
					//p.push(*iter);
					s.insert(*iter); 
					
				// �n�`�N�@��ơA�Y���X1�������񶰦X2�h
				// �h���X2��root�Ы��V���X1 
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
	else  //�p�G���Ospanning tree 
		return -1; 

}

int find_root(int*set_forest,int point)//��Xdisjoint sets forest���A���I��point��root���I���� 
{
	while(1)
	{
		if(set_forest[point] != point)
			point = set_forest[point];
		else
			return point;
	}
} 













