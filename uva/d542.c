#include <stdio.h>
#include <stdlib.h>

/*
�Q��merge sort�D��bubble sort���洫���� 
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
	//��������� 
	merge_sort(arr,tmp,n/2,count);            //��Ĥ@��i��merge sort 
	merge_sort(arr+n/2,tmp+n/2,n-n/2,count);  //��ĤG��i��merge sort 
	
	//�A�ӦX�֥H�ƧǦn�����A�s��tmp�}�C�� 
	i = 0;
	j = n/2;
	k = 0;
	while(1)
	{
		if(i>=n/2 && j>=n)   //�p�G�Ĥ@��M�ĤG�諸�������w�g���tmp�}�C��
			break;           //�N���X�j��
		if(i<n/2 && j<n && arr[i]<=arr[j])           //�Y�Ĥ@��M�ĤG�諸�����٨S�������temp�}�C���A�B�ثe�Ĥ@�諸����arr[i]<=�ثe�ĤG�諸����arr[j]
			tmp[k++] = arr[i++];                     //�N�ثe�Ĥ@�諸�e���������tmp�}�C��
		else if(i<n/2 && j<n && arr[i] >= arr[j])    //�Y�Ĥ@��M�ĤG�諸�����٨S�������temp�}�C���A�B�ثe�ĤG�諸����arr[j]<=�ثe�Ĥ@�諸����arr[i]  
		{
			*count = *count + n/2 - i;               //���ɲĤG�諸�����|���� (n/2-i)�B 
			tmp[k++] = arr[j++];                     //�N�ثe�ĤG�諸�e���������temp�}�C�� 
		}
		else if(i>=n/2 && j<n)                       //�Y�ĤG�諸�����٨S�������temp�}�C���A���Ĥ@�諸�����w�������temp�}�C�� 
			tmp[k++] = arr[j++];                     //�N�ثe�ĤG�諸�e���������temp�}�C�� 
		else if(i<n/2 && j>=n)                       //�Y�Ĥ@�諸�����٨S�������temp�}�C���A���ĤG�諸�����w�������temp�}�C�� 
			tmp[k++] = arr[i++];                     //�N�ثe�Ĥ@�諸�e���������temp�}�C�� 
	} 
	
	//�N�ƧǦn��tmp�}�C�ƻs��arr�}�C��
	for(i=0;i<n;i++)
		arr[i] = tmp[i]; 
	
}
