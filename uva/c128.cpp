#include <iostream>
#include <map>
#include <stdlib.h> 
#define INFINITE 100000000
#define min(a,b) ((a)<(b))?(a):(b)

/*�Q��Floyd-Warshall algorithm�ѨM����shortest path �����D*/

using namespace std;
void floyd(int**graph,int n);


int main()
{
	int n,r;
	map<string,int> MAP;  //�ΨӱN�r���ഫ���Ʀr
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
		//�ʺA���t�G���}�C 
		graph = new int*[n];
		for(i=0;i<n;i++)
			graph[i] = new int[n];
			
		//���U�Ӫ�l�ƹϫ�
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				if(i == j)
					graph[i][j] = 0;
				else
					graph[i][j] = -INFINITE;
			}
				
				 
		index = 0 ;//�ΨӥN��C�ӫ������N��
		
		//�H�U�}�l�إ߹ϧΪ��v�� 
		for(i=0;i<r;i++)
		{
			cin>>city1>>city2>>weight;
			
			
			//�M��city1���s�� 
			iter = MAP.find(city1);
			if(iter == MAP.end())
			{
				index1 = index;                               //�N��city1 ���и� index1 
				MAP.insert(pair<string,int>(city1,index++));  //�Ncity1 �P�ӽs�����map�e���� 
			}
			else
				index1 = iter->second;                        //�N��city1 ���s�� index1
				
			//�M��city2���s�� 
			iter = MAP.find(city2);
			if(iter == MAP.end())
			{
				index2 = index;                               //�N��city2 ���и� index12 
				MAP.insert(pair<string,int>(city2,index++));  //�Ncity2 �P�ӽs�����map�e���� 
			}
			else
				index2 = iter->second;                        //�N��city1���s�� index1 
				
			graph[index1][index2] = weight;
			graph[index2][index1] = weight; 
			
		} 
		
		cin>>city1>>city2; 
		
		
		//�M��city1���s�� 
		iter = MAP.find(city1);
		index1 = iter->second;                        //�N��city1 ���s�� index1
			
		//�M��city2���s�� 
		iter = MAP.find(city2);
		index2 = iter->second;                        //�N��city2 ���s�� index2
		
		//�Q��Floyd-Warshall algorithm�ѨM����shortest path �����D
		floyd(graph,n);
		
		cout<<"Scenario #"<<c++<<endl;
		ans = min(graph[index1][index2],graph[index2][index1]);
		cout<< ans <<" tons"<<endl;	
	 
		
		
		//����G���}�C�Ŷ� 
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








