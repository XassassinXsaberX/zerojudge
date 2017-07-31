#include <stdio.h>
#include <stdlib.h>

/*利用遞迴解決排列組合問題*/

void recursion(int current,int*arr,int*use,int n);

int main()
{
	int n;
	int i,j;
	int arr[8],use[8];
	while(scanf("%d",&n)!=EOF)
	{
		//初始化use陣列
		//use陣列是用來紀錄哪些數字已被用過 
		for(i=0;i<n;i++)
			use[i] = 0; 
		recursion(0,arr,use,n);
	}
	return 0;
}

void recursion(int current,int*arr,int*use,int n)
{
	int i,j,k;
	if(current == n)
	{
		for(i=0;i<n;i++)
			printf("%d",arr[i]);
		printf("\n");
	}
	else
	{
		for(i=n-1;i>=0;i--)
		{
			//當某個數字還沒被使用，才能用他來排列 
			if(use[i]==0)
			{
				use[i] = 1;
				arr[current] = i+1;
				recursion(current+1,arr,use,n);
				use[i] = 0;
			}
		}
	}
}
