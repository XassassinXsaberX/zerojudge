#include <stdio.h>
#include <stdlib.h>

/*�o�@�D�D�n�O�b�Nbfs���Φb�j�M���D�W*/ 

void bfs(int m,int n,int start_y,int start_x,int**arr,int S);

int main()
{
	int S;
	int i,j,k;
	int m,n;
	int **arr;
	int *ptr;
	int start_x,start_y; 
	int c=1;
	while(scanf("%d",&S)!=EOF)
	{
		scanf("%d %d",&m,&n);
		// ���Q�ΰʺA���t�O����ӫغc�G���}�C 
		arr = (int**)malloc(sizeof(int*)*m);
		ptr = (int*)malloc(sizeof(int)*m*n);
		for(i=0;i<m;i++,ptr+=n)
			arr[i]=ptr;
			
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				scanf("%d",&arr[i][j]);
				
		//�M��Ĥ@�C���A�ĴX�椣��0
		start_y=0;
		for(start_x=0;start_x<n;start_x++)
		{
			if(arr[start_y][start_x]==1)
				break;
		} 
		
		//���U�Ӷi��bfs�j�M 
		bfs(m,n,start_y,start_x,arr,S);
		
		//�̫�N�}�C�������Ĥ@�C�A�B��1�����������ܬ�0
		for(i=1;i<m;i++)
			for(j=0;j<n;j++)
				if(arr[i][j]==1) 
					arr[i][j]=0;
		
		printf("Case %d:\n",c++);
		for(i=0;i<m;i++) 
		{
			for(j=0;j<n;j++)
				printf("%d ",arr[i][j]);
			printf("\n");
		}
		
		free(arr[0]);
		free(arr);
	}
	
}


void bfs(int m,int n,int start_y,int start_x,int**arr,int S)
{
	//S�ܼƨM�wbfs�|���|���W�j�M 
	int queue_x[100],queue_y[100];
	int front=0,rear=0; //front�N��queue�e�ݡArear�N��queue���
	
	//�{�b�[�J�@�Ӥ�����queue��
	rear += 1;
	queue_x[rear] = start_x;
	queue_y[rear] = start_y;
	
	while(1)
	{
		//�Yqueue���šA�N���Xbfs�t��k 
		if(front == rear)
			break;
			
		//��queue�̫e�ݪ��@�Ӥ������X�ӧP�_�O�_���~��j�M 
		front = (front+1)%100;
		//�P�_�O�_�੹���j�M
		if(queue_x[front]-1 >= 0 && arr[queue_y[front]][queue_x[front]-1] == 1)
		{
			arr[queue_y[front]][queue_x[front]-1] = arr[queue_y[front]][queue_x[front]] + 1;
			//�Y�੹���j�M�A�N�n�[�J���I��queue��
			rear = (rear+1)%100;
			queue_y[rear] = queue_y[front];
			queue_x[rear] = queue_x[front]-1;
		}
		
		//�P�_�O�_�੹�k�j�M
		if(queue_x[front]+1 < n && arr[queue_y[front]][queue_x[front]+1] == 1)
		{
			arr[queue_y[front]][queue_x[front]+1] = arr[queue_y[front]][queue_x[front]] + 1;
			//�Y�੹���j�M�A�N�n�[�J���I��queue��
			rear = (rear+1)%100;
			queue_y[rear] = queue_y[front];
			queue_x[rear] = queue_x[front]+1;
		}
		
		//�P�_�O�_�੹�U�j�M
		if(queue_y[front]+1 < m && arr[queue_y[front]+1][queue_x[front]] == 1)
		{
			arr[queue_y[front]+1][queue_x[front]] = arr[queue_y[front]][queue_x[front]] + 1;
			//�Y�੹���j�M�A�N�n�[�J���I��queue��
			rear = (rear+1)%100;
			queue_y[rear] = queue_y[front]+1;
			queue_x[rear] = queue_x[front];
		}
		
		if(S==1) //���i�H���W�y
		{
			//�P�_�O�_�੹�U�j�M
			if(queue_y[front]-1 > 0 && arr[queue_y[front]-1][queue_x[front]] == 1 )
			{
				arr[queue_y[front]-1][queue_x[front]] = arr[queue_y[front]][queue_x[front]] + 1;
				//�Y�੹���j�M�A�N�n�[�J���I��queue��
				rear = (rear+1)%100;
				queue_y[rear] = queue_y[front]-1;
				queue_x[rear] = queue_x[front];
			}
			
		} 
		
	}
	
}

































