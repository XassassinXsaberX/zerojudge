#include <stdio.h>
#include <stdlib.h>

/*應用到堆疊概念的題目*/

int main()
{
	int stack;
	int top;
	int count;
	int N;
	int i,j,k;
	char *s1;
	s1 = (char*)malloc(sizeof(char)*10000000);
	
	while(scanf("%d",&N)!=EOF)
	{
		for(i=0;i<N;i++)
		{
			count = 0;
			top = -1;  //stack的最頂端 
			scanf("%s",s1);
			for(j=0;;j++)
			{
				if(s1[j]=='\0')
					break;
				if(s1[j]=='p')
					top += 1;
				else if(s1[j]=='q' && top != -1)
				{
					top -= 1;
					count += 1;
				}
			}
			printf("%d\n",count);
		}
		
	}
	free(s1);
	return 0;
}
