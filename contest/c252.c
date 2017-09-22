#include <stdio.h>
#include <stdlib.h>

/*²�檺dfs���D*/

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
		
		//�ʺA���t�G���}�C 
		map = (int**)malloc(sizeof(int*)*row);
		for(i=0;i<row;i++)
			map[i] = (int*)malloc(sizeof(int)*col);	
		
		//�إ߹ϧ� 
		for(i=0;i<row;i++)
		{
			scanf("%s",str);
			for(j=0;j<col;j++)
				map[i][j] = str[j] - '0';
		}
		//�A�ӧQ��dfs�έp���X�ӳ̤j�F�v���X�Ӭ��t(�O��LO)
		//�òέp���X�ӬF�v(��count����)
		LO = 0;
		count = 0; 
		for(i=0;i<row;i++)
			for(j=0;j<col;j++)
			{
				if(map[i][j]>0)
				{
					count++;
					tmp = 1; //tmp�ΨӬ����o�ӬF�v���X�Ӭ��t 
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
	//map�N��a�ϰ}�C
	//party�N����Ӭ��t(ex party=2 �N���t2) 
	//row�Bcol�N��a�Ϫ�row�Bcol 
	//num�ΨӬ����o�ӬF�v�����X�Ӭ��t (ex *num=3�N��o�ӬF�v��3�Ӭ��t2) 
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
			map[current_row+oper_row[i]][current_col+oper_col[i]] = -1;  //�N���I�w�g�g�L�F 
			dfs(map,party,row,col,current_row+oper_row[i],current_col+oper_col[i],num);			
			
		} 
	
	}
}






