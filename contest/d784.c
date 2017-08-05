#include <stdio.h>
#include <stdlib.h>

/*
maximum subarray���D�A�ϥ�Kadane's algorithm  �@��dp����k�ӸѨM�����D 
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
			
			//���U�ӧQ��dp����k��Xmaximum subarray
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
