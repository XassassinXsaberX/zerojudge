#include <stdio.h>
#include <stdlib.h>

/* 典型的河內塔問題  */ 

void recursion(char start,char mid,char end,int ring)
{
	if(ring==1)   
		printf("Move ring %d from %c to %c\n",ring,start,end);
	else
	{	

		recursion(start,end,mid,ring-1);
		printf("Move ring %d from %c to %c\n",ring,start,end);
		recursion(mid,start,end,ring-1);
	}

	
}

int main()
{
	int N;
	while(scanf("%d",&N)!=EOF)
	{
		recursion('A','B','C',N);

		printf("\n");
	}
	return 0;
}

