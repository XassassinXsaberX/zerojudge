#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

/*
利用 Dijkstra演算法找出指定起點到任意終點的最短路徑
其中會用到priority_queue 
*/ 

struct Point //頂點 
{
	int row,col; //代表頂點所在的位置 
	int weight;  //代表該頂點的weight 
	Point(int r=0,int c=0,int w=0):row(r),col(c),weight(w)
	{}
	
	bool operator>(const Point&p) const
	{
		if(this->weight>p.weight)
			return true;
		else
			return false;
	}
	bool operator==(const Point&p) const
	{
		if(this->weight == p.weight)
			return true;
		else
			return false;
	}
	bool operator<(const Point&p) const
	{
		if(this->weight < p.weight)
			return true;
		else
			return false;
	}
};

int Dijkstra(int**maze,int m,int n);

int main()
{
	int num;
	int n,m;
	int**maze;
	int*ptr;
	int i,j,k;
	int ans;
	while(scanf("%d",&num)!=EOF)
	{
		for(i=0;i<num;i++)
		{
			scanf("%d",&n);
			scanf("%d",&m);
			//迷宮組共有n列m行 
			maze = (int**)malloc(sizeof(int**)*n);
			ptr = (int*)malloc(sizeof(int*)*n*m);
			for(j=0;j<n;j++,ptr+=m)
				maze[j] = ptr;
			
			for(j=0;j<n;j++)
				for(k=0;k<m;k++)
					scanf("%d",&maze[j][k]);
					
			ans = Dijkstra(maze,n,m);
			cout<<ans<<endl;
				
				
			free(maze[0]);
			free(maze);
			
		}
	}
	return 0;
}

int Dijkstra(int**maze,int m,int n) //利用Dijkstra演算法找出從(0,0)到(m-1,n-1)的最短距離 
{	// 假設迷宮有m列n行 

	// 先動態配置記憶體 
	int **select = (int**)malloc(sizeof(int*)*m);           //記錄該點是否已被選取  
	Point **previous = (Point**)malloc(sizeof(Point*)*m);   //紀錄到此端點的最短路徑終的前一個頂點為何
	int **distance = (int**)malloc(sizeof(int*)*m);         //以(0,0)為起點，到其他點的最短路徑
	int *ptr1 = (int*)malloc(sizeof(int)*m*n);
	Point *ptr2 = (Point*)malloc(sizeof(Point)*m*n);
	int *ptr3 = (int*)malloc(sizeof(int)*m*n);
	
	int i,j,k;
	int ans;
	int top_row,top_col; // priority_queue中，最頂端的點的row及col 
	int select_num=1;    // 已找出最短路徑的點(選擇點)的個數，設為1是因為一開始就有決定出(0,0) 
	priority_queue<Point,deque<Point>,greater<Point> > p;
	
	// 動態配置記憶體 
	for(i=0;i<m;i++,ptr1+=n,ptr2+=n,ptr3+=n)
	{
		select[i] = ptr1;
		previous[i] = ptr2;
		distance[i] = ptr3;
	}
	
	//先決定select的所有元素
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			select[i][j] = 0; 
	select[0][0] = 1;       //一開始頂起點(0,0)是設定成已被選取的 
	
	
	//再來決定distance的所有元素
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			distance[i][j] = 100000000;
	distance[0][0] = maze[0][0]; //起點到起點的距離 
	
	 
	previous[0][0].row = 0; //起點到起點的最短路徑中，假設前一個節點就是起點 
	previous[0][0].col = 0;
	
	
	if(n>1) //如果圖形的行數>1，代表可以從頂點(0,0)向右移動 
	{
		previous[0][1] = Point(0,0); 
		distance[0][1] = maze[0][0]+maze[0][1];
		p.push(Point(0,1,distance[0][1]));
	}
	
	if(m>1)  //如果圖形的列數<1，代表可以從頂點(0,0)向下移動 
	{
		previous[1][0] = Point(0,0);
		distance[1][0] = maze[0][0]+maze[1][0];
		p.push(Point(1,0,distance[1][0]));
	}
	
	
	
	while(1)
	{
		if(p.size()==0)
			break;
		top_row = p.top().row;
		top_col = p.top().col;
		select[top_row][top_col] = 1;                 // 在(top_row , top_col)的端點被選取加入最短路徑中
		select_num++;                                 // 已找到從(0,0)到其他頂點的最短路徑數目+1 
		if(select_num == n*m)  // 若已選擇了n*m個頂點，代表找到了從(0,0)到所有點的最短路徑 
			break; 
		p.pop();
		
		//尋找看上方是有有可能出現較短路徑 
		if(top_row-1>=0 && distance[top_row][top_col]+maze[top_row-1][top_col]<distance[top_row-1][top_col] )
		{
			previous[top_row-1][top_col] = Point(top_row,top_col);  //設定到最短路徑中 (top_row-1 , top_col) 的前一點為 (top_row , top_col) 
			distance[top_row-1][top_col] = distance[top_row][top_col]+maze[top_row-1][top_col]; //更新從(0,0)到 (top_row-1 , top_col)的最短路徑長度 
			p.push( Point(top_row-1,top_col,distance[top_row-1][top_col]) );
		}
		
		//尋找看上方是有有可能出現較短路徑 
		if(top_row+1<m && distance[top_row][top_col]+maze[top_row+1][top_col]<distance[top_row+1][top_col] )
		{
			previous[top_row+1][top_col] = Point(top_row,top_col);  //設定最短路徑中到 (top_row+1 , top_col) 的前一點為 (top_row , top_col) 
			distance[top_row+1][top_col] = distance[top_row][top_col]+maze[top_row+1][top_col]; //更新從(0,0)到 (top_row+1 , top_col)的最短路徑長度 
			p.push( Point(top_row+1,top_col,distance[top_row+1][top_col]) );
		}
			
		//尋找看左方是有有可能出現較短路徑 
		if(top_col-1>=0 && distance[top_row][top_col]+maze[top_row][top_col-1]<distance[top_row][top_col-1] )
		{
			previous[top_row][top_col-1] = Point(top_row,top_col);  //設定最短路徑中到 (top_row , top_col-1) 的前一點為 (top_row , top_col) 
			distance[top_row][top_col-1] = distance[top_row][top_col]+maze[top_row][top_col-1]; //更新從(0,0)到 (top_row , top_col-1)的最短路徑長度 
			p.push( Point(top_row,top_col-1,distance[top_row][top_col-1]) );
		}	
			
		//尋找看右方是有有可能出現較短路徑 
		if(top_col+1<n && distance[top_row][top_col]+maze[top_row][top_col+1]<distance[top_row][top_col+1] )
		{
			previous[top_row][top_col+1] = Point(top_row,top_col);  //設定最短路徑中到 (top_row , top_col+1) 的前一點為 (top_row , top_col) 
			distance[top_row][top_col+1] = distance[top_row][top_col]+maze[top_row][top_col+1]; //更新從(0,0)到 (top_row , top_col-1)的最短路徑長度 
			p.push( Point(top_row,top_col+1,distance[top_row][top_col+1]) );
		}

	}	
	
	// 最後若previous[i][j] = Point(i-1,j)，代表從(0,0)到(i,j)的最短路徑中，到(i,j)的前一個端點為(i-1,j) 
	
	
	ans = distance[m-1][n-1];
	free(select[0]);
	free(select);
	free(previous[0]);
	free(previous);
	free(distance[0]);
	free(distance);
	return ans;	
	
}











