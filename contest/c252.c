#include <stdio.h>
#include <stdlib.h>

/*簡單的dfs問題*/

void dfs(int **map,int party,int row,int col,int current_row,int current_col,int*num);

int main()
{
	int row,col;
	int**map;
	int*ptr;
	char str[102];
	int i,j,k;
	int party;
	int LO,count,tmp;
	while(scanf("%d %d",&row,&col)!=EOF)
	{
		if(row == 0 && col == 0)
			break;
		
		//動態分配二維陣列 
		map = (int**)malloc(sizeof(int*)*row);
		for(i=0;i<row;i++)
			map[i] = (int*)malloc(sizeof(int)*col);	
		
		//建立圖形 
		for(i=0;i<row;i++)
		{
			scanf("%s",str);
			for(j=0;j<col;j++)
				map[i][j] = str[j] - '0';
		}
		//再來利用dfs統計有幾個最大政權有幾個派系(記為LO)
		//並統計有幾個政權(用count紀錄)
		LO = 0;
		count = 0; 
		for(i=0;i<row;i++)
			for(j=0;j<col;j++)
			{
				if(map[i][j]>0)
				{
					count++;
					tmp = 1; //tmp用來紀錄這個政權有幾個派系 
					party = map[i][j];
					map[i][j] = -1;
					dfs(map,party,row,col,i,j,&tmp);
					if(tmp > LO)
						LO = tmp;
				} 
			} 
		if(count > LO)
			printf("choas\n");
		else
			printf("peace\n");
		
		
		
		for(i=0;i<row;i++)
			free(map[i]);
		free(map);
		
	}
	
	
	return 0;

}

void dfs(int **map,int party,int row,int col,int current_row,int current_col,int*num)
{
	//map代表地圖陣列
	//party代表哪個派系(ex party=2 代表派系2) 
	//row、col代表地圖的row、col 
	//num用來紀錄這個政權中有幾個派系 (ex *num=3代表這個政權有3個派系2) 
	int oper_row[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
	int oper_col[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
	int i,j,k;
	
	for(i=0;i<8;i++)
	{
		if(current_row+oper_row[i]>=0 && current_row+oper_row[i]<row &&
		   current_col+oper_col[i]>=0 && current_col+oper_col[i]<col &&
		   map[current_row+oper_row[i]][current_col+oper_col[i]] == party)
		{
			(*num)++;
			map[current_row+oper_row[i]][current_col+oper_col[i]] = -1;  //代表此點已經經過了 
			dfs(map,party,row,col,current_row+oper_row[i],current_col+oper_col[i],num);			
			
		} 
	
	}
}






