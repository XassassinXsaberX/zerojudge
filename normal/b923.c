#include <stdio.h>
#include <stdlib.h>

/*²�檺���|�m��*/

int main()
{
	int n;
	int i,j,k;
	int input;
	int oper;
	int *stack = (int*)malloc(sizeof(int)*100000);
	int top;//�ΨӬ����ثe���|������ 
	
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
