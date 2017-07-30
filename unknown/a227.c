#include <stdio.h>
#include <stdlib.h>

//典型的河內塔問題

void recursion(int N,char start,char mid,char end);

int main()
{
	int N;
	int i,j;
	while(scanf("%d",&N)!=EOF)
	{
		recursion(N,'A','B','C');
	}
	return 0;
}

void recursion(int N,char start,char mid,char end)
{
	if(N==1)
		printf("Move ring 1 from %c to %c\n",start,end);
	else
	{
		recursion(N-1,start,end,mid);
		printf("Move ring %d from %c to %c\n",N,start,end);
		recursion(N-1,mid,start,end);
	
	}
}

