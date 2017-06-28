#include <stdio.h>
#include <stdlib.h>

/*利用遞迴來完成DFS，並求解八皇后問題*/

void dfs(int N,int current_row,char**arr,int*count)
{
	int i,j,k;
	if(current_row == N)
	{
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
				printf("%c",arr[i][j]);
			printf("\n");
		}
		printf("\n");
		*count = *count+1; 
	}
	else if(current_row == 0)
	{
		for(i=0;i<N;i++)//i代表第幾行 
		{
			arr[current_row][i] = 'Q'; 
			dfs(N,current_row+1,arr,count); 
			arr[current_row][i] = 'x'; 
		}
	}
	else
	{
		int fail; 
		for(i=0;i<N;i++) //i代表第幾行 
		{
			fail = 0; 
			//若要在第current_row列、第i行的位置放上'Q'，得先判對這一行是否沒有'Q'
			for(j=current_row-1;j>=0;j--)
			{
				if(arr[j][i]=='Q')
				{
					fail = 1;
					break; 
				}	
			}
			if(fail == 0) //如果這一行都沒有'Q'，還要判斷他的對角線是否有'Q' 
			{
				
				//判斷左上角的對角線方向是否有'Q'
				k = i-1;
				for(j=current_row-1;j>=0;j--)
				{
					if(k<0)
						break;
					if(arr[j][k]=='Q')
					{
						fail = 1;
						break;
					}		
					k--;
				}
						
							
				//判斷右上方的對角線方線是否有'Q'
				k = i+1;
				for(j=current_row-1;j>=0;j--)
				{
					if(k>=N)
						break;
					if(arr[j][k]=='Q')
					{
						fail = 1;
						break;
					}
					k++;
				}
					
									
				
				// 對角線也的確沒有'Q'，我們才可以真的將'Q'放在此位置		
				if(fail == 0)
				{ 
					arr[current_row][i] = 'Q';
					dfs(N,current_row+1,arr,count);
					arr[current_row][i] = 'x';
				} 
			}
			
		} 
	} 
}


int main()
{
	int N;
	char **arr;
	char *ptr;
	int i,j,k;
	int count;
	while(scanf("%d",&N)!=EOF)
	{
		if(N==0)
			break;
		// 先動態配置二維陣列 
		arr = (char**)malloc(sizeof(char*)*N);
		ptr = (char*)malloc(sizeof(char)*N*N);
		for(i=0;i<N;i++,ptr+=N)
			arr[i] = ptr;
			
		// 將二維陣列的所有元素全部訂為x
		for(i=0;i<N;i++)
			for(j=0;j<N;j++)
				arr[i][j] = 'x';
		
		//利用遞迴找出所有可能性(dfs)
		count = 0;
		dfs(N,0,arr,&count);
		printf("%d\n\n",count);
			
		
		free(arr[0]);
		free(arr);
		
	}
	return 0;
	
}
