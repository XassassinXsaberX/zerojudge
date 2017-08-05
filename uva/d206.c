#include <stdio.h>
#include <stdlib.h>

/*
 maximum subarray���G����
 �p�Ginput matrix arr��
 0   -2   -7    0
 9    2   -6    2
-4    1   -4    1
-1    8    0   -2
�ڭ̧�L��
 0    0    0    0    0
 0    0   -2   -7    0
 0    9    2   -6    2
 0   -4    1   -4    1
 0   -1    8    0   -2  


 �g�Ldp���ֿnmatrix�ܬ�
 0    0    0    0    0
 0    0   -2   -9    0
 0    9    9   -4   -2
 0    5    6  -11   -8
 0    4   13   -4   -3
 
 �Ҧpdp[2][3] = arr[1][1] + arr[1][2] + arr[1][3] 
              + arr[2][1] + arr[2][2] + arr[2][3]
              
 
 
 �̫��ǥ�dp matrix��̤j�϶�
 �Ҧp�϶� arr[1][2]  arr[1][3]  arr[1][4]
          arr[2][2]  arr[2][3]  arr[2][4] ���`�M
 ��dp[2][4] - dp[2][1] - dp[0][4] + dp[0][1] 
 
*/

int main()
{
	int N;
	int arr[100][100];
	int dp[101][101];
	int i,j,k,l;
	int max;
	while(scanf("%d",&N)!=EOF)
	{
		for(i=0;i<N;i++)
			for(j=0;j<N;j++)
				scanf("%d",&arr[i][j]);
		// ��l��dp matrix 
		for(i=0;i<N+1;i++)
			for(j=0;j<N+1;j++)
				dp[i][j] = 0;
				
		// �}�l�إ�dp matrix 
		for(i=1;i<N+1;i++)
			for(j=1;j<N+1;j++)
				dp[i][j] = arr[i-1][j-1] + dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1];
		
		// �qdp matrix��̤j�`�M�϶���   
		max = -100000000;
		for(i=1;i<N+1;i++)
			for(j=1;j<N+1;j++)
				for(k=0;k<i;k++)
					for(l=0;l<j;l++)
					{
						if(dp[i][j] - dp[k][j] - dp[i][l] + dp[k][l] > max)
							max = dp[i][j] - dp[k][j] - dp[i][l] + dp[k][l];
					}
		
		printf("%d\n",max);
	}
	
	
}
