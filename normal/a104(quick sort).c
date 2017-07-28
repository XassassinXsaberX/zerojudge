#include <stdio.h>
#include <stdlib.h>

/*
絤策quick sort
眖逼 
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
 
//膀非程オよе硉逼 
void quick_sort(int*arr,int left,int right)
{
	int i,j,k;
	int pivot_index = left;
	int pivot;
	i = left;
	j = right;
	

	pivot_index = left; //膀非竚 
	pivot = arr[pivot_index]; //膀非 
	
	//璝璶逼计ヘ<=1碞ぃ暗逼
	if(right - left <= 0)
		return ;
		
	// 安砞じ琌璶眖逼 
	// 玥е硉逼膀セ弘碞琌∕﹚膀非pivot
	// 璶―よ璶膀非オよ璶膀非  
	while(1)
	{
		while(1)  //眖程オよ秨﹍┕碝тゑpivotじ  (ヘ琌絋玂よ常膀非)
		{
			if(arr[i]>pivot || i>j)
				break;
			i++;
		}
		while(1)  //眖程よ秨﹍┕オ碝тゑpivotじ  (ヘ琌絋玂オよ常膀非) 
		{
			if(arr[j]<pivot || i>j)
				break;
			j--;	
		}
		if(i<j)  //璝i<jarr[i] > arr[j] (オよよ)璶秈︽じユ传絋玂オよよ 
			swap(&arr[i],&arr[j]);
		else if(i>j) //苯磞挡 
		{
			swap(&arr[j],&arr[pivot_index]);
			//瞷pivotオよじ常ゑpivot
			//pivotよじ常ゑpivot 
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



 


