#include <stdio.h>
#include <stdlib.h>

/*這一題的目的是要找最大公因數*/ 

int gcd(int a,int b);

int main()
{
	int a,b;
	int c;
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		c = gcd(a,b);
		printf("%d\n",c);
	}	
	return 0;
}

int gcd(int a,int b)
{
	int i;
	while(1)
	{
		i = a%b;
		if(i==0)
			return b;
		a=b;
		b=i;
	}
}
