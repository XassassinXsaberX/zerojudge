#include <stdio.h>
#include <stdlib.h>

/*
�m��merge sort
�q�p�ƨ�j 
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
	
	//�Y�}�C���u���@�Ӥ����A�h�����Ƨ� 
	if(n <= 1)
		return ;
	
	// ���q�����������A�����Ĥ@�ﰵmerge sort�A�A���ĤG�ﰵmerge sort 
	merge_sort(arr,temp,mid);
	merge_sort(arr+mid,temp+mid,n-mid);
	
	// �{�b *arr ~ *(arr+mid-1) �� *(arr+mid) ~ *(arr+n-1) �o�����O�O�H�ƧǦn�����
	// �ڭ̤��O�٨䬰�Ĥ@��βĤG�� 
	// �{�b�n�����O�N�o����ǥ�temp�}�C��z���@��@�ƧǦn���ƦC�s�btemp�� 
	i = 0,j = mid,k = 0;
	while(1)
	{
		for(;i<mid;i++)
		{
			if(arr[i]<=arr[j] || j>=n)  // �Y�Ĥ@�諸�Y�@�Ӥ���<=�ĤG��A�άO�ĤG�諸�����w�������temp�}�C�������p�� 
				temp[k++] = arr[i];	    // �h�N�Ĥ@�諸�Ӥ������temp�}�C��
			else
				break;
		}
		for(;j<n;j++)
		{
			if(arr[j]<=arr[i] || i>=mid) // �Y�ĤG�諸�Y�@�Ӥ���<=�Ĥ@��A�άO�Ĥ@�諸�����w�������temp�}�C�������p�� 
				temp[k++] = arr[j];      // �h�N�ĤG�諸�Ӥ������temp�}�C�� 
			else
				break;
		}
		if(k == n)                       // �Ytemp�}�C����Fn�Ӥ����A�N��Ĥ@��βĤG�諸�Ҧ����������temp�}�C���F 
			break;
				
	}
	
	//�{�btemp�}�C�����O�w�ƧǦn�������A�Ntemp�}�C���������ƻs��arr�}�C���a 
	for(i=0;i<n;i++)
		arr[i] = temp[i];
	
}
