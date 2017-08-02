#include <stdio.h>
#include <stdlib.h>
#define INFINITE 100000000 

/*
Floyd - Warshall 簍衡猭跑て 
硂Ωshortest path痻皚ぃ琌虫ㄢ竊翴程祏禯瞒
τ琌ㄢ竊翴隔畖い兵隔畖Τ(程(程weight))
ex
安砞Τ4竊翴㎝4兵娩 
竊翴1  -->  竊翴2  weight = 10
竊翴2  -->  竊翴3  weight = 15
竊翴1  -->  竊翴4  weight = 5
竊翴4  -->  竊翴3  weight = 3 

┮ 竊翴1  -->  竊翴2  -->  竊翴3  程weight = 15 
     竊翴1  -->  竊翴4  -->  竊翴3  程weight = 5  

珿竊翴1  竊翴3 隔畖い(程(程weight)) = 5
*/     



void floyd(int adj_matrix[100][100],int shortest[100][100],int n);

int main()
{
	int adj_matrix[100][100];
	int shortest[100][100];    //竊翴程祏隔畖
	int C,S,Q;
	int start,end,noise;
	int i,j,k;
	int c=1;
	while(scanf("%d %d %d",&C,&S,&Q)!=EOF) //ΤC竊翴S娩Q高拜 
	{
		if(C==0 && S==0 && Q==0)
			break;
		
		//﹍てadjacency matrix 
		for(i=0;i<C;i++)
			for(j=0;j<C;j++)
			{
				if(i==j)
					adj_matrix[i][j] = 0;
				else
					adj_matrix[i][j] = INFINITE; 
			} 
		//钡ㄓ璶ミadjacency matrix
		for(i=0;i<S;i++)
		{
			scanf("%d %d %d",&start,&end,&noise);
			adj_matrix[start-1][end-1] = noise;
			adj_matrix[end-1][start-1] = noise; 
		} 
		
		//ㄏノfloyd-warshall 程祏隔畖簍衡猭 
		floyd(adj_matrix,shortest,C);
		
		printf("Case #%d\n",c++);
		for(i=0;i<Q;i++)
		{
			scanf("%d %d",&start,&end);
			if(shortest[start-1][end-1] == INFINITE)
				printf("no path\n");
			else
				printf("%d\n",shortest[start-1][end-1]);
		} 
		
	}
	return 0;
	 
	
}

void floyd(int adj_matrix[100][100],int shortest[100][100],int n)
{
	int i,j,k;
	int max;
	//ㄏノfloyd-warshall 程祏隔畖簍衡猭璶砞﹚程祏隔畖痻皚籔adjacency matrix 
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			shortest[i][j] = adj_matrix[i][j];
			
	//钡ㄓ秨﹍т竊翴i竊翴j(程(程weight))
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				//т竊翴i竊翴K程(程(程weight))shortest[i][k]の竊翴k竊翴j(程(程weight))shortest[k][j]ㄢ计程 
				if(shortest[i][k] > shortest[k][j])
					max = shortest[i][k];
				else
					max = shortest[k][j];
				if(max < shortest[i][j])      //璝max穦ゑ竊翴i竊翴j(程(程weight))祏杠 
						shortest[i][j] = max; //玥穝竊翴i竊翴j(程(程weight))
			
			}
				
	
	
}



