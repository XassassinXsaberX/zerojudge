#include <stdio.h>
#include <stdlib.h>

/*²�檺�j��Bif else������D�B�Φr��B�z*/

int main()
{
	char str[1000];
	char*p1,*p2;
	int i,j,k;
	long long int sum;
	long long int current;
	long long int num1,num2;
	while(scanf("%s",str)!=EOF)
	{
		sum = 0;
		for(i=0;;i++)
		{
			if(str[i] == '\0')
				break;
			if(str[i]>='0' && str[i]<='9')
			{
				//�����y�Ʀr 
				sscanf(str+i,"%lld",&num1);
				//�A�ӭn����Ʀr�᭱�����r�� 
				for(;;i++)
					if(str[i]<'0' || str[i]>'9')
						break;
				//�M�w�o�ӼƭȦ��X��bit 
				if(str[i]=='g')
					num1 *= (long long int)1000000000 * 8;
				else if(str[i]=='m')
					num1 *= 1000000 * 8;
				else if(str[i]=='k')
					num1 *= 1000 * 8;
				else if(str[i]=='b'&&str[i+1]=='y')
					num1 *= 8;
				else if(str[i]=='b'&&str[i+1]=='i')
					num1 = num1;
				else if(str[i]=='.')
				{
					i++;
					//�b�����y�p���I�᪺�Ʀr
					sscanf(str+i,"%lld",&num2);
					//�A�ӭn����Ʀr�᭱�����r�� 
					for(;;i++)
						if(str[i]<'0' || str[i]>'9')
							break;
					//�M�w�o�ӼƭȦ��X��bit		
					if(str[i]=='k')
						num1 = num1*1000*8 + num2*100*8;
					else if(str[i]=='b')
						num1 = num1*8 + num2;
				} 
				sum += num1;
						
			}
					
		}
		printf("%lld\n",sum);
	}
	return 0;
}
