#include <stdio.h>
#include <stdlib.h>

/*基礎的bitwise operation*/

void print_bit(unsigned int); //用來觀察位元值為何 

int main()
{
	unsigned int a,b,c;
	int bit;
	int i,j;
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		for(i=0;i<32;i++)
		{
			bit = ((a^b)>>i) & 1; // bit代表從右邊數過來第i個bit值為何 
			if(bit == 1)          
				c |= 1 << i;      // 將c從右邊數過來第i個bit設為1 
			else
				c &= ~(1<<i);     // 將c從右邊數過來第i個bit設為0 
		}
		/*  //可以用來觀察a,b,c的位元值為何 
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



