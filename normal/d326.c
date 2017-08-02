#include <stdio.h>
#include <stdlib.h>

/*韌體設計師基本題：位元運算*/ 

int main()
{
	int v,a,b;
	int i,j,k;
	while(scanf("%d %d %d",&v,&a,&b)!=EOF)
	{
		if(b==0)
			v &= ~(1<<a);   //將從右數到左，第a個bit設為1 
		else
			v |= (1<<a);    //將從左數到右，第a個bit設為0 
		//補充一下，若要將從左數到右，第a個bit做inverse(即bit1變bit0，bit0變bit1) 
		//則程式為
		//v ^= (1<<a); 
		for(i=31;i>=0;i--)
			printf("%d",((v>>i)&1)); //印出從左數到右，第i個bit 
		printf("\n");
	}
	return 0;
}
