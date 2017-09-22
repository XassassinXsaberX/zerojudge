#include <stdio.h>
#include <stdlib.h>
#define SIZE 20000000

/*�إ߽�ƪ�ӸѨM��ư��D*/

typedef struct newData
{
	int data1,data2;
}Data;

int main()
{
	int*prime_table = (int*)malloc(sizeof(int)*SIZE);            //��ƪ� 
	int*prime = (int*)malloc(sizeof(int)*1280000);               //�s���ƪ��}�C 
	Data*cousin_prime = (Data*)malloc(sizeof(Data)*100000);      //�s���ƹ諸�}�C 
	int prime_num = 0;
	int count = 0;
	int i,j,k;
	int S;
	
	//�إ߽�ƪ� 
	for(i=0;i<SIZE;i++)
		prime_table[i] = 1;
	prime_table[0] = 0;
	prime_table[1] = 0;
	for(i=2;i*i<SIZE;i++)
		if(prime_table[i])
			for(j=i*i;j<SIZE;j+=i)
				prime_table[j] = 0;
				
	//���U�ӱq��ƪ�����
	for(i=0;i<SIZE;i++)
		if(prime_table[i])
			prime[prime_num++] = i;
		
	//�A�ӫإ�cousin_prime
	for(i=0;i<prime_num;i++)
	{
		if(prime_table[prime[i] + 4]) //�p�G���prime[i] + 4 �笰��ơA�N�O���_�� 
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
