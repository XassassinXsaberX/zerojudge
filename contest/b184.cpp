#include <iostream>
#define INFINITE 1000000 

/*
0/1 Knapsack Problem
*/

using namespace std;

int main()
{
	int n;
	int dp[101];                  // 在體積i時，可以剛好得到最大的總價值 dp[i]
	int volume[1000],price[1000]; // volume紀錄每物個品的體積、price紀錄每個物品價錢
	int i,j,k;
	int max_price;                // 紀錄最大總價值 
	
	while(cin>>n)
	{
		for(i=0;i<n;i++)
			cin>>volume[i]>>price[i];
			
		// 接下來初始化dp陣列
		for(i=0;i<101;i++)
			dp[i] = -INFINITE;
		dp[0] = 0;
		
		max_price = 0;
		
		// 接下來開始進行動態規劃
		// dp[i]代表在體積為i的情況下，可以存放總價值為dp[i]的物品 
		for(i=0;i<n;i++) //考慮所有的物品 
			for(j=100;j-volume[i]>=0;j--)
			{
				// 如果已經有統計體積為j-volume[i]時可收集到的物品價值
				// 而且體積為j-volume[i]的多個物品加上第i個物品的價值 比 體積為j的多個物品的價值還多 
				if(dp[j-volume[i]] != -INFINITE && dp[j-volume[i]] + price[i] > dp[j])
				{
					dp[j] = dp[j-volume[i]] + price[i];
					if(dp[j]>max_price)
						max_price = dp[j];
				}
					
			
			}
		
		cout<<max_price<<endl;
		
	}
	return 0;
	

}

