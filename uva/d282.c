#include <stdio.h>
#include <stdlib.h>
#define INFINITE 100000000

/*
�Q��Floyd-Warshall algorithm��shortest path
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
			
		//��l��adjancey matrix 
		for(i=0;i<N;i++)
			for(j=0;j<N;j++)
			{
				if(i == j)
					adj_matrix[i][j] = 0;
				else
					adj_matrix[i][j] = INFINITE;
			}
		//���U�Ӥ~�O�n�إ�adjancey matrix
		for(i=0;i<M;i++)
		{
			scanf("%d %d %d",&start,&end,&length);
			adj_matrix[start-1][end-1] = length;
			adj_matrix[end-1][start-1] = length;
		}
		
		floyd(adj_matrix,shortest,N); //�Q��Floyd-Warshall algorithm��shortest path
		
		//���U�ӧ�A�M��H�����I�����I�ɡA��L�I�즹�I��(�̵u�Z���`�M)�|�̤p 
		min_length = INFINITE;
		for(i=0;i<N;i++)
		{
			//�Y�H��i�H��@���I��
			//��X��L�H��o�@�ӤH���̵u�Z�����`�M 
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
	//A�ΨӬ������I����shortest path����
	//n�ΨӬ������X�Ӻ��I
	int i,j,k;
	
	//�ϥ�floyd-warshall �t��k��̵u���|�ɡA�n����l�Ƴ̵u���|�x�}��adjancey matrix 
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			A[i][j] = adj_matrix[i][j];
	
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(A[i][k] + A[k][j] < A[i][j])   //�Y(���Ii)�g�L(���Ik)��(���Ij)���Z�� �|��(���Ii)��(���Ij)���Z���u 
					A[i][j] = A[i][k] + A[k][j];  //�h��s(���Ii)��(���Ij)���̵u�Z�� 
					
}
