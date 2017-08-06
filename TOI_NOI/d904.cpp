#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define INFINITE 1000000

using namespace std;

/*
換零錢的dp問題
湊到某個價位的最少硬幣用量 changing making problem 
*/

int main()
{
	int C,N;
	int dp[1001];
	int coin[10];
	int i,j,k;
	
	while(scanf("%d %d",&C,&N)!=EOF)
	{
		//目標是最少硬幣數，來收集到C元
		//共有N個硬幣
		 
		for(i=0;i<N;i++)
			cin>>coin[i];
			
		//先初始化dp陣列
		for(i=0;i<=C;i++) 
			dp[i] = INFINITE;
		dp[0] = 0;
		
		//接下來開始進行動態規劃
		for(i=0;i<N;i++)
			for(j=0;j+coin[i]<=C;j++)
			{
				//dp[j]代表目前湊到 j元 需要多少個硬幣 
				if(dp[j] + 1 < dp[j+coin[i]])
					dp[j+coin[i]] = dp[j]+1;
					
			} 
		
		cout<<dp[C]<<endl;
	}
	return 0;
	

}
