#include <iostream>
#define INFINITE 100000000

/*
Bounded Knapsack Problem
*/ 

using namespace std;

int main()
{
	int N;
	int weight[2000],value[2000];       //�O���C�@�ت��~���q�λ��� 
	int weight_bound;                   //�I�]��e�Ǫ��̤j���q 
	int max_value;                      //�b���W�L�̤j���q�����p�U�A����a���̤j���~�`���� 
	int dp[10001];                      //dp[i]�ΨӬ����b���q��i�ɡA���n�o��̤j���`����dp[i] 
	int i,j,k;
	while(cin>>N)
	{
		for(i=0;i<N;i++)
		{
			cin>>weight[i];
			cin>>value[i];
		}
		cin>>weight_bound;
		
		//��l��dp�}�C 
		for(i=0;i<=weight_bound;i++)
			dp[i] = -INFINITE;
		dp[0] = 0;
		//���U�Ӷ}�l�i��ʺA�W��
		//dp[i]�N���N�O�b���qi�����p�U�A��s���`����dp[i]�����~ 
		max_value = 0;
		for(i=0;i<N;i++)
			for(j=weight_bound;j-weight[i]>=0;j--)
			{
				if(dp[j-weight[i]]>=0)   //�p�G�w�g���έp���qj-weight[i]�Ҳֿn�����~���Ȯ� 
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
