#include <stdio.h>
#include <stdlib.h>
#define SIZE 20000000

/*建立質數表來解決質數問題*/

typedef struct newData
{
	int data1,data2;
}Data;

int main()
{
	int*prime_table = (int*)malloc(sizeof(int)*SIZE);            //質數表 
	int*prime = (int*)malloc(sizeof(int)*1280000);               //存放質數的陣列 
	Data*cousin_prime = (Data*)malloc(sizeof(Data)*100000);      //存放質數對的陣列 
	int prime_num = 0;
	int count = 0;
	int i,j,k;
	int S;
	
	//建立質數表 
	for(i=0;i<SIZE;i++)
		prime_table[i] = 1;
	prime_table[0] = 0;
	prime_table[1] = 0;
	for(i=2;i*i<SIZE;i++)
		if(prime_table[i])
			for(j=i*i;j<SIZE;j+=i)
				prime_table[j] = 0;
				
	//接下來從質數表中找質數
	for(i=0;i<SIZE;i++)
		if(prime_table[i])
			prime[prime_num++] = i;
		
	//再來建立cousin_prime
	for(i=0;i<prime_num;i++)
	{
		if(prime_table[prime[i] + 4]) //如果質數prime[i] + 4 亦為質數，就記錄起來 
		{
			cousin_prime[count].data1 = prime[i];
			cousin_prime[count].data2 = prime[i] + 4;
			count++;
			if(count == 100000)
				break;
		} 
	} 
	
	while(scanf("%d",&S)!=EOF)
	{
		printf("(%d, %d)\n",cousin_prime[S-1].data1,cousin_prime[S-1].data2);
	}
	
	
	
	free(prime_table);
	free(prime);
	free(cousin_prime);
	return 0;
}
