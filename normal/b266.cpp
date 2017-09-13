#include <iostream>

/*�Q�Ϊ���ɦV���g�k�����}�C�B��*/ 

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
			// ���ʺA���t�@�ӤG���}�C 
			new_matrix = new int*[new_row];
			for(i=0;i<new_row;i++)
				new_matrix[i] = new int[new_col];
				
			for(i=0;i<new_col;i++)
				for(j=0;j<new_row;j++)
					new_matrix[j][i] = matrix[row-1-i][j];
			
			// �N�쥻�ʺA���t���G���}�C ����
			for(i=0;i<row;i++)
				delete [] matrix[i];
			delete [] matrix;
			
			// �̫�վ�@�U���󤤪���Ʀ��� 
			matrix = new_matrix;
			row = new_row;
			col = new_col; 
		}
		
		void r_rotation()
		{
			int i,j,k;
			int **new_matrix;
			int new_row = col , new_col = row;
			// ���ʺA���t�@�ӤG���}�C 
			new_matrix = new int*[new_row];
			for(i=0;i<new_row;i++)
				new_matrix[i] = new int[new_col];
				
			for(i=0;i<new_col;i++)
				for(j=0;j<new_row;j++)
					new_matrix[j][i] = matrix[i][col-1-j];
			
			// �N�쥻�ʺA���t���G���}�C ����
			for(i=0;i<row;i++)
				delete [] matrix[i];
			delete [] matrix;
			
			// �̫�վ�@�U���󤤪���Ʀ��� 
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
		Matrix m(R,C); //�إߤ@�ӯx�}����
		
		//���U�ӿ�J�x�}���� 
		for(i=0;i<R;i++)
			for(j=0;j<C;j++)
				cin>>m.matrix[i][j];
		
		//���U�ӿ�J�@�g�L���ǹB�� 
		for(i=0;i<M;i++)
			cin>>operation[i];
		
		//�i��ϹB�� 
		for(i=M-1;i>=0;i--)
		{
			if(operation[i] == 0)
				m.r_rotation();
			else
				m.r_inverse();
		}
		
		//�̫��X���G 
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
