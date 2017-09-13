#include <iostream>

/*利用物件導向的寫法完成陣列運算*/ 

using namespace std;

class Matrix
{
	private:
		
		
	public:
		int row,col;
		int **matrix;
		Matrix(int a=0,int b=0):row(a),col(b)
		{
			int i,j;
			matrix = new int*[row];
			for(i=0;i<row;i++)
				matrix[i] = new int[col];
		}
		void inverse()
		{
			int i,j;
			int tmp;
			for(i=0;i<col;i++)
				for(j=0;j<row/2;j++)
				{
					tmp = matrix[j][i];
					matrix[j][i] = matrix[row-1-j][i];
					matrix[row-1-j][i] = tmp;
				}			
		}
		void r_inverse()
		{
			int i,j;
			int tmp;
			for(i=0;i<col;i++)
				for(j=0;j<row/2;j++)
				{
					tmp = matrix[j][i];
					matrix[j][i] = matrix[row-1-j][i];
					matrix[row-1-j][i] = tmp;
				}	
		}
		
		void rotation()
		{
			int i,j,k;
			int **new_matrix;
			int new_row = col , new_col = row;
			// 先動態分配一個二維陣列 
			new_matrix = new int*[new_row];
			for(i=0;i<new_row;i++)
				new_matrix[i] = new int[new_col];
				
			for(i=0;i<new_col;i++)
				for(j=0;j<new_row;j++)
					new_matrix[j][i] = matrix[row-1-i][j];
			
			// 將原本動態分配的二維陣列 釋放掉
			for(i=0;i<row;i++)
				delete [] matrix[i];
			delete [] matrix;
			
			// 最後調整一下物件中的資料成員 
			matrix = new_matrix;
			row = new_row;
			col = new_col; 
		}
		
		void r_rotation()
		{
			int i,j,k;
			int **new_matrix;
			int new_row = col , new_col = row;
			// 先動態分配一個二維陣列 
			new_matrix = new int*[new_row];
			for(i=0;i<new_row;i++)
				new_matrix[i] = new int[new_col];
				
			for(i=0;i<new_col;i++)
				for(j=0;j<new_row;j++)
					new_matrix[j][i] = matrix[i][col-1-j];
			
			// 將原本動態分配的二維陣列 釋放掉
			for(i=0;i<row;i++)
				delete [] matrix[i];
			delete [] matrix;
			
			// 最後調整一下物件中的資料成員 
			matrix = new_matrix;
			row = new_row;
			col = new_col; 
		}
		
};

int main()
{
	int R,C,M;
	int i,j,k;
	int operation[10];
	
	while(cin>>R>>C>>M)
	{
		Matrix m(R,C); //建立一個矩陣物件
		
		//接下來輸入矩陣元素 
		for(i=0;i<R;i++)
			for(j=0;j<C;j++)
				cin>>m.matrix[i][j];
		
		//接下來輸入共經過哪些運算 
		for(i=0;i<M;i++)
			cin>>operation[i];
		
		//進行反運算 
		for(i=M-1;i>=0;i--)
		{
			if(operation[i] == 0)
				m.r_rotation();
			else
				m.r_inverse();
		}
		
		//最後輸出結果 
		cout<<m.row<<" "<<m.col<<endl;
		for(i=0;i<m.row;i++)
		{
			for(j=0;j<m.col;j++)
				cout<<m.matrix[i][j]<<" ";
			cout<<endl;
		}
			
	}
	
	return 0;
}
