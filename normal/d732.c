#include <stdio.h>
#include <stdlib.h>

/*�m�߹�w�ƧǦn���ƦC�i�� binary search*/

int binary_search(int*arr,int value,int n);

int main()
{
	int n,k;
	int *arr;
	int i,j;
	int value;
	while(scanf("%d %d",&n,&k)!=EOF)
	{
		arr = (int*)malloc(sizeof(int)*n);
		
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);
		for(i=0;i<k;i++)
		{
			scanf("%d",&value);
			printf("%d\n",binary_search(arr,value,n));
		}	
				
		
		free(arr);
	
	}
	return 0;

}

int binary_search(int*arr,int value,int n)
{  //arr���w�q�p��j�ƧǦn���}�C
   //value���n�j�M����
   //n�N��}�C�@���h�֤��� 
	int i,j,k;
	int start=0,end=n; //���O�N��_�I�β��I 
	int mid;           //�N������m 
	
	while(1)
	{
		mid = (start + end) / 2;   // ����X������m 
		if(arr[mid] == value)      // �p�G�barr�}�C���j�M��value  
			return mid+1;          // �N�^�Ǩ��m 
			
		else if(arr[mid] < value)  // �p�Garr�}�C������ < value 
			start = mid+1;         // �令�j�M�}�C����b���� 
			
		else if(value < arr[mid])  // �p�Garr�}�C������ > value 
			end = mid;             // �令�j�M�}�C���e�b���� 
			
		if(start == end)           // �p�G�j�M������A�������� 
			return 0;	           // �h�^��0 
	}
	
}









