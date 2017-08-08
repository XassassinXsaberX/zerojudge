#include <iostream>
#define INFINITE 100000000

/*
Bounded Knapsack Problem
*/ 

using namespace std;

int main()
{
	int N;
	int weight[2000],value[2000];       //癘魁–贺珇秖の基 
	int weight_bound;                   //璉甧程秖 
	int max_value;                      //ぃ禬筁程秖薄猵拟盿程珇羆基 
	int dp[10001];                      //dp[i]ノㄓ魁秖i眔程羆基dp[i] 
	int i,j,k;
	while(cin>>N)
	{
		for(i=0;i<N;i++)
		{
			cin>>weight[i];
			cin>>value[i];
		}
		cin>>weight_bound;
		
		//﹍てdp皚 
		for(i=0;i<=weight_bound;i++)
			dp[i] = -INFINITE;
		dp[0] = 0;
		//钡ㄓ秨﹍秈︽笆篈砏购
		//dp[i]碞琌秖i薄猵羆基dp[i]珇 
		max_value = 0;
		for(i=0;i<N;i++)
			for(j=weight_bound;j-weight[i]>=0;j--)
			{
				if(dp[j-weight[i]]>=0)   //狦竒Τ参璸秖j-weight[i]┮仓縩珇基 
				{
					if(dp[j] < dp[j-weight[i]] + value[i])
					{
						dp[j] = dp[j-weight[i]] + value[i];
						if(dp[j] > max_value)
							max_value = dp[j];
					}
						
				} 
			}
		cout<<max_value<<endl;
	}
	return 0;
	
}
