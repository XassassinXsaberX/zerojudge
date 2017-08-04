#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <deque>

using namespace std;

/*常見的bfs練習*/ 

int bfs(int m,int n,vector<vector<char> > map,int start_row,int start_col,int end_row,int end_col);

struct Node
{
	int row,col;
	Node(int i,int j):row(i),col(j)
	{}
};

int main()
{
	int T;
	int M,N;
	vector<vector<char> > map;
	char s[1000];
	int start_row,start_col,end_row,end_col;
	int i,j,k;
	int ans;
	
	while(cin>>T)
	{
		for(k=0;k<T;k++)
		{
			cin>>M>>N;
			map.clear();
			for(i=0;i<M;i++)
				map.push_back(vector<char>(N));
				
			//開始建立地圖 
			for(i=0;i<M;i++)
			{
				cin>>s;
				for(j=0;j<N;j++)
				{
					map[i][j] = s[j];
					//找出起點位置 
					if(map[i][j] == 'A')
					{
						start_row = i;
						start_col = j;
					}
					//找出終點位置 
					else if(map[i][j] == 'B')
					{
						end_row = i;
						end_col = j;
					}
				}
					
			}
			
			ans = bfs(M,N,map,start_row,start_col,end_row,end_col); //進行bfs搜尋 
			

			if(ans == 0)
				cout<<"King Peter, you can't go now!"<<endl;
			else
				cout<<"Minimal possible length of a trip is "<<ans<<endl;
		
		}
	
	}
	return 0;
	

}

int bfs(int m,int n,vector<vector<char> > map,int start_row,int start_col,int end_row,int end_col)
{
	int pass[m][n];   //用來紀錄哪些點已經走過了。若為-1代表該點會被攻擊，不能走、若為0代表尚未經過、若>0代表經過幾步可以到達此點 
	int i,j,k;
	int row_operation[9] = {-1,-1,-1,0,0,0,1,1,1}; //紀錄之後要進行的row方向的動作 
	int col_operation[9] = {-1,0,1,-1,0,1,-1,0,1}; //紀錄之後要進行的col方向的動作 
	
	//利用queue來完成bfs 
	deque<Node> q;
	q.push_back(Node(start_row,start_col));
	
	//先初始化pass 
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			pass[i][j] = 0;
	
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
		{
			if(map[i][j] == 'Z')
			{
				pass[i][j] = -1; //代表該點不能走 
				if(i-1 >= 0 && j-2 >= 0 && map[i-1][j-2] == '.')
					pass[i-1][j-2] = -1;
				if(i-2 >= 0 && j-1 >= 0 && map[i-2][j-1] == '.')
					pass[i-2][j-1] = -1;
				if(i-2 >= 0 && j+1 < n && map[i-2][j+1] == '.')
					pass[i-2][j+1] = -1;
				if(i-1 >= 0 && j+2 < n && map[i-1][j+2] == '.')
					pass[i-1][j+2] = -1;
				if(i+1 < m && j-2 >= 0 && map[i+1][j-2] == '.')
					pass[i+1][j-2] = -1;
				if(i+2 < m && j-1 >= 0 && map[i+2][j-1] == '.')
					pass[i+2][j-1] = -1;
				if(i+1 < m && j+2 < n && map[i+1][j+2] == '.')
					pass[i+1][j+2] = -1;
				if(i+2 < m && j+1 < n && map[i+2][j+1] == '.')
					pass[i+2][j+1] = -1;
				
			}
		}
		
	//以下為bfs演算法 
	while(1)
	{
		if(q.size()==0)  //當queue沒有元素時就跳出 
			break;
		for(i=0;i<9;i++) //判斷國王的九個方向是否能進行移動 
		{
			//判斷國王的九個方向是否能進行移動 
			if(q.begin()->row + row_operation[i] >= 0 && q.begin()->row + row_operation[i] < m && q.begin()->col + col_operation[i] >= 0 && q.begin()->col + col_operation[i] < n\
			   && pass[q.begin()->row+row_operation[i]][q.begin()->col+col_operation[i]] == 0 && map[q.begin()->row+row_operation[i]][q.begin()->col+col_operation[i]] != 'A') 
			{
				//如果能進行移動，就將下一個點丟到queue中 
				pass[q.begin()->row + row_operation[i]][q.begin()->col + col_operation[i]] = pass[q.begin()->row][q.begin()->col] + 1;
				if(map[q.begin()->row + row_operation[i]][q.begin()->col + col_operation[i]]=='B')      //若該點為終點B 
					return pass[q.begin()->row + row_operation[i]][q.begin()->col + col_operation[i]];  //就回傳走了多少步才到終點 
				
				q.push_back( Node(q.begin()->row + row_operation[i], q.begin()->col + col_operation[i]) );
		   	}
		
		}
		q.pop_front(); //pop最頂端的元素 
			
	}
	
	return 0;
	
}


