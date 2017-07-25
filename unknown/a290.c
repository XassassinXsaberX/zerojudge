#include <stdio.h>
#include <stdlib.h>

/*
用adjacency matrix實做圖論問題
利用dfs或bfs來走訪整個圖形 
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
			matrix[A-1][B-1] = 1; //代表A城市可以到B城市 
		}
		scanf("%d %d",&A,&B);
		find = 0;
		bfs(N,matrix,A-1,B-1,&find);
		//亦可用DFS
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
	//N代表有幾個城市、matrix代表adjacency matrix
	//current代表目前dfs到哪一個城市
	//B代表終點
	//若可以連通到B，則find=1 
	int i,j,k;
	int temp;
	if(*find == 0)
	{
		for(i=0;i<N;i++)
		{
			if(matrix[current][i] == 1) //若可以從current城市走到i城市 
			{
				if(i == B)
				{
					*find = 1;
					break;
				}
				matrix[current][i] = 2; //代表該路徑走過了
				dfs(N,matrix,i,B,find);
			} 
		}
	}
}


void bfs(int N,char**matrix,int A,int B,int *find)
{
	//N代表有幾個城市、matrix代表adjacency matrix
	//A代表起點、B代表終點
	//若可以連通到B，則find=1
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
			if(matrix[q.arr[q.front]][i] == 1) //如果q.arr[q.front]城市可以連通到i城市
			{
				if(i == B)
				{
					*find = 1;
					break; 
				} 
				matrix[q.arr[q.front]][i] = 2;//代表該路徑已經走過了
				q.arr[++q.rear] = i; 
			}	
		}
		if(*find == 1)
			break; 
	}
	
	
	
}









