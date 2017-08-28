#include <stdio.h>
#include <stdlib.h>

/*
利用dfs和堆疊來解決問題 
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
	//sum用來紀錄目前累積值
	//n代表目標
	//current_num代表目前累進到哪個數(從1、2、3不斷累進)
	//stack用堆疊存放資料
	//top紀錄堆疊頂端
	//find用來紀錄是否有找到可能的組合 
	int i,j,k;
	int current_sum;
	if(sum == n)
	{
		*find = 1;
		//印出堆疊中的內容 
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
			stack[++top] = 0;         //代表將'+'丟入堆疊中
			 
		stack[++top] = current_num;   //將current_num丟入堆疊中 
		sum += current_num;
		
		recursion(sum,n,current_num+1,stack,top,find);
		
		while(1)
		{
			// 判斷是否能將'*','2'丟入堆疊中 
			if(sum*2>n)
				break;
				
			stack[++top] = -1;         //代表將'*'丟入堆疊中
			stack[++top] = 2;
			sum *= 2;
			recursion(sum,n,current_num+1,stack,top,find);
		}
		
		
		
	}
	
	
	
	
}



