#include <stdio.h>
#include <stdlib.h>

/*�m��qsort�Ƨ�+���j�����D*/ 

int cmp(const void*,const void*);
void recursion(int current,int count,int n,int m,int*arr,int*ans);

int main()
{
	int n,m;
	int*arr;
	int*ans;
	int i,j,k;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		arr = (int*)malloc(sizeof(int)*n);
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);
		scanf("%d",&m);
		ans = (int*)malloc(sizeof(int)*m);
		
		qsort(arr,n,sizeof(int),cmp);//��arr�}�C�i��ֳt�Ƨ� (�q�p�ƨ�j)
		
		recursion(0,0,n,m,arr,ans);
			
		
		free(arr);
		free(ans);
	}
	return 0;
}

int cmp(const void*a,const void*b)
{
	int*a1 = (int*)a;
	int*b1 = (int*)b;
	if(*a1<*b1)
		return -1;
	else if(*a1==*b1)
		return 0;
	else
		return 1;
}

void recursion(int current,int count,int n,int m,int*arr,int*ans)
{
	//current�����ثe���j��arr�����Ӧ�m
	//count�����ثeans������X�Ӥ���
	//arr�}�C��n�Ӥ���
	//ans�}�C�ݭn����m�Ӥ��� 
	int i,j,k;
	
	if(current == n && count < m )
	//�p�G�ثe�w�W�Larr�}�C���d�� 
		return ;//�N���X���j 
	
	//�p�G�ثe�����쪺�����w�g��m�� 
	if(count == m)
	{
		for(i=0;i<m;i++)
			printf("%d ",ans[i]);
		printf("\n");
	}
	//�_�h�N�~�򻼰j 
	else
	{
		for(i=current;i<n-(m-count-1);i++)
		{
			ans[count] = arr[i];
			recursion(i+1,count+1,n,m,arr,ans);
		}
	}
	
	
}









