#include <stdio.h>
#include <stdlib.h>

/*
練習merge sort
從小排到大 
*/ 

void merge_sort(int*arr,int*temp,int n);

int main()
{
	int n;
	int *arr,*temp;
	int i,j,k;
	int flag;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		arr = (int*)malloc(sizeof(int)*n);
		temp = (int*)malloc(sizeof(int)*n);
		
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);

		merge_sort(arr,temp,n);
		
		for(i=0;i<n;i++)
			printf("%d ",arr[i]);
		printf("\n");
		 
		free(arr);
		free(temp);
	} 
	return 0; 
}

void merge_sort(int*arr,int *temp,int n)
{
	int mid = n/2;
	int i,j,k;
	
	//若陣列中只有一個元素，則不做排序 
	if(n <= 1)
		return ;
	
	// 先從中間分成兩堆，並讓第一堆做merge sort，再讓第二堆做merge sort 
	merge_sort(arr,temp,mid);
	merge_sort(arr+mid,temp+mid,n-mid);
	
	// 現在 *arr ~ *(arr+mid-1) 及 *(arr+mid) ~ *(arr+n-1) 這兩堆分別是以排序好的兩堆
	// 我們分別稱其為第一堆及第二堆 
	// 現在要做的是將這兩堆藉由temp陣列整理成一堆一排序好的數列存在temp中 
	i = 0,j = mid,k = 0;
	while(1)
	{
		for(;i<mid;i++)
		{
			if(arr[i]<=arr[j] || j>=n)  // 若第一堆的某一個元素<=第二堆，或是第二堆的元素已全部丟到temp陣列中的情況時 
				temp[k++] = arr[i];	    // 則將第一堆的該元素丟到temp陣列中
			else
				break;
		}
		for(;j<n;j++)
		{
			if(arr[j]<=arr[i] || i>=mid) // 若第二堆的某一個元素<=第一堆，或是第一堆的元素已全部丟到temp陣列中的情況時 
				temp[k++] = arr[j];      // 則將第二堆的該元素丟到temp陣列中 
			else
				break;
		}
		if(k == n)                       // 若temp陣列收到了n個元素，代表第一堆及第二堆的所有元素都丟到temp陣列中了 
			break;
				
	}
	
	//現在temp陣列中都是已排序好的元素，將temp陣列中的元素複製到arr陣列中吧 
	for(i=0;i<n;i++)
		arr[i] = temp[i];
	
}
