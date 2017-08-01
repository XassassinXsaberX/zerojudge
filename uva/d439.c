#include <stdio.h>
#include <stdlib.h>

/*
質數表 + dp的問題 
*/

int main()
{
	int*prime_table = (int*)malloc(sizeof(int)*800);
	int*prime = (int*)malloc(sizeof(int)*800);
	int prime_num; 
	int*sopf = (int*)malloc(sizeof(int)*500001); //這個陣列用來紀錄sopf(i) 的值 
	int*dp = (int*)malloc(sizeof(int)*500001);       //這個陣列用來紀錄lsopf(i) 的值 
	int i,j,k;
	int temp,sum;
	int T,n,m;
	int max;
	
	
	//建立質數表 
	for(i=0;i<800;i++)
		prime_table[i] = 1;
	prime_table[0] = 0;
	prime_table[1] = 0;
	for(i=2;i*i<800;i++)
		if(prime_table[i])
			for(j=i*i;j<800;j+=i)
				prime_table[j] = 0;
				
	//建立完質數表後，開始找哪些數為質數，並放到prime中
	prime_num = 0;
	for(i=2;i<800;i++)
		if(prime_table[i])
			prime[prime_num++] = i;

	
	// 接下來要統計從2~500000，其sopf值
	// sopf值指的就是不含1的質因數分解後的和
	// ex. 28 = 2 * 2 * 7
	// 所以sopf[28] = 2 + 2 + 7 = 11 
	//
	// 不用擔心1~800的質數不夠用來做質因數分解
	// ex 以334142為例
    //    334142的質數有2，所以334142/2 = 167071
    //    接下來1~800的質數中沒有質數可以再整除167071，所以167071為質數
    //    故334142 = 2 * 167071
	//    sopf(334142) = 2 + 167071
	
	for(i=2;i<500001;i++)
	{
		temp = i;
		sum = 0;
		for(j=0;j<prime_num;j++) //prime中共有prime_num個質數 
		{
			if(temp%prime[j] == 0)
			{
				while(1)
				{
					if(temp%prime[j]!=0)
						break;
					sum += prime[j];
					temp /= prime[j];
				}
			} 
			if(temp==1)
				break;
		} 
		if(temp!=1)//此時temp亦為質數 
			sum += temp;
			
		sopf[i] = sum;
	} 
	
	
	//接下來要統計從2~500000，其lsopf值 (利用dp的方式)
	dp[0] = 0;
	dp[1] = 0;
	for(i=2;i<500001;i++)
	{
		if(sopf[i] == i)
			dp[i] = 1;			
		else
			dp[i] = dp[sopf[i]] + 1;
	}
	
	
	while(scanf("%d",&T)!=EOF)
	{
		for(i=0;i<T;i++)
		{
			scanf("%d %d",&n,&m);
			if(n>m)
			{
				n^=m;
				m^=n;
				n^=m;
			}
			//找出n ~ m中，最大的何者的lsopf最大 
			max = 0; 
			for(j=n;j<=m;j++)
				if(max<dp[j])
					max = dp[j];
			printf("Case #%d:\n",i+1);
			printf("%d\n",max);
		}
	}
	
	free(dp);
	free(sopf);
	free(prime_table);
	free(prime);
	
	return 0;
	
	
}








