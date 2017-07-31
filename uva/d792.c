#include <stdio.h>
#include <stdlib.h>

/*
�Q��Floyd-Warshall algorithm��shortest path
*/

void floyd(int A[100][100],int adj_matrix[100][100],int N);

int main()
{
	int T;
	int N,R;
	int u,v;
	int adj_matrix[100][100];
	int A[100][100];          //�ΨӬ������P���I�����̵u���| 
	int i,j,k,l;
	int i1,i2;
	int c;
	int ans;
	while(scanf("%d",&T)!=EOF)
	{
		c=1;
		for(l=0;l<T;l++)
		{
			scanf("%d",&N); //���X�Ӻ��I 
			scanf("%d",&R); //���X���� 
			
			//����l��adjacency matrix 
			for(i=0;i<N;i++)
				for(j=0;j<N;j++)
				{
					//�Y�n�ϥ�Floyd - Warshall�̵u���|�t��k�A�����i��H�U����l�� 
					if(i==j)
						adj_matrix[i][j] = 0;   
					else
						adj_matrix[i][j] = 1000000;
				}		
				
			//�إ�adjacency matrix	
			for(j=0;j<R;j++)
			{
				scanf("%d %d",&i1,&i2);
				adj_matrix[i1][i2] = 1;
				adj_matrix[i2][i1] = 1;
			}
			scanf("%d %d",&u,&v); //���O�N��_�I�M���I 
			
			floyd(A,adj_matrix,N);
			// ���槹 Floyd - Warshall�̵u���|�t��k��A�YA[i][j] = 20
			// �N��`�Ii��`�Ij���̵u���|���׬�20 
			
			// �M��q�_�Iu�X�o�A�g�L�Y�@�Ӹ`�I�̫����Iv��
			// �Ҧ��i�઺�̵u���|���A�Z���̤j�Ȭ��� 
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
	//A�}�C�O�ΨӬ������P���I�����̵u���|  
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			A[i][j] = adj_matrix[i][j];
	
	for(k=0;k<N;k++)
		for(i=0;i<N;i++)
			for(j=0;j<N;j++)
			{
				if(A[i][j] > A[i][k] + A[k][j])  //�Y(�`�Ii)�g�L(�`�Ik)��(�`�Ij)�|����֮ɡA��s�`�Ii��`�Ij���̵u�Z�� 
					A[i][j] = A[i][k] + A[k][j];
			}
	
	
}
