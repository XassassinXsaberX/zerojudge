#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define INFINITE 1000000

using namespace std;

/*
���s����dp���D
���Y�ӻ��쪺�ֵ̤w���ζq changing making problem 
*/

int main()
{
	int C,N;
	int dp[1001];
	int coin[10];
	int i,j,k;
	
	while(scanf("%d %d",&C,&N)!=EOF)
	{
		//�ؼЬO�ֵ̤w���ơA�Ӧ�����C��
		//�@��N�ӵw��
		 
		for(i=0;i<N;i++)
			cin>>coin[i];
			
		//����l��dp�}�C
		for(i=0;i<=C;i++) 
			dp[i] = INFINITE;
		dp[0] = 0;
		
		//���U�Ӷ}�l�i��ʺA�W��
		for(i=0;i<N;i++)
			for(j=0;j+coin[i]<=C;j++)
			{
				//dp[j]�N��ثe��� j�� �ݭn�h�֭ӵw�� 
				if(dp[j] + 1 < dp[j+coin[i]])
					dp[j+coin[i]] = dp[j]+1;
					
			} 
		
		cout<<dp[C]<<endl;
	}
	return 0;
	

}
