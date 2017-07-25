#include <stdio.h>
#include <stdlib.h>

/*
��adjacency matrix�갵�Ͻװ��D
�Q��dfs��bfs�Ө��X��ӹϧ� 
*/

void dfs(int N,char**matrix,int current,int B,int *find);
void bfs(int N,char**matrix,int A,int B,int *find);

typedef struct queue
{
	int front,rear;
	int arr[1000];
}Queue;

int main()
{
	char **matrix = (char**)malloc(sizeof(char*)*800);
	char *ptr = (char*)malloc(sizeof(char)*800*800);
	int i,j,k;
	int N,M;
	int A,B;
	Queue q;
	int find;
	for(i=0;i<800;i++,ptr+=800)
		matrix[i] = ptr;
	while(scanf("%d %d",&N,&M)!=EOF)
	{
		for(i=0;i<N;i++)
			for(j=0;j<N;j++)
				matrix[i][j] = 0;
		for(i=0;i<M;i++)
		{
			scanf("%d %d",&A,&B);
			matrix[A-1][B-1] = 1; //�N��A�����i�H��B���� 
		}
		scanf("%d %d",&A,&B);
		find = 0;
		bfs(N,matrix,A-1,B-1,&find);
		//��i��DFS
		//dfs(N,matrix,A-1,B-1,&find);
		if(find == 1)
			printf("Yes!!!\n");
		else
			printf("No!!!\n");
	}
	return 0;
	
}

void dfs(int N,char**matrix,int current,int B,int *find)
{
	//N�N���X�ӫ����Bmatrix�N��adjacency matrix
	//current�N��ثedfs����@�ӫ���
	//B�N����I
	//�Y�i�H�s�q��B�A�hfind=1 
	int i,j,k;
	int temp;
	if(*find == 0)
	{
		for(i=0;i<N;i++)
		{
			if(matrix[current][i] == 1) //�Y�i�H�qcurrent��������i���� 
			{
				if(i == B)
				{
					*find = 1;
					break;
				}
				matrix[current][i] = 2; //�N��Ӹ��|���L�F
				dfs(N,matrix,i,B,find);
			} 
		}
	}
}


void bfs(int N,char**matrix,int A,int B,int *find)
{
	//N�N���X�ӫ����Bmatrix�N��adjacency matrix
	//A�N��_�I�BB�N����I
	//�Y�i�H�s�q��B�A�hfind=1
	Queue q;
	int i,j,k;
	q.front = -1;
	q.rear = -1;
	q.arr[++q.rear] = A;
	
	while(1)
	{
		if(q.front == q.rear)
			break;
		q.front = (q.front+1)%1000;
		for(i=0;i<N;i++)
		{
			if(matrix[q.arr[q.front]][i] == 1) //�p�Gq.arr[q.front]�����i�H�s�q��i����
			{
				if(i == B)
				{
					*find = 1;
					break; 
				} 
				matrix[q.arr[q.front]][i] = 2;//�N��Ӹ��|�w�g���L�F
				q.arr[++q.rear] = i; 
			}	
		}
		if(*find == 1)
			break; 
	}
	
	
	
}









