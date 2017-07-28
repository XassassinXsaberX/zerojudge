#include <stdio.h>
#include <stdlib.h>

/*
�m��heap sort
�q�p�ƨ�j 
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
	
	//���إ�max heap tree 
	construct_heap(arr,max_heap,n);
	
	for(i=n-1;i>=0;i--)
		arr[i] = pop_heap(max_heap,i+1); //�qmax heap tree�����_�u�X�̤j�� 

	
}

//�إ̤߳j��n�� 
//max heap tree�������O�@���G����A�䤤���`�I���ȥ��j���l�`�I 
void construct_heap(int*arr,int*heap,int n)
{
	int i,j,k;
	int parent_index;
	int max;
	for(i=0;i<n;i++)
	{
		//���b��n�𪺳̩��ݥ[�J�s���� 
		heap[i] = arr[i];
		
		//���U�ӭn�q�̩��h�}�l�վ�max heap tree 
		j=i; 
		while(1) 
		{
			if(j==0) //�Y�ثe�`�I�N�Oroot�h�S�����n�վ�heap tree 
				break;	
			
			parent_index = (j-1)/2;  // parent_index�����ثe�`�I�����`�Iindex 
			if(heap[parent_index] >= heap[j]) // �Y���`�I����>=�ثe�`�I�A�h�ŦXmax heap tree 
				break;						  // �ҥH���Φb�վ�`�I�F 
			else 
			{
				// �Y���`�I����<�ثe�`�I�A�h���ŦXmax heap tree 
				swap(heap+parent_index, heap+j);  //���F�n�վ�`�I�~�A�٭n�~�򩹤��`�I����V���ʡA�ݬO�_�n�A�վ�W�h�`�I 
				j = parent_index;
			}
		} 
	}	
} 


//�q�̤j��n�𤤡A�u�X�̤j��(�R���̤j��n��root) 
int pop_heap(int*heap,int n)
{
	int ans;
	int i,j,k;
	int max_child_index; //�ΨӬ����l��index 
	
	ans = heap[0];//ans �Y��heap tree���̤j�� 
	
	//�u�Xmax heap tree��root��A�Nheap tree���̫�@���I�ɨӷ�root 
	heap[0] = heap[n-1];
	
	n = n - 1;//heap tree�������ƥ�-1 
	
	//���U�ӭn�qroot�ȶ}�l���U�վ�max heap tree
	i = 0; 
	while(1)
	{
		if(i*2+1+1 <= n && i*2+2+1 <= n) //�Y�ثe�`�I�����B�k�l�𳣦s�b
		{
			//��X���Ӥl�𪺭ȳ̤j�A�ðO����index 
			if(heap[i*2+1] > heap[i*2+2])
				max_child_index = i*2+1;
			else
				max_child_index = i*2+2;
		} 
		else if(i*2+1+1 <= n && i*2+2+1 > n)   //�Y�ثe�`�I�u�����l��
			max_child_index = i*2+1;
		else                                   //�Y�ثe�`�I�S���l��A�N�����h�X 
			break;
		
		if(heap[i] < heap[max_child_index])    //�Y�ثe���`�I���Ȥ��l�𪺭��٤p�A�N�n�i��վ� 
		{
			swap(heap+i, heap+max_child_index);
			i = max_child_index;
		} 
		else                                    //�Y�ثe���`�I�Ȥ��l�𪺸`�I�Ȥj�A�N��ŦXmax heap tree���ΦA�վ� 
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



 


