#include <stdio.h>
#include <stdlib.h>

/*比較複雜一點的遞迴問題*/

void dfs(int N,int current,int position[15][15],char*record,char*previous_record,char*current_record);
void Strcpy(char*s1,const char*s2);

int main()
{
	int N;
	int position[15][15]; //用來紀錄第幾個人有哪些位置他不想坐
	int dont;
	char current_record[16],previous_record[16]; //用來紀錄目前書出及前一個輸出 
	char record[15];      //用來紀錄第i人是否做在位置上了 
	int i,j,k;
	while(scanf("%d",&N)!=EOF)
	{
		for(i=0;i<N;i++)
			for(j=0;j<N;j++)
				position[i][j] = 1;//一開始假設每個人對於所有位置都可以做
				
		for(i=0;i<N;i++)
			record[i] = 0;      //一開始假設所有人都沒做在位置上 
		
		for(i=0;i<N;i++)
		{	
			for(j=0;;j++)
			{
				scanf("%d",&dont);
				position[i][dont-1] = 0;//代表第i人不能做此位置
				if(dont == 0)
					break;
			}
			
		}
		for(i=0;i<N;i++)
		{
			previous_record[i] = '\0';
			current_record[i] = '\0';
		}
			
			
		dfs(N,0,position,record,current_record,previous_record);
	}
	
	return 0;
}

void dfs(int N,int current,int position[15][15],char*record,char*previous_record,char*current_record)
{
	int ok;
	int i,j,k;
	if(current == N)
	{
		for(i=0;;i++)
		{
			if(current_record[i] == previous_record[i] && current_record[i] != '\0')
				continue;
			else if(current_record[i] == '\0')
			{
				printf("\n");
				break;
			}
			else
				printf("%c",current_record[i]);
			
		}
		Strcpy(previous_record,current_record);
	}
	else
	{
		for(i=0;i<N;i++)
		{
			//判斷這個人是否已經做在位置上了
			if(record[i] == 1)
				continue;
			
			//要判斷第i個人是否可以做在current+1這個位置
			if(position[i][current] == 0)
				continue;
	
			
			current_record[current] = i+'A';
			current_record[current+1] = '\0';
			record[i] = 1; //第i個人坐在位置上 
			dfs(N,current+1,position,record,previous_record,current_record);
			record[i] = 0; //第i個人離開位置上 
		
		}
	}
}

void Strcpy(char*s1,const char*s2)
{
	int i,j;
	for(i=0;;i++)
	{
		s1[i] = s2[i];
		if(s1[i] == '\0')
			break;
	}
}



