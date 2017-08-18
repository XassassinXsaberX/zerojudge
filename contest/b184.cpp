#include <iostream>
#define INFINITE 1000000 

/*
0/1 Knapsack Problem
*/

using namespace std;

int main()
{
	int n;
	int dp[101];                  // �b��ni�ɡA�i�H��n�o��̤j���`���� dp[i]
	int volume[1000],price[1000]; // volume�����C���ӫ~����n�Bprice�����C�Ӫ��~����
	int i,j,k;
	int max_price;                // �����̤j�`���� 
	
	while(cin>>n)
	{
		for(i=0;i<n;i++)
			cin>>volume[i]>>price[i];
			
		// ���U�Ӫ�l��dp�}�C
		for(i=0;i<101;i++)
			dp[i] = -INFINITE;
		dp[0] = 0;
		
		max_price = 0;
		
		// ���U�Ӷ}�l�i��ʺA�W��
		// dp[i]�N��b��n��i�����p�U�A�i�H�s���`���Ȭ�dp[i]�����~ 
		for(i=0;i<n;i++) //�Ҽ{�Ҧ������~ 
			for(j=100;j-volume[i]>=0;j--)
			{
				// �p�G�w�g���έp��n��j-volume[i]�ɥi�����쪺���~����
				// �ӥB��n��j-volume[i]���h�Ӫ��~�[�W��i�Ӫ��~������ �� ��n��j���h�Ӫ��~�������٦h 
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

