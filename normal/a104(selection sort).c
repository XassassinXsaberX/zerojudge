#include <stdio.h>
#include <stdlib.h>

void selection_sort(int n,int arr[1000]);

int main()
{
	int n;
	int arr[1000];
	int i,j,k;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);
	
		selection_sort(n,arr);
		
		for(i=0;i<n;i++)
			printf("%d ",arr[i]);
		printf("\n");
			
	}
	return 0;
}

void selection_sort(int n,int arr[1000])
{
	int i,j,k;
	int min_index;
	int temp;
	for(i=0;i<n;i++)
	{
		min_index = i;
		for(j=i+1;j<n;j++)
		{
			if(arr[min_index] > arr[j])
				min_index = j;
		}
		//�̫��X�qarr[i] ~ arr[n-1]���A�̤p�Ȭ�arr[min_index]
		//�ҥHarr[min_index]�Marr[i]�洫
	
		temp = arr[i];
		arr[i] = arr[min_index];
		arr[min_index] = temp;
		
	}
		
}
