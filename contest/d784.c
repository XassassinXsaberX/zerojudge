#include <stdio.h>
#include <stdlib.h>

/*
maximum subarray問題，使用Kadane's algorithm  一種dp的方法來解決此問題 
*/ 
int main()
{
	int t;
	int n;
	int arr[100];
	int dp[100]; 
	int max;
	int i,j,k;
	while(scanf("%d",&t)!=EOF)
	{
		for(i=0;i<t;i++)
		{
			scanf("%d",&n);
			for(j=0;j<n;j++)
				scanf("%d",&arr[j]);
			
			//接下來利用dp的方法找出maximum subarray
			dp[0] = arr[0];
			max = dp[0]; 
			for(j=1;j<n;j++) 
			{
				if(dp[j-1]>0)
					dp[j] = dp[j-1] + arr[j];
				else
					dp[j] = arr[j];
				if(dp[j] > max)
					max = dp[j];
			}
			printf("%d\n",max); 
		}
	
	}
	return 0; 
}
