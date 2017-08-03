#include <stdio.h>
#include <stdlib.h>

/*
�o�@�D�Ҫ��O�V�m�A��bitwise operation�N0�B1�զ����r���ন�G�i��Ʀr
�̫�A��gcd���P�_ 
*/

int gcd(int a,int b);

int main()
{
	int N;
	char s1[31],s2[31];
	int S,L;
	int i,j,k;
	while(scanf("%d",&N)!=EOF)
	{
		for(i=0;i<N;i++)
		{
			scanf("%s",s1);
			scanf("%s",s2);
			
			//�Ns1�Bs2�ন�Q�i��Ʀr�s��S�BL�� 
			S = 0;
			L = 0;
			for(j=0;s1[j]!='\0';j++)
			{
				S  <<= 1;
				if(s1[j] == '1')
					S |= 1;
			}
			for(j=0;s2[j]!='\0';j++)
			{
				L <<= 1;
				if(s2[j] == '1')
					L |= 1;
			}
			
			//�̫�P�_S,L�O�_���� 
			if(gcd(S,L) == 1)
				printf("Pair #%d: Love is not all you need!\n",i+1);	
			else
				printf("Pair #%d: All you need is love!\n",i+1);
			
			
			
		}
	}
	
	return 0;
}

int gcd(int a,int b)
{
	if(a%b == 0)
		return b;
	else
		return gcd(b,a%b);
}

