#include <stdio.h>
#include <stdlib.h>

/*利用遞迴來找出所有可能的組合問題*/

void recursion(int current,int last,int use[15],int num,int N);

int main()
{
	int T,N;
	int arr[15];
	int use[15];
	int i,j,k;
	
	while(scanf("%d",&T)!=EOF)
	{
		for(i=0;i<T;i++)
		{
			scanf("%d",&N);
			
			//初始化use陣列
			for(j=0;j<N;j++) 
				use[j] = 0;
				
			for(j=0;j<=N;j++)
				recursion(0,0,use,j,N);
		}
	
	
	}
	return 0;
}

void recursion(int current,int last,int use[15],int num,int N)
{
	//current代表目前收集到多少數字
	//last紀錄集合中最後一筆數字 
	//use紀錄哪些數字被使用(use[i] == 1 代表數字i+1被使用)
	//num代表要選取多少個數字 
	//N代表總共有多少數字 
	int i,j,k;
	int first_number = 1; //用來決定是否為第一個出現的數字 
	if(num==0)
		printf("{0}\n");
	
	else if(current == num)
	{
		printf("{");
		for(i=0;i<N;i++)
		{
			if(use[i]==1 && first_number==1)
			{	
				printf("%d",i+1);
				first_number = 0;
			}
			else if(use[i]==1 && first_number==0)
			{
				printf(",%d",i+1);
			}
		}
		printf("}\n");
	}
	else
	{
		for(i=last;i+(num-current)-1<N;i++)
		{
			if(use[i]==0)
			{
				use[i] = 1;//將這個數字丟到集合中 ，所以代表被使用了 
				recursion(current+1,i+1,use,num,N);
				use[i] = 0;
			}
		}
	}
}













