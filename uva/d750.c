#include <stdio.h>
#include <stdlib.h>

int cmp(const void*,const void*);
int M;

int main()
{
	int arr[10000];
	int N;
	int i,j;
	while(scanf("%d %d",&N,&M)!=EOF)
	{
		printf("%d %d\n",N,M);
		if(N==0 && M==0)
			break;
		for(i=0;i<N;i++)
			scanf("%d",&arr[i]);
			
		qsort(arr,N,sizeof(int),cmp);
		
		for(i=0;i<N;i++)
			printf("%d\n",arr[i]);
	}
	return 0;
}

//�w�q�ƧǨ�� 
int cmp(const void*a,const void*b)
{
	int*a1 = (int*)a;
	int*b1 = (int*)b;
	if((*a1)%M < (*b1)%M)       // �p�G*a1���HM���l�� < *b1���HM���l�ơA�h*a1��e�� 
		return -1;
	else if((*a1)%M > (*b1)%M)  // �p�G*a1���HM���l�� < *b1���HM���l�ơA�h*b1��e�� 
		return 1;
	else                        // �p�G*a1���HM���l�� == *b1���HM���l��
	{
		if((*a1)%2 == 1 && (*b1)%2 == 0)   // �Y*a1���_�ơA*b1�����ƮɡA*a1��e�� 
			return -1;
		else if((*a1)%2==0 && (*b1)%2==1)  // �Y*a1�����ơA*b1���_�ƮɡA*b1��e�� 
			return 1;
		else if((*a1)%2==1 && (*b1)%2==1)  // �Y*a1�B*b1�Ҭ��_�Ʈ� 
		{
			if(*a1 > *b1)                  // �h�j���Ʀr��e�� 
				return -1;
			else if(*a1 == *b1)
				return 0;
			else
				return 1;
		}
		else if((*a1)%2==0 && (*b1)%2==0)  // �Y*a1�B*b1�Ҭ����Ʈ�  
		{
			if(*a1 < *b1)			       // �h�p���Ʀr��e�� 
				return -1;
			else if(*a1 == *b1)
				return 0;
			else
				return 1;
		}
	}
	
	
}
