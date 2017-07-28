#include <stdio.h>
#include <stdlib.h>

/*
練習heap sort
從小排到大 
*/
void heap_sort(int*arr,int n);
void swap(int*,int*);
void construct_heap(int*,int*,int);
int pop_heap(int*heap,int n);


int main()
{
	int n;
	int *arr;
	int i,j,k;
	int temp; 
	int flag;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		arr = (int*)malloc(sizeof(int)*n);
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);

		heap_sort(arr,n);
		
		for(i=0;i<n;i++)
			printf("%d ",arr[i]);
		printf("\n"); 
		free(arr);
		 
	} 
	return 0; 
}
 
 
void heap_sort(int*arr,int n)
{
	int i,j,k;
	int max_heap[n];
	
	//先建立max heap tree 
	construct_heap(arr,max_heap,n);
	
	for(i=n-1;i>=0;i--)
		arr[i] = pop_heap(max_heap,i+1); //從max heap tree中不斷彈出最大值 

	
}

//建立最大堆積樹 
//max heap tree的概念是一顆二元樹，其中父節點的值必大於其子節點 
void construct_heap(int*arr,int*heap,int n)
{
	int i,j,k;
	int parent_index;
	int max;
	for(i=0;i<n;i++)
	{
		//先在堆積樹的最底端加入新元素 
		heap[i] = arr[i];
		
		//接下來要從最底層開始調整max heap tree 
		j=i; 
		while(1) 
		{
			if(j==0) //若目前節點就是root則沒有必要調整heap tree 
				break;	
			
			parent_index = (j-1)/2;  // parent_index紀錄目前節點的父節點index 
			if(heap[parent_index] >= heap[j]) // 若父節點的值>=目前節點，則符合max heap tree 
				break;						  // 所以不用在調整節點了 
			else 
			{
				// 若父節點的值<目前節點，則不符合max heap tree 
				swap(heap+parent_index, heap+j);  //除了要調整節點外，還要繼續往父節點的方向移動，看是否要再調整上層節點 
				j = parent_index;
			}
		} 
	}	
} 


//從最大堆積樹中，彈出最大值(刪除最大堆積樹的root) 
int pop_heap(int*heap,int n)
{
	int ans;
	int i,j,k;
	int max_child_index; //用來紀錄子樹的index 
	
	ans = heap[0];//ans 即為heap tree的最大值 
	
	//彈出max heap tree的root後，將heap tree的最後一個點補來當root 
	heap[0] = heap[n-1];
	
	n = n - 1;//heap tree的元素數目-1 
	
	//接下來要從root值開始往下調整max heap tree
	i = 0; 
	while(1)
	{
		if(i*2+1+1 <= n && i*2+2+1 <= n) //若目前節點的左、右子樹都存在
		{
			//找出哪個子樹的值最大，並記錄其index 
			if(heap[i*2+1] > heap[i*2+2])
				max_child_index = i*2+1;
			else
				max_child_index = i*2+2;
		} 
		else if(i*2+1+1 <= n && i*2+2+1 > n)   //若目前節點只有左子樹
			max_child_index = i*2+1;
		else                                   //若目前節點沒有子樹，就直接退出 
			break;
		
		if(heap[i] < heap[max_child_index])    //若目前的節點的值比其子樹的值還小，就要進行調整 
		{
			swap(heap+i, heap+max_child_index);
			i = max_child_index;
		} 
		else                                    //若目前的節點值比其子樹的節點值大，代表符合max heap tree不用再調整 
			break;
	
	} 
	return ans;
	
		
}

void swap(int*a,int*b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}



 


