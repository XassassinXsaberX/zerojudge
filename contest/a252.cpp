#include <iostream>

/*
Longest Common Subsequence (LCS)
可參考此網站 http://www.csie.ntnu.edu.tw/~u91029/LongestCommonSubsequence.html#2 

最長共同子序列：出現於每一個序列、而且是最長的子序列。可能有許多個。
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

using namespace std;

int Strlen(const char*);       // 該函數是用來找字串長度 
int max3(int i,int j,int k);   // 該函式是用來從三數中找最大值 

int main()
{
	char s1[100],s2[100],s3[100]; //存放三個輸入字串 
	int len1,len2,len3;           //存放3個字串的長度 
	int i,j,k;
	int *dp[101][101];  
	for(i=0;i<101;i++)
		for(j=0;j<101;j++)
			dp[i][j] = new int[101];
			
	while(cin>>s1>>s2>>s3)
	{
		len1 = Strlen(s1);
		len2 = Strlen(s2);
		len3 = Strlen(s3);
		
		//初始化三維的dp陣列
		for(i=0;i<=len1;i++)
			for(j=0;j<=len2;j++)
				for(k=0;k<=len3;k++)
					dp[i][j][k] = 0;
		
		//開始進行動態規劃找LCS
		//dp三維陣列中dp[i][j][k]代表字串s1[0]~s1[i-1]、字串s2[0]~s2[j-1]、字串s3[0]~s3[k-1]的LCS長度 
		for(i=1;i<=len1;i++)
			for(j=1;j<=len2;j++)
				for(k=1;k<=len3;k++)
				{
					//若此時三個字串的字元都相同時 
					if(s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1])
						dp[i][j][k] = dp[i-1][j-1][k-1] + 1; //更新此刻LCS長度 
					else
						dp[i][j][k] = max3(dp[i][j][k-1], dp[i][j-1][k], dp[i-1][j][k]);
				} 
			
		cout<<dp[len1][len2][len3];
		
		 
	
	}
	return 0;

}

int Strlen(const char*s)
{
	int i;
	for(i=0;;i++)
		if(s[i]=='\0')
			return i;
}

int max3(int i,int j,int k)
{
	if(i>=j && i>=k)
		return i;
	else if(j>=i && j>=k)
		return j;
	else
		return k;
}


