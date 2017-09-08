#include <stdio.h>
#include <stdlib.h>

/*
Euler圖形一筆畫問題
可參考維基百科  https://zh.wikipedia.org/wiki/%E4%B8%80%E7%AC%94%E7%94%BB%E9%97%AE%E9%A2%98 
*/

int main()
{
	int degree[10000];  //degree[i]代表節點i的分支度(degree) 
	int i,j,k;
	int n,m;
	int node1,node2;
	int odd;           //紀錄有多少個節點分支度為奇數 
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		for(i=0;i<=n;i++)
			degree[i] = 0;
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&node1,&node2);
			degree[node1]++;
			degree[node2]++; 
		}
		
		//統計分支度為奇數的節點有幾個 
		odd = 0;
		for(i=1;i<=n;i++)
		{
			if(degree[i]%2==1)
				odd++;
			if(odd > 2)
				break;
		}
		
		//若分度為奇數的節點個數為0或2個，則圖形可一筆畫連接 
		if(odd == 0 || odd == 2)
			printf("YES\n");
		else
			printf("NO\n"); 
		
	}
	return 0;
	
}
