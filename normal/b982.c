#include <stdio.h>
#include <stdlib.h>

/*簡單的迴圈、if else控制問題、及字串處理*/

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
				//先掃描數字 
				sscanf(str+i,"%lld",&num1);
				//再來要跳到數字後面的單位字串 
				for(;;i++)
					if(str[i]<'0' || str[i]>'9')
						break;
				//決定這個數值有幾個bit 
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
					//在次掃描小數點後的數字
					sscanf(str+i,"%lld",&num2);
					//再來要跳到數字後面的單位字串 
					for(;;i++)
						if(str[i]<'0' || str[i]>'9')
							break;
					//決定這個數值有幾個bit		
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
