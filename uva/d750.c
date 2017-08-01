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

//﹚竡逼ㄧ计 
int cmp(const void*a,const void*b)
{
	int*a1 = (int*)a;
	int*b1 = (int*)b;
	if((*a1)%M < (*b1)%M)       // 狦*a1埃M緇计 < *b1埃M緇计玥*a1玡 
		return -1;
	else if((*a1)%M > (*b1)%M)  // 狦*a1埃M緇计 < *b1埃M緇计玥*b1玡 
		return 1;
	else                        // 狦*a1埃M緇计 == *b1埃M緇计
	{
		if((*a1)%2 == 1 && (*b1)%2 == 0)   // 璝*a1计*b1案计*a1玡 
			return -1;
		else if((*a1)%2==0 && (*b1)%2==1)  // 璝*a1案计*b1计*b1玡 
			return 1;
		else if((*a1)%2==1 && (*b1)%2==1)  // 璝*a1*b1计 
		{
			if(*a1 > *b1)                  // 玥计玡 
				return -1;
			else if(*a1 == *b1)
				return 0;
			else
				return 1;
		}
		else if((*a1)%2==0 && (*b1)%2==0)  // 璝*a1*b1案计  
		{
			if(*a1 < *b1)			       // 玥计玡 
				return -1;
			else if(*a1 == *b1)
				return 0;
			else
				return 1;
		}
	}
	
	
}
