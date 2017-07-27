#include <stdio.h>
#include <stdlib.h>

/*
�m�߹Ͻת����N�Ƨ�(topology sort)
*/

void topology_sort(int n,int result[100],int adj_matrix[100][100],int in_degree[100]);

int main()
{
	int n,m;
	int adj_matrix[100][100];
	int in_degree[100];  //�O���C�Ӻ��I��in-degree�� 
	int result[100];     //�������N�ƧǪ����G 
	int i,j,k;
	int s,e;
	
	while(scanf("%d %d",&n,&m)!=EOF)//n�Ӻ��I�Am���� 
	{
		//����l��adjacency matrix 
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				adj_matrix[i][j] = 0;
		//��l��in_degree array
		for(i=0;i<n;i++)
			in_degree[i] = 0; 
		
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&s,&e);
			adj_matrix[s][e] = 1;  //���Is�i�H����Ie 
			in_degree[e]++;        //���Ie��in-degree�ȥ[1 
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
	// �`�@��n�����I 
	// result���Ƨǵ��G
	// in_degree�O���C�Ӻ��I��in-degree value 
	int count=0;
	int i,j,k;
	count = 0;
	while(1)
	{
		//�����Ӧr�嶶�ǧ�Xin-degree��0�����I
		for(i=0;i<n;i++)
		{
			if(in_degree[i] == 0) //�Y���Ii��in-degree = 0 
			{
				in_degree[i] = -1;   //�N��Ӻ��I���|�A�Q�j�M 
				result[count++] = i; //�����ݾ�ƧǪ����G 
				
				if(count == n)       //�p�G�w�������N�ƧǡA�N���X�禡 
					return ;
				
				// �N���Ii��immediate sucessor(�ߨ���~��)��in-degree��1 
				// �{�b�n��X���Ii�� immediate sucessor
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
