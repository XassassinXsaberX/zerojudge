#include <stdio.h>
#include <stdlib.h>

/*練習bubble sort*/
// 從小排到大 

void bubble_sort(int n,int arr[1000]);

int main()
{
	int n;
	int arr[1000];
	int i,j,k;
	int temp; 
	int flag;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);

		bubble_sort(n,arr);
		
		for(i=0;i<n;i++)
			printf("%d ",arr[i]);
		printf("\n"); 
		 
	} 
	return 0; 
}

void bubble_sort(int n,int arr[1000])
{
	int i,j,k,flag;
	int temp;
	for(i=n-1;i>=0;i--)
	{
		flag = 0;  // flag用來紀錄有無交換發生，沒有的話，代表排序完成 
		for(j=0;j<i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				flag = 1;
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;	
			}
		}
		if(flag = 0)
			break;
	
	}
		
}
