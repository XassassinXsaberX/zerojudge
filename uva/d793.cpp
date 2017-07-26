#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

/*
�Q�� Dijkstra�t��k��X���w�_�I����N���I���̵u���|
�䤤�|�Ψ�priority_queue 
*/ 

struct Point //���I 
{
	int row,col; //�N���I�Ҧb����m 
	int weight;  //�N��ӳ��I��weight 
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
			//�g�c�զ@��n�Cm�� 
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

int Dijkstra(int**maze,int m,int n) //�Q��Dijkstra�t��k��X�q(0,0)��(m-1,n-1)���̵u�Z�� 
{	// ���]�g�c��m�Cn�� 

	// ���ʺA�t�m�O���� 
	int **select = (int**)malloc(sizeof(int*)*m);           //�O�����I�O�_�w�Q���  
	Point **previous = (Point**)malloc(sizeof(Point*)*m);   //�����즹���I���̵u���|�ת��e�@�ӳ��I����
	int **distance = (int**)malloc(sizeof(int*)*m);         //�H(0,0)���_�I�A���L�I���̵u���|
	int *ptr1 = (int*)malloc(sizeof(int)*m*n);
	Point *ptr2 = (Point*)malloc(sizeof(Point)*m*n);
	int *ptr3 = (int*)malloc(sizeof(int)*m*n);
	
	int i,j,k;
	int ans;
	int top_row,top_col; // priority_queue���A�̳��ݪ��I��row��col 
	int select_num=1;    // �w��X�̵u���|���I(����I)���ӼơA�]��1�O�]���@�}�l�N���M�w�X(0,0) 
	priority_queue<Point,deque<Point>,greater<Point> > p;
	
	// �ʺA�t�m�O���� 
	for(i=0;i<m;i++,ptr1+=n,ptr2+=n,ptr3+=n)
	{
		select[i] = ptr1;
		previous[i] = ptr2;
		distance[i] = ptr3;
	}
	
	//���M�wselect���Ҧ�����
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			select[i][j] = 0; 
	select[0][0] = 1;       //�@�}�l���_�I(0,0)�O�]�w���w�Q����� 
	
	
	//�A�ӨM�wdistance���Ҧ�����
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			distance[i][j] = 100000000;
	distance[0][0] = maze[0][0]; //�_�I��_�I���Z�� 
	
	 
	previous[0][0].row = 0; //�_�I��_�I���̵u���|���A���]�e�@�Ӹ`�I�N�O�_�I 
	previous[0][0].col = 0;
	
	
	if(n>1) //�p�G�ϧΪ����>1�A�N��i�H�q���I(0,0)�V�k���� 
	{
		previous[0][1] = Point(0,0); 
		distance[0][1] = maze[0][0]+maze[0][1];
		p.push(Point(0,1,distance[0][1]));
	}
	
	if(m>1)  //�p�G�ϧΪ��C��<1�A�N��i�H�q���I(0,0)�V�U���� 
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
		select[top_row][top_col] = 1;                 // �b(top_row , top_col)�����I�Q����[�J�̵u���|��
		select_num++;                                 // �w���q(0,0)���L���I���̵u���|�ƥ�+1 
		if(select_num == n*m)  // �Y�w��ܤFn*m�ӳ��I�A�N����F�q(0,0)��Ҧ��I���̵u���| 
			break; 
		p.pop();
		
		//�M��ݤW��O�����i��X�{���u���| 
		if(top_row-1>=0 && distance[top_row][top_col]+maze[top_row-1][top_col]<distance[top_row-1][top_col] )
		{
			previous[top_row-1][top_col] = Point(top_row,top_col);  //�]�w��̵u���|�� (top_row-1 , top_col) ���e�@�I�� (top_row , top_col) 
			distance[top_row-1][top_col] = distance[top_row][top_col]+maze[top_row-1][top_col]; //��s�q(0,0)�� (top_row-1 , top_col)���̵u���|���� 
			p.push( Point(top_row-1,top_col,distance[top_row-1][top_col]) );
		}
		
		//�M��ݤW��O�����i��X�{���u���| 
		if(top_row+1<m && distance[top_row][top_col]+maze[top_row+1][top_col]<distance[top_row+1][top_col] )
		{
			previous[top_row+1][top_col] = Point(top_row,top_col);  //�]�w�̵u���|���� (top_row+1 , top_col) ���e�@�I�� (top_row , top_col) 
			distance[top_row+1][top_col] = distance[top_row][top_col]+maze[top_row+1][top_col]; //��s�q(0,0)�� (top_row+1 , top_col)���̵u���|���� 
			p.push( Point(top_row+1,top_col,distance[top_row+1][top_col]) );
		}
			
		//�M��ݥ���O�����i��X�{���u���| 
		if(top_col-1>=0 && distance[top_row][top_col]+maze[top_row][top_col-1]<distance[top_row][top_col-1] )
		{
			previous[top_row][top_col-1] = Point(top_row,top_col);  //�]�w�̵u���|���� (top_row , top_col-1) ���e�@�I�� (top_row , top_col) 
			distance[top_row][top_col-1] = distance[top_row][top_col]+maze[top_row][top_col-1]; //��s�q(0,0)�� (top_row , top_col-1)���̵u���|���� 
			p.push( Point(top_row,top_col-1,distance[top_row][top_col-1]) );
		}	
			
		//�M��ݥk��O�����i��X�{���u���| 
		if(top_col+1<n && distance[top_row][top_col]+maze[top_row][top_col+1]<distance[top_row][top_col+1] )
		{
			previous[top_row][top_col+1] = Point(top_row,top_col);  //�]�w�̵u���|���� (top_row , top_col+1) ���e�@�I�� (top_row , top_col) 
			distance[top_row][top_col+1] = distance[top_row][top_col]+maze[top_row][top_col+1]; //��s�q(0,0)�� (top_row , top_col-1)���̵u���|���� 
			p.push( Point(top_row,top_col+1,distance[top_row][top_col+1]) );
		}

	}	
	
	// �̫�Yprevious[i][j] = Point(i-1,j)�A�N��q(0,0)��(i,j)���̵u���|���A��(i,j)���e�@�Ӻ��I��(i-1,j) 
	
	
	ans = distance[m-1][n-1];
	free(select[0]);
	free(select);
	free(previous[0]);
	free(previous);
	free(distance[0]);
	free(distance);
	return ans;	
	
}











