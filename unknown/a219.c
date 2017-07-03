#include <stdio.h>
#include <stdlib.h>

/*��������@�I�����j���D*/

void dfs(int N,int current,int position[15][15],char*record,char*previous_record,char*current_record);
void Strcpy(char*s1,const char*s2);

int main()
{
	int N;
	int position[15][15]; //�ΨӬ����ĴX�ӤH�����Ǧ�m�L���Q��
	int dont;
	char current_record[16],previous_record[16]; //�ΨӬ����ثe�ѥX�Ϋe�@�ӿ�X 
	char record[15];      //�ΨӬ�����i�H�O�_���b��m�W�F 
	int i,j,k;
	while(scanf("%d",&N)!=EOF)
	{
		for(i=0;i<N;i++)
			for(j=0;j<N;j++)
				position[i][j] = 1;//�@�}�l���]�C�ӤH���Ҧ���m���i�H��
				
		for(i=0;i<N;i++)
			record[i] = 0;      //�@�}�l���]�Ҧ��H���S���b��m�W 
		
		for(i=0;i<N;i++)
		{	
			for(j=0;;j++)
			{
				scanf("%d",&dont);
				position[i][dont-1] = 0;//�N���i�H���వ����m
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
			//�P�_�o�ӤH�O�_�w�g���b��m�W�F
			if(record[i] == 1)
				continue;
			
			//�n�P�_��i�ӤH�O�_�i�H���bcurrent+1�o�Ӧ�m
			if(position[i][current] == 0)
				continue;
	
			
			current_record[current] = i+'A';
			current_record[current+1] = '\0';
			record[i] = 1; //��i�ӤH���b��m�W 
			dfs(N,current+1,position,record,previous_record,current_record);
			record[i] = 0; //��i�ӤH���}��m�W 
		
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



