#include <stdio.h>
#include <stdlib.h>

/*這一題也是簡單的遞迴練習題*/

void recursion(int N,int current,int left,int right,char*str);

int main()
{
	int N;
	char str[30];
	while(scanf("%d",&N)!=EOF)
	{
		recursion(N,0,0,0,str);
		printf("\n");
	}
	return 0;
}

void recursion(int N,int current,int left,int right,char*str)
{ //N代表要有幾組互相匹配的括號、current代表目前遞迴到的位置、left代表目前有幾個左括號、right代表目前有幾個右括號 
	int i,j;
	if(current == 2*N)
	{
		str[current] = '\0';
		printf("%s\n",str);
	}
	else
	{
		//判斷該位置是否能放左括號 
		if(left+1<=N)
		{
			str[current]='(';
			recursion(N,current+1,left+1,right,str);
		}
		//判斷該位置是否能放右括號 
		if(left>=right+1)
		{
			str[current]=')'; 
			recursion(N,current+1,left,right+1,str);
		}
	} 
	
}
