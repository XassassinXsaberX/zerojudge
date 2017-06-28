#include <stdio.h>
#include <stdlib.h>

/*這一題主要是在將bfs應用在搜尋問題上*/ 

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
		// 先利用動態分配記憶體來建構二維陣列 
		arr = (int**)malloc(sizeof(int*)*m);
		ptr = (int*)malloc(sizeof(int)*m*n);
		for(i=0;i<m;i++,ptr+=n)
			arr[i]=ptr;
			
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				scanf("%d",&arr[i][j]);
				
		//尋找第一列中，第幾行不為0
		start_y=0;
		for(start_x=0;start_x<n;start_x++)
		{
			if(arr[start_y][start_x]==1)
				break;
		} 
		
		//接下來進行bfs搜尋 
		bfs(m,n,start_y,start_x,arr,S);
		
		//最後將陣列中不為第一列，且為1的元素全部變為0
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
	//S變數決定bfs會不會往上搜尋 
	int queue_x[100],queue_y[100];
	int front=0,rear=0; //front代表queue前端，rear代表queue後端
	
	//現在加入一個元素到queue中
	rear += 1;
	queue_x[rear] = start_x;
	queue_y[rear] = start_y;
	
	while(1)
	{
		//若queue為空，就跳出bfs演算法 
		if(front == rear)
			break;
			
		//把queue最前端的一個元素拿出來判斷是否能繼續搜尋 
		front = (front+1)%100;
		//判斷是否能往左搜尋
		if(queue_x[front]-1 >= 0 && arr[queue_y[front]][queue_x[front]-1] == 1)
		{
			arr[queue_y[front]][queue_x[front]-1] = arr[queue_y[front]][queue_x[front]] + 1;
			//若能往左搜尋，就要加入此點到queue中
			rear = (rear+1)%100;
			queue_y[rear] = queue_y[front];
			queue_x[rear] = queue_x[front]-1;
		}
		
		//判斷是否能往右搜尋
		if(queue_x[front]+1 < n && arr[queue_y[front]][queue_x[front]+1] == 1)
		{
			arr[queue_y[front]][queue_x[front]+1] = arr[queue_y[front]][queue_x[front]] + 1;
			//若能往左搜尋，就要加入此點到queue中
			rear = (rear+1)%100;
			queue_y[rear] = queue_y[front];
			queue_x[rear] = queue_x[front]+1;
		}
		
		//判斷是否能往下搜尋
		if(queue_y[front]+1 < m && arr[queue_y[front]+1][queue_x[front]] == 1)
		{
			arr[queue_y[front]+1][queue_x[front]] = arr[queue_y[front]][queue_x[front]] + 1;
			//若能往左搜尋，就要加入此點到queue中
			rear = (rear+1)%100;
			queue_y[rear] = queue_y[front]+1;
			queue_x[rear] = queue_x[front];
		}
		
		if(S==1) //水可以往上流
		{
			//判斷是否能往下搜尋
			if(queue_y[front]-1 > 0 && arr[queue_y[front]-1][queue_x[front]] == 1 )
			{
				arr[queue_y[front]-1][queue_x[front]] = arr[queue_y[front]][queue_x[front]] + 1;
				//若能往左搜尋，就要加入此點到queue中
				rear = (rear+1)%100;
				queue_y[rear] = queue_y[front]-1;
				queue_x[rear] = queue_x[front];
			}
			
		} 
		
	}
	
}

































