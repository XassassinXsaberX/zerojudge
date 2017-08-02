#include <stdio.h>
#include <stdlib.h>
#define INFINITE 100000000 

/*
Floyd - Warshall �t��k���ܤƫ� 
�o��shortest path�x�}�s�񪺤��O��¨�`�I���̵u�Z��
�ӬO��`�I���|���A�������|��(�̤p��(�̤jweight))
ex
���]��4�Ӹ`�I�A�M�H�U4���� 
�`�I1  -->  �`�I2  ��weight = 10
�`�I2  -->  �`�I3  ��weight = 15
�`�I1  -->  �`�I4  ��weight = 5
�`�I4  -->  �`�I3  ��weight = 3 

�ҥH �`�I1  -->  �`�I2  -->  �`�I3  ���̤jweight = 15 
     �`�I1  -->  �`�I4  -->  �`�I3  ���̤jweight = 5  

�G�`�I1 �� �`�I3 ���|����(�̤p��(�̤jweight)) = 5
*/     



void floyd(int adj_matrix[100][100],int shortest[100][100],int n);

int main()
{
	int adj_matrix[100][100];
	int shortest[100][100];    //�s��U�`�I���̵u���|
	int C,S,Q;
	int start,end,noise;
	int i,j,k;
	int c=1;
	while(scanf("%d %d %d",&C,&S,&Q)!=EOF) //��C�Ӹ`�I�BS����BQ�Ӹ߰� 
	{
		if(C==0 && S==0 && Q==0)
			break;
		
		//����l��adjacency matrix 
		for(i=0;i<C;i++)
			for(j=0;j<C;j++)
			{
				if(i==j)
					adj_matrix[i][j] = 0;
				else
					adj_matrix[i][j] = INFINITE; 
			} 
		//���U�ӭn�إ�adjacency matrix
		for(i=0;i<S;i++)
		{
			scanf("%d %d %d",&start,&end,&noise);
			adj_matrix[start-1][end-1] = noise;
			adj_matrix[end-1][start-1] = noise; 
		} 
		
		//�ϥ�floyd-warshall �̵u���|�t��k 
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
	//�ϥ�floyd-warshall �̵u���|�t��k�ɡA�n���]�w�̵u���|�x�}�Padjacency matrix�ۦP 
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			shortest[i][j] = adj_matrix[i][j];
			
	//���U�Ӷ}�l��`�Ii��`�Ij��(�̤p��(�̤jweight))
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				//����X�`�Ii��`�IK����(�̤p��(�̤jweight))shortest[i][k]�A�θ`�Ik��`�Ij��(�̤p��(�̤jweight))shortest[k][j]�A��Ƴ̤j�Ȭ��� 
				if(shortest[i][k] > shortest[k][j])
					max = shortest[i][k];
				else
					max = shortest[k][j];
				if(max < shortest[i][j])      //�Ymax�|��`�Ii��`�Ij��(�̤p��(�̤jweight))�u���� 
						shortest[i][j] = max; //�h��s�`�Ii��`�Ij��(�̤p��(�̤jweight))
			
			}
				
	
	
}



