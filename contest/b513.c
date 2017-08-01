#include <stdio.h>
#include <stdlib.h>

/*建立質數表來判斷質數*/

int main()
{
	int*prime_table = (int*)malloc(sizeof(int)*65536);
	int i,j,k;
	int n,input;
	
	//以下為建立質樹表的流程 
	for(i=0;i<65536;i++)
		prime_table[i] = 1;
	prime_table[0] = 0;
	prime_table[1] = 0;
	for(i=2;i*i<65536;i++)
		if(prime_table[i] == 1)
			for(j=i*i;j<65536;j+=i)
				prime_table[j] = 0;
	//當prime_table[i] == 1  代表i為質數
	//當prime_table[i] == 0  代表i不為質數

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
