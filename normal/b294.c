#include <stdio.h>
#include <stdlib.h>

/*基礎的運算問題*/

int main()
{
	int n;
	long long int i;
	long long int num;
	long long int sum;
	while(scanf("%d",&n)!=EOF)
	{
		sum = 0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&num);
			sum += i*num;
		}
		printf("%lld\n",sum);
	}
	return 0;
}
