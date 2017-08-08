#include <iostream>

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

using namespace std;

int Strlen(const char*);       // �Ө�ƬO�Ψӧ�r����� 
int max3(int i,int j,int k);   // �Ө禡�O�Ψӱq�T�Ƥ���̤j�� 

int main()
{
	char s1[100],s2[100],s3[100]; //�s��T�ӿ�J�r�� 
	int len1,len2,len3;           //�s��3�Ӧr�ꪺ���� 
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
		
		//��l�ƤT����dp�}�C
		for(i=0;i<=len1;i++)
			for(j=0;j<=len2;j++)
				for(k=0;k<=len3;k++)
					dp[i][j][k] = 0;
		
		//�}�l�i��ʺA�W����LCS
		//dp�T���}�C��dp[i][j][k]�N��r��s1[0]~s1[i-1]�B�r��s2[0]~s2[j-1]�B�r��s3[0]~s3[k-1]��LCS���� 
		for(i=1;i<=len1;i++)
			for(j=1;j<=len2;j++)
				for(k=1;k<=len3;k++)
				{
					//�Y���ɤT�Ӧr�ꪺ�r�����ۦP�� 
					if(s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1])
						dp[i][j][k] = dp[i-1][j-1][k-1] + 1; //��s����LCS���� 
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


