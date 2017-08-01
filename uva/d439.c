#include <stdio.h>
#include <stdlib.h>

/*
��ƪ� + dp�����D 
*/

int main()
{
	int*prime_table = (int*)malloc(sizeof(int)*800);
	int*prime = (int*)malloc(sizeof(int)*800);
	int prime_num; 
	int*sopf = (int*)malloc(sizeof(int)*500001); //�o�Ӱ}�C�ΨӬ���sopf(i) ���� 
	int*dp = (int*)malloc(sizeof(int)*500001);       //�o�Ӱ}�C�ΨӬ���lsopf(i) ���� 
	int i,j,k;
	int temp,sum;
	int T,n,m;
	int max;
	
	
	//�إ߽�ƪ� 
	for(i=0;i<800;i++)
		prime_table[i] = 1;
	prime_table[0] = 0;
	prime_table[1] = 0;
	for(i=2;i*i<800;i++)
		if(prime_table[i])
			for(j=i*i;j<800;j+=i)
				prime_table[j] = 0;
				
	//�إߧ���ƪ��A�}�l����ǼƬ���ơA�é��prime��
	prime_num = 0;
	for(i=2;i<800;i++)
		if(prime_table[i])
			prime[prime_num++] = i;

	
	// ���U�ӭn�έp�q2~500000�A��sopf��
	// sopf�ȫ����N�O���t1����]�Ƥ��ѫ᪺�M
	// ex. 28 = 2 * 2 * 7
	// �ҥHsopf[28] = 2 + 2 + 7 = 11 
	//
	// ���ξ��1~800����Ƥ����ΨӰ���]�Ƥ���
	// ex �H334142����
    //    334142����Ʀ�2�A�ҥH334142/2 = 167071
    //    ���U��1~800����Ƥ��S����ƥi�H�A�㰣167071�A�ҥH167071�����
    //    �G334142 = 2 * 167071
	//    sopf(334142) = 2 + 167071
	
	for(i=2;i<500001;i++)
	{
		temp = i;
		sum = 0;
		for(j=0;j<prime_num;j++) //prime���@��prime_num�ӽ�� 
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
		if(temp!=1)//����temp�笰��� 
			sum += temp;
			
		sopf[i] = sum;
	} 
	
	
	//���U�ӭn�έp�q2~500000�A��lsopf�� (�Q��dp���覡)
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
			//��Xn ~ m���A�̤j����̪�lsopf�̤j 
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








