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
		if(i>=mid && j>=n)  //�p�G�Ĥ@��M�ĤG�諸�������w�g���temp�}�C�� 
			break;          //�N���X�j�� 
		if(i<mid && j<n && arr[i]<=arr[j])       //�Y�Ĥ@��M�ĤG�諸�����٨S�������temp�}�C���A�B�ثe�Ĥ@�諸����arr[i]<=�ثe�ĤG�諸����arr[j] 
			temp[k++] = arr[i++];                //�N�ثe�Ĥ@�諸�e���������temp�}�C�� 
		else if(i<mid && j<n && arr[j]<=arr[i])  //�Y�Ĥ@��M�ĤG�諸�����٨S�������temp�}�C���A�B�ثe�ĤG�諸����arr[j]<=�ثe�Ĥ@�諸����arr[i]  
			temp[k++] = arr[j++];                //�N�ثe�ĤG�諸�e���������temp�}�C�� 
		else if(i<mid && j>=n)                   //�Y�Ĥ@�諸�����٨S�������temp�}�C���A���ĤG�諸�����w�������temp�}�C�� 
			temp[k++] = arr[i++];                //�N�ثe�Ĥ@�諸�e���������temp�}�C�� 
		else if(i>=mid && j<n)                   //�Y�ĤG�諸�����٨S�������temp�}�C���A���Ĥ@�諸�����w�������temp�}�C��  
			temp[k++] =arr[j++];                 //�N�ثe�ĤG�諸�e���������temp�}�C�� 
	}
	
	//�{�btemp�}�C�����O�w�ƧǦn�������A�Ntemp�}�C���������ƻs��arr�}�C���a 
	for(i=0;i<n;i++)
		arr[i] = temp[i];
	
}
