#include <stdio.h>
#include <stdlib.h>

/*
�m��quick sort
�q�p�ƨ�j 
*/
void quick_sort(int*arr,int left,int right);
void swap(int*,int*);


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

		quick_sort(arr,0,n-1);
		
		for(i=0;i<n;i++)
			printf("%d ",arr[i]);
		printf("\n"); 
		free(arr);
		 
	} 
	return 0; 
}
 
//��ǭȦb�̥��誺�ֳt�Ƨ� 
void quick_sort(int*arr,int left,int right)
{
	int i,j,k;
	int pivot_index = left;
	int pivot;
	i = left;
	j = right;
	

	pivot_index = left; //��ǭȪ���m 
	pivot = arr[pivot_index]; //��ǭ� 
	
	//�Y�n�ƧǪ��ƥ�<=1�A�N�����Ƨ�
	if(right - left <= 0)
		return ;
		
	// ���]�����O�n�q�p�ƨ�j 
	// �h�ֳt�ƧǪ��򥻺믫�N�O���M�w��ǭ�pivot
	// �A�n�D�k�誺�ȭn�p���ǭȡA���誺�ȭn�j���ǭ�  
	while(1)
	{
		while(1)  //�q�̥���}�l���k�M���pivot�j������  (�ت��O�T�O�k�誺�ȳ��p���ǭ�)
		{
			if(arr[i]>pivot || i>j)
				break;
			i++;
		}
		while(1)  //�q�̥k��}�l�����M���pivot�p������  (�ت��O�T�O���誺�ȳ��j���ǭ�) 
		{
			if(arr[j]<pivot || i>j)
				break;
			j--;	
		}
		if(i<j)  //�Yi<j�A�N��arr[i] > arr[j] (���誺�Ȥj��k��)�A�n�i�椸���洫�A�T�O���誺�Ȥj��k�� 
			swap(&arr[i],&arr[j]);
		else if(i>j) //���y���� 
		{
			swap(&arr[j],&arr[pivot_index]);
			//�{�bpivot���誺��������pivot�p
			//pivot�k�誺��������pivot�j 
			break;
		}
		 
	}
	quick_sort(arr,left,j-1);
	quick_sort(arr,j+1,right);
}



void swap(int*a,int*b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}



 


