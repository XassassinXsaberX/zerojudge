#include <stdio.h>
#include <stdlib.h>
#define INFINITE 100000000

/*
利用Floyd-Warshall algorithm找shortest path
*/ 

void floyd(int adj_matrix[22][22],int A[22][22],int n);

int main()
{
	int adj_matrix[22][22];
	int shortest[22][22];
	int N,M;
	int start,end,length;
	int min_length;
	int sum_value;
	char *ans;
	char name[22][11];
	int i,j,k;
	int c=1;
	
	while(scanf("%d %d",&N,&M)!=EOF)
	{
		if(N==0 && M==0)
			break;
		
		for(i=0;i<N;i++)
			scanf("%s",name[i]);
			
		//初始化adjancey matrix 
		for(i=0;i<N;i++)
			for(j=0;j<N;j++)
			{
				if(i == j)
					adj_matrix[i][j] = 0;
				else
					adj_matrix[i][j] = INFINITE;
			}
		//接下來才是要建立adjancey matrix
		for(i=0;i<M;i++)
		{
			scanf("%d %d %d",&start,&end,&length);
			adj_matrix[start-1][end-1] = length;
			adj_matrix[end-1][start-1] = length;
		}
		
		floyd(adj_matrix,shortest,N); //利用Floyd-Warshall algorithm找shortest path
		
		//接下來找，尋找以哪個點為終點時，其他點到此點其(最短距離總和)會最小 
		min_length = INFINITE;
		for(i=0;i<N;i++)
		{
			//若以第i人當作終點時
			//找出其他人到這一個人的最短距離的總和 
			sum_value = 0;
			for(j=0;j<N;j++)
				sum_value += shortest[i][j];
			
			if(sum_value < min_length)
			{
				min_length = sum_value;
				ans = name[i];
			}		
		}
		
		printf("Case #%d : %s\n",c++,ans);
		
	}
	return 0;
}

void floyd(int adj_matrix[22][22],int A[22][22],int n)
{
	//A用來紀錄端點間的shortest path長度
	//n用來紀錄有幾個端點
	int i,j,k;
	
	//使用floyd-warshall 演算法找最短路徑時，要先初始化最短路徑矩陣為adjancey matrix 
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			A[i][j] = adj_matrix[i][j];
	
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(A[i][k] + A[k][j] < A[i][j])   //若(端點i)經過(端點k)到(端點j)的距離 會比(端點i)到(端點j)的距離短 
					A[i][j] = A[i][k] + A[k][j];  //則更新(端點i)到(端點j)的最短距離 
					
}
