#include <stdio.h>
#include <stdlib.h>

/*
利用merge sort求解bubble sort的交換次數 
*/

void merge_sort(int*arr,int*tmp,int n,long long int*count);

int main()
{
	int n;
	int *arr,*tmp;
	int i,j,k;
	long long int count;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break; 
		arr = (int*)malloc(sizeof(int)*n);
		tmp = (int*)malloc(sizeof(int)*n);
		
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);
		count = 0;
		merge_sort(arr,tmp,n,&count);
	
		printf("%lld\n",count);
		
		
		free(arr);
		free(tmp);
	}
	return 0;
}

void merge_sort(int*arr,int*tmp,int n,long long int*count)
{
	int i,j,k;
	int mid=n/2;
	if(n<=1)
		return ;
	//先分成兩堆 
	merge_sort(arr,tmp,n/2,count);            //對第一堆進行merge sort 
	merge_sort(arr+n/2,tmp+n/2,n-n/2,count);  //對第二堆進行merge sort 
	
	//再來合併以排序好的兩堆，存到tmp陣列中 
	i = 0;
	j = n/2;
	k = 0;
	while(1)
	{
		if(i>=n/2 && j>=n)   //如果第一堆和第二堆的元素都已經丟到tmp陣列中
			break;           //就跳出迴圈
		if(i<n/2 && j<n && arr[i]<=arr[j])           //若第一堆和第二堆的元素還沒全部丟到temp陣列中，且目前第一堆的元素arr[i]<=目前第二堆的元素arr[j]
			tmp[k++] = arr[i++];                     //將目前第一堆的前面元素丟到tmp陣列中
		else if(i<n/2 && j<n && arr[i] >= arr[j])    //若第一堆和第二堆的元素還沒全部丟到temp陣列中，且目前第二堆的元素arr[j]<=目前第一堆的元素arr[i]  
		{
			*count = *count + n/2 - i;               //此時第二堆的元素會移動 (n/2-i)步 
			tmp[k++] = arr[j++];                     //將目前第二堆的前面元素丟到temp陣列中 
		}
		else if(i>=n/2 && j<n)                       //若第二堆的元素還沒全部丟到temp陣列中，但第一堆的元素已全部丟到temp陣列中 
			tmp[k++] = arr[j++];                     //將目前第二堆的前面元素丟到temp陣列中 
		else if(i<n/2 && j>=n)                       //若第一堆的元素還沒全部丟到temp陣列中，但第二堆的元素已全部丟到temp陣列中 
			tmp[k++] = arr[i++];                     //將目前第一堆的前面元素丟到temp陣列中 
	} 
	
	//將排序好的tmp陣列複製到arr陣列中
	for(i=0;i<n;i++)
		arr[i] = tmp[i]; 
	
}
