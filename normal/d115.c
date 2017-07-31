#include <stdio.h>
#include <stdlib.h>

/*練習qsort排序+遞迴的問題*/ 

int cmp(const void*,const void*);
void recursion(int current,int count,int n,int m,int*arr,int*ans);

int main()
{
	int n,m;
	int*arr;
	int*ans;
	int i,j,k;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		arr = (int*)malloc(sizeof(int)*n);
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);
		scanf("%d",&m);
		ans = (int*)malloc(sizeof(int)*m);
		
		qsort(arr,n,sizeof(int),cmp);//對arr陣列進行快速排序 (從小排到大)
		
		recursion(0,0,n,m,arr,ans);
			
		
		free(arr);
		free(ans);
	}
	return 0;
}

int cmp(const void*a,const void*b)
{
	int*a1 = (int*)a;
	int*b1 = (int*)b;
	if(*a1<*b1)
		return -1;
	else if(*a1==*b1)
		return 0;
	else
		return 1;
}

void recursion(int current,int count,int n,int m,int*arr,int*ans)
{
	//current紀錄目前遞迴到arr的哪個位置
	//count紀錄目前ans收集到幾個元素
	//arr陣列有n個元素
	//ans陣列需要收集m個元素 
	int i,j,k;
	
	if(current == n && count < m )
	//如果目前已超過arr陣列的範圍 
		return ;//就跳出遞迴 
	
	//如果目前收集到的元素已經有m個 
	if(count == m)
	{
		for(i=0;i<m;i++)
			printf("%d ",ans[i]);
		printf("\n");
	}
	//否則就繼續遞迴 
	else
	{
		for(i=current;i<n-(m-count-1);i++)
		{
			ans[count] = arr[i];
			recursion(i+1,count+1,n,m,arr,ans);
		}
	}
	
	
}









