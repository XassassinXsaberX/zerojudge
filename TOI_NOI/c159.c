#include <stdio.h>
#include <stdlib.h>

int main()
{
	int arr[10001];
	int set[100];
	int num;
	int count;
	int i,j,k;
	int input;
	while(scanf("%d",&num)!=EOF)
	{
		for(i=0;i<10001;i++)
			arr[i] = -1;
			
		count = 0;
		
		for(i=0;i<num;i++)
		{
			scanf("%d",&set[i]);
			arr[set[i]] = 0;
		}
			
		
		for(i=0;i<num;i++)
			for(j=i+1;j<num;j++)
			{
				if(set[i]+set[j]<=10000 && arr[set[i]+set[j]] == 0)
				{
					arr[set[i]+set[j]] = 1;
					count++;
				}	
				
			}
		printf("%d\n",count);
	
	}
	return 0;
}
