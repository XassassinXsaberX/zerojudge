#include <stdio.h>
#include <stdlib.h>

/*
�Q��dfs�M���|�ӸѨM���D 
*/ 

void recursion(int sum,int n,int current_num,int stack[1000],int top,int*find);

int main()
{
	int n;
	int stack[1000];
	int i,j;
	int find;
	
	while(scanf("%d",&n)!=EOF)
	{
		if(n == 0)
			break;
		
		find = 0;
		recursion(0,n,1,stack,-1,&find);
		if(find == 0)
			printf("cheat!\n");
	}
	return 0;
}

void recursion(int sum,int n,int current_num,int stack[1000],int top,int *find)
{
	//sum�ΨӬ����ثe�ֿn��
	//n�N��ؼ�
	//current_num�N��ثe�ֶi����Ӽ�(�q1�B2�B3���_�ֶi)
	//stack�ΰ��|�s����
	//top�������|����
	//find�ΨӬ����O�_�����i�઺�զX 
	int i,j,k;
	int current_sum;
	if(sum == n)
	{
		*find = 1;
		//�L�X���|�������e 
		for(i=0;i<=top;i++)
		{
			if(stack[i] == 0)
				printf(" + ");
			else if(stack[i] == -1)
				printf(" * ");
			else
				printf("%d",stack[i]);
		}
		printf("\n");
	}
	else if(sum > n)
		return ;
	else
	{
		if(current_num >= 2)
			stack[++top] = 0;         //�N��N'+'��J���|��
			 
		stack[++top] = current_num;   //�Ncurrent_num��J���|�� 
		sum += current_num;
		
		recursion(sum,n,current_num+1,stack,top,find);
		
		while(1)
		{
			// �P�_�O�_��N'*','2'��J���|�� 
			if(sum*2>n)
				break;
				
			stack[++top] = -1;         //�N��N'*'��J���|��
			stack[++top] = 2;
			sum *= 2;
			recursion(sum,n,current_num+1,stack,top,find);
		}
		
		
		
	}
	
	
	
	
}



