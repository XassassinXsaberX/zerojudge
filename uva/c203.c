#include <stdio.h>
#include <stdlib.h>

/*�M��@��Ƥ����Ҧ��i��]��*/

int main()
{
	int n;
	int input;
	int i,j,k;
	int sum;
	
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&input);
			//���U�ӭn��Xinput�������Ǧ]��
			//�ñN�o�Ǧ]�Ƭۥ[(���[�W�ݩ�ۤv���]��) 
			//ex  6���]�Ʀ�1�B2�B3�B6
			//    sum = 1 + 2 + 3 
			sum = 0;
			for(j=1;j*j<=input;j++)
			{
				if(input%j == 0)
				{
					if(j == 1)
						sum += j;
					else if(j == input/j)
						sum += j;
					else
					{
						sum += j;
						sum += input/j;
					}
				}	
			} 
			
			if(input == sum)
				printf("perfect\n");
			else if(sum<input)
				printf("deficient\n");
			else
				printf("abundant\n");
		}
	}
	return 0;
}
