#include <stdio.h>
#include <stdlib.h>

/*����]�p�v���D�G�줸�B��*/ 

int main()
{
	int v,a,b;
	int i,j,k;
	while(scanf("%d %d %d",&v,&a,&b)!=EOF)
	{
		if(b==0)
			v &= ~(1<<a);   //�N�q�k�ƨ쥪�A��a��bit�]��1 
		else
			v |= (1<<a);    //�N�q���ƨ�k�A��a��bit�]��0 
		//�ɥR�@�U�A�Y�n�N�q���ƨ�k�A��a��bit��inverse(�Ybit1��bit0�Abit0��bit1) 
		//�h�{����
		//v ^= (1<<a); 
		for(i=31;i>=0;i--)
			printf("%d",((v>>i)&1)); //�L�X�q���ƨ�k�A��i��bit 
		printf("\n");
	}
	return 0;
}
