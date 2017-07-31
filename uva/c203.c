#include <stdio.h>
#include <stdlib.h>

/*碝т俱计い┮Τ计*/

int main()
{
	int n;
	int input;
	int i,j,k;
	int sum;
	
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&input);
			//钡ㄓ璶тinputいΤㄇ计
			//盢硂ㄇ计(ぃ妮计) 
			//ex  6计Τ1236
			//    sum = 1 + 2 + 3 
			sum = 0;
			for(j=1;j*j<=input;j++)
			{
				if(input%j == 0)
				{
					if(j == 1)
						sum += j;
					else if(j == input/j)
						sum += j;
					else
					{
						sum += j;
						sum += input/j;
					}
				}	
			} 
			
			if(input == sum)
				printf("perfect\n");
			else if(sum<input)
				printf("deficient\n");
			else
				printf("abundant\n");
		}
	}
	return 0;
}
