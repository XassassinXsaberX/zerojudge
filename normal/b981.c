#include <stdio.h>
#include <stdlib.h>

/*簡單的迴圈、if else控制問題、及字串處理*/

int main()
{
	char str[100];
	char*ptr;
	int i,j,k;
	int sum; //紀錄時間總合 
	int time,time2; //time2定義為小數點時間 
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
				//從字串中讀取時間 
				sscanf(str+i,"%d",&time);
				//接下來字串要跳到最後一個數字 
				for(j=i;;j++)
					if(str[j]<'0' || str[j]>'9')
						break;
				i = j - 1;
			}
			else if(str[i]=='.') //如果有小數點時間 
			{
				i++;
				sscanf(str+i,"%d",&time2);
				//接下來字串要跳到最後一個數字 
				for(j=i;;j++)
					if(str[j]<'0' || str[j]>'9')
						break;
				i = j - 1;
			}
			else
			{
				//從字串中讀取時間單位 
				if(str[i]=='h')
					sum += time * 60 * 60 * 1000;
				else if( (str[i]=='m' && str[i+1]!='s') || (str[i]=='m' && str[i+1]=='i') ) 
					sum += time * 60 * 1000;
				else if(str[i] == 's')
					sum += time * 1000 + time2 * 100;
				else 
					sum += time;
				//要跳到時間單位字母(英文)的最後一個字母
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













