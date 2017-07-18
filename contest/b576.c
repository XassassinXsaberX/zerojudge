#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*考數列的觀察*/

int main()
{
	int T;
	long long int K;
	int i,j,k;
	int count;
	long long int arr[40];
	float f;
	
	arr[0] = 3;
	for(i=1;i<40;i++)
		arr[i] = arr[i-1]*2;
		
	while(scanf("%d",&T)!=EOF)
	{
		for(i=0;i<T;i++)
		{
			scanf("%lld",&K);
			if((K-2)%3==0)
				printf("2\n");
			else
			{
				count = 0;
				while(1)
				{
					for(j=30;j>=0;j--)
					{
						if(arr[j]<K)
						{
							K -= arr[j];
							count++;
							break;
						}
					}
					if(K<=3)
						break;
				}
				if(count%2==1)
					if(K == 3)
						printf("1\n");
					else
						printf("3\n");
				else
					printf("%d\n",K);
			}
			
		}
	
	}
	return 0;
}
