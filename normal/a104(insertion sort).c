#include <stdio.h>
#include <stdlib.h>

/*
實做insertion sort (插入排序)
從小排到大 
*/

void insertion_sort(int n,int arr[1000]);

int main()
{
	int n;
	int arr[1000];
	int i,j;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);
		
		insertion_sort(n,arr);
		
		for(i=0;i<n;i++)
			printf("%d ",arr[i]);
		printf("\n");
		
	}
	return 0;
}

void insertion_sort(int n,int arr[1000])
{
	int i,j,k;
	int next;
	for(i=1;i<n;i++)
	{
		next = arr[i];  //最新選擇要插入的點 
		//以下開始尋找要進行插入的位置 
		for(j=i-1;j>=0;j--)
		{
			if(arr[j] > next) 
				arr[j+1] = arr[j];
			else
				break;	
		}
		arr[j+1] = next;
	}
	
}




