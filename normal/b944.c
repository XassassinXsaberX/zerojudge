#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	int a,b;
	int Number[21],Time[21];
	int i,j,k;
	int find;
	int position;
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		Number[i] = 0;
		Time[i] = 0;
	}
	
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			if(Time[i] > 0)
			{
				Time[i] -= 1;
				if(Time[i] == 0)
					Number[i] = 0;	
			}
			else if(Time[i] == 0)
				Number[i] = 0;
			
		}
		
		//�M��O�_���Ŧ�
		//���j�M��_���j�ƬO�_����m
		find = 0;
		for(i=0;i<n;i++)
		{
			if(i==0 && Time[i] == 0 && Time[i+1] == 0) //�̳��ݪ���m 
			{
				find = 1;
				position = i;
				break;
			} 
			else if(i==n-1 && Time[i] == 0 && Time[i-1] == 0) //�̩��ݪ���m 
			{
				find = 1;
				position = i;
				break;
			}
			else if(Time[i] == 0 && i>0 && i<n-1 && Time[i-1] == 0 && Time[i+1] == 0)
			{
				find = 1;
				position = i;
				break;
			}
		}
		
		//�̫�@���M��O�_���Ŧ� 
		if(find == 0)
		{
			for(i=0;i<n;i++)
			{
				if(Time[i] == 0)
				{
					find = 1;
					position = i;
					break;
				}
			}
		}
		
		if(find == 0)
			printf("  Not enough\n");
		else
		{
			Number[position] = a;
			Time[position] = b;
		}
		printf("Number: ");
		for(i=0;i<n;i++)
			printf("%d ",Number[i]);
		printf("\n");
		printf("  Time: ");
		for(i=0;i<n;i++)
			printf("%d ",Time[i]);
		printf("\n\n");
		
		
	}
	return 0;
	
}












