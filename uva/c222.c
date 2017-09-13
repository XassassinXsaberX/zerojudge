#include <stdio.h>
#include <stdlib.h>

/*��¦��bitwise operation*/

void print_bit(unsigned int); //�Ψ��[��줸�Ȭ��� 

int main()
{
	unsigned int a,b,c;
	int bit;
	int i,j;
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		for(i=0;i<32;i++)
		{
			bit = ((a^b)>>i) & 1; // bit�N��q�k��ƹL�Ӳ�i��bit�Ȭ��� 
			if(bit == 1)          
				c |= 1 << i;      // �Nc�q�k��ƹL�Ӳ�i��bit�]��1 
			else
				c &= ~(1<<i);     // �Nc�q�k��ƹL�Ӳ�i��bit�]��0 
		}
		/*  //�i�H�Ψ��[��a,b,c���줸�Ȭ��� 
		printf("a=");
		print_bit(a);
		printf("b=");
		print_bit(b);
		printf("c=");
		print_bit(c);
		*/
		printf("%u\n",c);
	}
	return 0;

}

void print_bit(unsigned int a)
{
	int i,j;
	for(i=31;i>=0;i--)
		printf("%d",(a>>i)&1);
	printf("\n");
	
}



