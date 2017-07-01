#include <stdio.h>
#include <stdlib.h>

/*最簡單的動態規劃問題*/

int main()
{
	long long int arr[51];
	int i,j,k;
	int n;
	arr[1] = 1;
	arr[2] = 2;
	for(i=3;i<51;i++)
		arr[i] = arr[i-1] + arr[i-2];
	while(scanf("%d",&n)!=EOF)
	{
		if(n == 0)
			break;
		printf("%lld\n",arr[n]);
	}
	return 0;
}
