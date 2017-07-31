#include <stdio.h>
#include <stdlib.h>

/*
利用Floyd-Warshall algorithm找shortest path
*/

void floyd(int A[100][100],int adj_matrix[100][100],int N);

int main()
{
	int T;
	int N,R;
	int u,v;
	int adj_matrix[100][100];
	int A[100][100];          //用來紀錄不同頂點間的最短路徑 
	int i,j,k,l;
	int i1,i2;
	int c;
	int ans;
	while(scanf("%d",&T)!=EOF)
	{
		c=1;
		for(l=0;l<T;l++)
		{
			scanf("%d",&N); //有幾個端點 
			scanf("%d",&R); //有幾條邊 
			
			//先初始化adjacency matrix 
			for(i=0;i<N;i++)
				for(j=0;j<N;j++)
				{
					//若要使用Floyd - Warshall最短路徑演算法，必須進行以下的初始化 
					if(i==j)
						adj_matrix[i][j] = 0;   
					else
						adj_matrix[i][j] = 1000000;
				}		
				
			//建立adjacency matrix	
			for(j=0;j<R;j++)
			{
				scanf("%d %d",&i1,&i2);
				adj_matrix[i1][i2] = 1;
				adj_matrix[i2][i1] = 1;
			}
			scanf("%d %d",&u,&v); //分別代表起點和終點 
			
			floyd(A,adj_matrix,N);
			// 執行完 Floyd - Warshall最短路徑演算法後，若A[i][j] = 20
			// 代表節點i到節點j的最短路徑長度為20 
			
			// 尋找從起點u出發，經過某一個節點最後到終點v時
			// 所有可能的最短路徑中，距離最大值為何 
			ans = 0;
			for(i=0;i<N;i++)
				if(A[u][i]+A[i][v] > ans)
					ans = A[u][i]+A[i][v];
			
			printf("Case %d: %d\n",c++,ans);
			
		
		}
	}
	return 0;
}

void floyd(int A[100][100],int adj_matrix[100][100],int N)
{
	int i,j,k;
	//A陣列是用來紀錄不同頂點間的最短路徑  
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			A[i][j] = adj_matrix[i][j];
	
	for(k=0;k<N;k++)
		for(i=0;i<N;i++)
			for(j=0;j<N;j++)
			{
				if(A[i][j] > A[i][k] + A[k][j])  //若(節點i)經過(節點k)到(節點j)會比較快時，更新節點i到節點j的最短距離 
					A[i][j] = A[i][k] + A[k][j];
			}
	
	
}
