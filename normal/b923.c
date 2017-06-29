#include <stdio.h>
#include <stdlib.h>

/*簡單的堆疊練習*/

int main()
{
	int n;
	int i,j,k;
	int input;
	int oper;
	int *stack = (int*)malloc(sizeof(int)*100000);
	int top;//用來紀錄目前堆疊的頂端 
	
	while(scanf("%d",&n)!=EOF)
	{
		top = -1;
		for(i=0;i<n;i++)
		{
			scanf("%d",&oper);
			if(oper == 1)
				top -= 1;
			else if(oper == 2)
				printf("%d\n",stack[top]);
			else if(oper == 3)
			{
				scanf("%d",&input);
				top += 1;
				stack[top] = input;
			}
		}
	}
	return 0;
}
