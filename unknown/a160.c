#include <stdio.h>
#include <stdlib.h>

/*�Q�λ��j�ӧ���DFS�A�èD�ѤK�ӦZ���D*/

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
		for(i=0;i<N;i++)//i�N��ĴX�� 
		{
			arr[current_row][i] = 'Q'; 
			dfs(N,current_row+1,arr,count); 
			arr[current_row][i] = 'x'; 
		}
	}
	else
	{
		int fail; 
		for(i=0;i<N;i++) //i�N��ĴX�� 
		{
			fail = 0; 
			//�Y�n�b��current_row�C�B��i�檺��m��W'Q'�A�o���P��o�@��O�_�S��'Q'
			for(j=current_row-1;j>=0;j--)
			{
				if(arr[j][i]=='Q')
				{
					fail = 1;
					break; 
				}	
			}
			if(fail == 0) //�p�G�o�@�泣�S��'Q'�A�٭n�P�_�L���﨤�u�O�_��'Q' 
			{
				
				//�P�_���W�����﨤�u��V�O�_��'Q'
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
						
							
				//�P�_�k�W�誺�﨤�u��u�O�_��'Q'
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
					
									
				
				// �﨤�u�]���T�S��'Q'�A�ڭ̤~�i�H�u���N'Q'��b����m		
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
		// ���ʺA�t�m�G���}�C 
		arr = (char**)malloc(sizeof(char*)*N);
		ptr = (char*)malloc(sizeof(char)*N*N);
		for(i=0;i<N;i++,ptr+=N)
			arr[i] = ptr;
			
		// �N�G���}�C���Ҧ����������q��x
		for(i=0;i<N;i++)
			for(j=0;j<N;j++)
				arr[i][j] = 'x';
		
		//�Q�λ��j��X�Ҧ��i���(dfs)
		count = 0;
		dfs(N,0,arr,&count);
		printf("%d\n\n",count);
			
		
		free(arr[0]);
		free(arr);
		
	}
	return 0;
	
}
