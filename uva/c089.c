#include <stdio.h>
#include <stdlib.h>

/*�m�ߤ��P�i�춡���ഫ*/

int transfer(char input[20], char output[8], int base1, int base2);


int main()
{
	char input[20];
	char output[8];
	int base1,base2;
	int state;
	int i,j,k;
	while(scanf("%s %d %d",input,&base1,&base2)!=EOF)
	{
		state = transfer(input,output,base1,base2);
		printf("%s\n",output);
	
	}
	return 0;
	
	
}

int transfer(char input[20], char output[8], int base1, int base2)
{
	int num=0;
	int tmp;
	int len;
	int i,j,k;
	
	//�����Ninput�ন�Q��ƪ��Ʀrnum
	for(i=0;;i++)
		if(input[i]=='\0')
		{
			len = i;
			break;
		}
	tmp = 1;
	for(i=len-1;i>=0;i--)
	{
		if(input[i] >= '0' && input[i] <= '9')
			num += (input[i] - '0') * tmp;
		else
			num += (input[i] - 'A' + 10) * tmp;
		tmp *= base1;
	}
	
	//���U�ӭn�Nnum�নbase2�i�쪺�r��
	for(i=0;i<7;i++)
		output[i] = ' ';
	output[7] = '\0';
	for(i=6;i>=0;i--)
	{
		tmp = num % base2;
		if(tmp <= 9)
			output[i] = '0' + tmp;
		else
			output[i] = tmp - 10 + 'A';
		num /= base2;
		if(num == 0)
			break;
	}
	if(num == 0)
		return 0;
	else
	{
		output[0] = ' ';
		output[1] = ' ';
		output[2] = 'E';
		output[3] = 'R';
		output[4] = 'R';
		output[5] = 'O';
		output[6] = 'R';
		output[7] = '\0';
		return -1;
	}	 
}
