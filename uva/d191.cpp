#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <deque>

using namespace std;

/*�`����bfs�m��*/ 

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
				
			//�}�l�إߦa�� 
			for(i=0;i<M;i++)
			{
				cin>>s;
				for(j=0;j<N;j++)
				{
					map[i][j] = s[j];
					//��X�_�I��m 
					if(map[i][j] == 'A')
					{
						start_row = i;
						start_col = j;
					}
					//��X���I��m 
					else if(map[i][j] == 'B')
					{
						end_row = i;
						end_col = j;
					}
				}
					
			}
			
			ans = bfs(M,N,map,start_row,start_col,end_row,end_col); //�i��bfs�j�M 
			

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
	int pass[m][n];   //�ΨӬ��������I�w�g���L�F�C�Y��-1�N����I�|�Q�����A���ਫ�B�Y��0�N��|���g�L�B�Y>0�N��g�L�X�B�i�H��F���I 
	int i,j,k;
	int row_operation[9] = {-1,-1,-1,0,0,0,1,1,1}; //��������n�i�檺row��V���ʧ@ 
	int col_operation[9] = {-1,0,1,-1,0,1,-1,0,1}; //��������n�i�檺col��V���ʧ@ 
	
	//�Q��queue�ӧ���bfs 
	deque<Node> q;
	q.push_back(Node(start_row,start_col));
	
	//����l��pass 
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			pass[i][j] = 0;
	
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
		{
			if(map[i][j] == 'Z')
			{
				pass[i][j] = -1; //�N����I���ਫ 
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
		
	//�H�U��bfs�t��k 
	while(1)
	{
		if(q.size()==0)  //��queue�S�������ɴN���X 
			break;
		for(i=0;i<9;i++) //�P�_������E�Ӥ�V�O�_��i�沾�� 
		{
			//�P�_������E�Ӥ�V�O�_��i�沾�� 
			if(q.begin()->row + row_operation[i] >= 0 && q.begin()->row + row_operation[i] < m && q.begin()->col + col_operation[i] >= 0 && q.begin()->col + col_operation[i] < n\
			   && pass[q.begin()->row+row_operation[i]][q.begin()->col+col_operation[i]] == 0 && map[q.begin()->row+row_operation[i]][q.begin()->col+col_operation[i]] != 'A') 
			{
				//�p�G��i�沾�ʡA�N�N�U�@���I���queue�� 
				pass[q.begin()->row + row_operation[i]][q.begin()->col + col_operation[i]] = pass[q.begin()->row][q.begin()->col] + 1;
				if(map[q.begin()->row + row_operation[i]][q.begin()->col + col_operation[i]]=='B')      //�Y���I�����IB 
					return pass[q.begin()->row + row_operation[i]][q.begin()->col + col_operation[i]];  //�N�^�Ǩ��F�h�֨B�~����I 
				
				q.push_back( Node(q.begin()->row + row_operation[i], q.begin()->col + col_operation[i]) );
		   	}
		
		}
		q.pop_front(); //pop�̳��ݪ����� 
			
	}
	
	return 0;
	
}


