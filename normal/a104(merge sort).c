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
		if(i>=mid && j>=n)  //如果第一堆和第二堆的元素都已經丟到temp陣列中 
			break;          //就跳出迴圈 
		if(i<mid && j<n && arr[i]<=arr[j])       //若第一堆和第二堆的元素還沒全部丟到temp陣列中，且目前第一堆的元素arr[i]<=目前第二堆的元素arr[j] 
			temp[k++] = arr[i++];                //將目前第一堆的前面元素丟到temp陣列中 
		else if(i<mid && j<n && arr[j]<=arr[i])  //若第一堆和第二堆的元素還沒全部丟到temp陣列中，且目前第二堆的元素arr[j]<=目前第一堆的元素arr[i]  
			temp[k++] = arr[j++];                //將目前第二堆的前面元素丟到temp陣列中 
		else if(i<mid && j>=n)                   //若第一堆的元素還沒全部丟到temp陣列中，但第二堆的元素已全部丟到temp陣列中 
			temp[k++] = arr[i++];                //將目前第一堆的前面元素丟到temp陣列中 
		else if(i>=mid && j<n)                   //若第二堆的元素還沒全部丟到temp陣列中，但第一堆的元素已全部丟到temp陣列中  
			temp[k++] =arr[j++];                 //將目前第二堆的前面元素丟到temp陣列中 
	}
	
	//現在temp陣列中都是已排序好的元素，將temp陣列中的元素複製到arr陣列中吧 
	for(i=0;i<n;i++)
		arr[i] = temp[i];
	
}
