#include <stdio.h>
#include <stdlib.h>

/*²�檺�j��Bif else������D�B�Φr��B�z*/

int main()
{
	char str[100];
	char*ptr;
	int i,j,k;
	int sum; //�����ɶ��`�X 
	int time,time2; //time2�w�q���p���I�ɶ� 
	int unit;
	while(scanf("%s",str)!=EOF)
	{
		sum = 0;
		for(i=0;;i++)
		{
			if(str[i]=='\0')
				break;
			else if(str[i]>='0'&&str[i]<='9')
			{
				time2 = 0;
				//�q�r�ꤤŪ���ɶ� 
				sscanf(str+i,"%d",&time);
				//���U�Ӧr��n����̫�@�ӼƦr 
				for(j=i;;j++)
					if(str[j]<'0' || str[j]>'9')
						break;
				i = j - 1;
			}
			else if(str[i]=='.') //�p�G���p���I�ɶ� 
			{
				i++;
				sscanf(str+i,"%d",&time2);
				//���U�Ӧr��n����̫�@�ӼƦr 
				for(j=i;;j++)
					if(str[j]<'0' || str[j]>'9')
						break;
				i = j - 1;
			}
			else
			{
				//�q�r�ꤤŪ���ɶ���� 
				if(str[i]=='h')
					sum += time * 60 * 60 * 1000;
				else if( (str[i]=='m' && str[i+1]!='s') || (str[i]=='m' && str[i+1]=='i') ) 
					sum += time * 60 * 1000;
				else if(str[i] == 's')
					sum += time * 1000 + time2 * 100;
				else 
					sum += time;
				//�n����ɶ����r��(�^��)���̫�@�Ӧr��
				for(j=i;;j++)
					if(str[j]<'a'||str[j]>'z')
						break;
				i = j - 1; 
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}













