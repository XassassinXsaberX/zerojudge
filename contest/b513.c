#include <stdio.h>
#include <stdlib.h>

/*�إ߽�ƪ�ӧP�_���*/

int main()
{
	int*prime_table = (int*)malloc(sizeof(int)*65536);
	int i,j,k;
	int n,input;
	
	//�H�U���إ߽����y�{ 
	for(i=0;i<65536;i++)
		prime_table[i] = 1;
	prime_table[0] = 0;
	prime_table[1] = 0;
	for(i=2;i*i<65536;i++)
		if(prime_table[i] == 1)
			for(j=i*i;j<65536;j+=i)
				prime_table[j] = 0;
	//��prime_table[i] == 1  �N��i�����
	//��prime_table[i] == 0  �N��i�������

	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&input);
			if(prime_table[input] == 0)
				printf("N\n");
			else
				printf("Y\n");
		}
	}
	
	
	
	free(prime_table);
	return 0;
}
