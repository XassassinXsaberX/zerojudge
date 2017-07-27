#include <stdio.h>
#include <stdlib.h>

/*
�갵insertion sort (���J�Ƨ�)
�q�p�ƨ�j 
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
		next = arr[i];  //�̷s��ܭn���J���I 
		//�H�U�}�l�M��n�i�洡�J����m 
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




