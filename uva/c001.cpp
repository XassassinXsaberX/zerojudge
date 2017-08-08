#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

/*
Longest Common Subsequence (LCS)
�i�ѦҦ����� http://www.csie.ntnu.edu.tw/~u91029/LongestCommonSubsequence.html#2 
�̪��@�P�l�ǦC�G�X�{��C�@�ӧǦC�B�ӥB�O�̪����l�ǦC�C�i�঳�\�h�ӡC
-----------------------------------------------
s1: 2 5 7 9 3 1 2
s2: 3 5 3 2 8
LCS(s1, s2) = 5 3 2
-----------------------------------------------
s1: a b c d b c e e a
s2: c a b d e f g a
s3: d c e a
LCS(s1, s2, s3) =  {c e a, d e a}
-----------------------------------------------
*/

int max(int,int);

int main()
{
	char s1[1001],s2[1001];
	int len1,len2;
	int**dp ;
	int i,j,k;

	
	while(cin>>s1>>s2)
	{
		len1 = strlen(s1);
		len2 = strlen(s2);
		
		dp = new int*[len1+1];
		for(i=0;i<len1+1;i++)
			dp[i] = new int[len2+1];
		
		//��l��dp�}�C 
		for(i=0;i<=len1;i++)
			dp[i][0] = 0;
		for(i=0;i<=len2;i++)
			dp[0][i] = 0;
		//���U�Ӷ}�l�i��ʺA�W����LCS 
		//dp�G���}�C��dp[i][j]�N��r��s1[0]~s1[i-1]�B�r��s2[0]~s2[j-1]��LCS���� 
		for(i=1;i<=len1;i++)
			for(j=1;j<=len2;j++)
			{
				if(s1[i-1] == s2[j-1])
					dp[i][j] = dp[i-1][j-1] + 1;
				else
					dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
			} 
			
		cout<<dp[len1][len2]<<endl;
		
		for(i=0;i<len1+1;i++)
			delete [] dp[i];
		delete [] dp;
	
	}
	
	
	return 0;
}

int max(int i,int j)
{
	if(i>j)
		return i;
	else
		return j;
}
