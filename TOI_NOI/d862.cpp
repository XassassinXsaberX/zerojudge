#include <iostream>
using namespace std;

/*
0/1背包問題 (0/1 knapsack problem) 
0/1 的意思是：每種物品只會放進背包零個或一個。一個物品要嘛整個不放進背包、要嘛整個放進背包。物品無法切割。 
此題要問的是 "讓背包裡面的物品總體積最大" 
*/

int main()
{
	int v;            //背包能容納的最大體積 
	int n;            //總共有n個物品 
	int arr[30];      //arr陣列用來存放每個物品的體積 
	char dp[20001];    
	int i,j,k;
	int max_volume;   //從n個物品中，選特定幾個物品後讓總體積最大化，但不能超過v 
	
	while(cin>>v)
	{
		cin>>n;
		for(i=0;i<n;i++)
			cin>>arr[i];
			
		//接下來要初始化dp陣列
		for(i=0;i<=v;i++)
			dp[i] = 0;
		dp[0] = 1;
		 
		//開始進行動態規劃 
		max_volume = 0;  //紀錄所有物品累積的最大體積 (注意：不能超過背包能容納的最大體積v) 
		for(i=0;i<n;i++) //窮舉所有可能物品的體積 (arr[i] 代表物品i的體積) 
		{
			for(j=v;j-arr[i]>=0;j--)
			{
				if(dp[j-arr[i]] == 1)     //如果在未放入物品i時，其他物品的總體積可以累積到 j-arr[i] 
				{
					dp[j] = 1;            //代表加上物品i的體積時，總體積可到達j 
					if(j > max_volume)    //若加上物品i的體積arr[i]後，其總體積超過max_volume(但不超過v) 
						max_volume = j;   //則更新max_volume值 
				}			
			}
		}
		
		cout<<(v - max_volume)<<endl;
		 
	
	}
	return 0;
}
