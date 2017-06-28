#include <stdio.h>
#include <stdlib.h>

/*�o�@�D�]�O²�檺���j�m���D*/

void recursion(int N,int current,int left,int right,char*str);

int main()
{
	int N;
	char str[30];
	while(scanf("%d",&N)!=EOF)
	{
		recursion(N,0,0,0,str);
		printf("\n");
	}
	return 0;
}

void recursion(int N,int current,int left,int right,char*str)
{ //N�N��n���X�դ��ۤǰt���A���Bcurrent�N��ثe���j�쪺��m�Bleft�N��ثe���X�ӥ��A���Bright�N��ثe���X�ӥk�A�� 
	int i,j;
	if(current == 2*N)
	{
		str[current] = '\0';
		printf("%s\n",str);
	}
	else
	{
		//�P�_�Ӧ�m�O�_��񥪬A�� 
		if(left+1<=N)
		{
			str[current]='(';
			recursion(N,current+1,left+1,right,str);
		}
		//�P�_�Ӧ�m�O�_���k�A�� 
		if(left>=right+1)
		{
			str[current]=')'; 
			recursion(N,current+1,left,right+1,str);
		}
	} 
	
}
