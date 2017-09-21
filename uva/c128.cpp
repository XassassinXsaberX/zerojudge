#include <iostream>
#include <map>
#include <stdlib.h> 
#define INFINITE 100000000
#define min(a,b) ((a)<(b))?(a):(b)

/*利用Floyd-Warshall algorithm解決類似shortest path 的問題*/

using namespace std;
void floyd(int**graph,int n);


int main()
{
	int n,r;
	map<string,int> MAP;  //用來將字串轉換成數字
	map<string,int>::iterator iter,iter1,iter2;
	string city1,city2;
	int index,index1,index2;
	int weight;
	int**graph,*ptr;
	int i,j,k;
	int c=1;
	int ans;
	
	while(cin>>n>>r)
	{
		if(n==0 && r==0)
			break;
		//動態分配二維陣列 
		graph = new int*[n];
		for(i=0;i<n;i++)
			graph[i] = new int[n];
			
		//接下來初始化圖型
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				if(i == j)
					graph[i][j] = 0;
				else
					graph[i][j] = -INFINITE;
			}
				
				 
		index = 0 ;//用來代表每個城市的代號
		
		//以下開始建立圖形的權重 
		for(i=0;i<r;i++)
		{
			cin>>city1>>city2>>weight;
			
			
			//尋找city1的編號 
			iter = MAP.find(city1);
			if(iter == MAP.end())
			{
				index1 = index;                               //代表city1 為標號 index1 
				MAP.insert(pair<string,int>(city1,index++));  //將city1 與該編號丟到map容器中 
			}
			else
				index1 = iter->second;                        //代表city1 為編號 index1
				
			//尋找city2的編號 
			iter = MAP.find(city2);
			if(iter == MAP.end())
			{
				index2 = index;                               //代表city2 為標號 index12 
				MAP.insert(pair<string,int>(city2,index++));  //將city2 與該編號丟到map容器中 
			}
			else
				index2 = iter->second;                        //代表city1為編號 index1 
				
			graph[index1][index2] = weight;
			graph[index2][index1] = weight; 
			
		} 
		
		cin>>city1>>city2; 
		
		
		//尋找city1的編號 
		iter = MAP.find(city1);
		index1 = iter->second;                        //代表city1 為編號 index1
			
		//尋找city2的編號 
		iter = MAP.find(city2);
		index2 = iter->second;                        //代表city2 為編號 index2
		
		//利用Floyd-Warshall algorithm解決類似shortest path 的問題
		floyd(graph,n);
		
		cout<<"Scenario #"<<c++<<endl;
		ans = min(graph[index1][index2],graph[index2][index1]);
		cout<< ans <<" tons"<<endl;	
	 
		
		
		//釋放二維陣列空間 
		for(i=0;i<n;i++)
			delete [] graph[i];
		delete [] graph;
		MAP.clear();
	}
	return 0;
	
}


void floyd(int**graph,int n)
{
	int i,j,k;
	int min_value;	
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				min_value = min(graph[i][k],graph[k][j]);
				if(min_value > graph[i][j])
					graph[i][j] = min_value;
			}
}








