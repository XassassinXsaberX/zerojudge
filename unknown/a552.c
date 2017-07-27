#include <stdio.h>
#include <stdlib.h>

/*
練習圖論的拓墣排序(topology sort)
*/

void topology_sort(int n,int result[100],int adj_matrix[100][100],int in_degree[100]);

int main()
{
	int n,m;
	int adj_matrix[100][100];
	int in_degree[100];  //記錄每個端點的in-degree值 
	int result[100];     //紀錄拓墣排序的結果 
	int i,j,k;
	int s,e;
	
	while(scanf("%d %d",&n,&m)!=EOF)//n個端點，m個邊 
	{
		//先初始化adjacency matrix 
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				adj_matrix[i][j] = 0;
		//初始化in_degree array
		for(i=0;i<n;i++)
			in_degree[i] = 0; 
		
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&s,&e);
			adj_matrix[s][e] = 1;  //端點s可以到端點e 
			in_degree[e]++;        //端點e的in-degree值加1 
		}
		
		topology_sort(n,result,adj_matrix,in_degree);
		
		for(i=0;i<n;i++)
			printf("%d ",result[i]);
		printf("\n");
		
	}
	return 0;
}

void topology_sort(int n,int result[100],int adj_matrix[100][100],int in_degree[100])
{
	// 總共有n的端點 
	// result為排序結果
	// in_degree記錄每個端點的in-degree value 
	int count=0;
	int i,j,k;
	count = 0;
	while(1)
	{
		//先按照字典順序找出in-degree為0的端點
		for(i=0;i<n;i++)
		{
			if(in_degree[i] == 0) //若端點i的in-degree = 0 
			{
				in_degree[i] = -1;   //代表該端點不會再被搜尋 
				result[count++] = i; //紀錄拓樸排序的結果 
				
				if(count == n)       //如果已完成拓墣排序，就跳出函式 
					return ;
				
				// 將端點i的immediate sucessor(立刻後繼者)的in-degree減1 
				// 現在要找出端點i的 immediate sucessor
				for(j=0;j<n;j++)
				{
					if(adj_matrix[i][j] == 1 && in_degree[j]>0)
						in_degree[j]--; 
				}	
				
				break;
			} 
		} 
	}
	

}
