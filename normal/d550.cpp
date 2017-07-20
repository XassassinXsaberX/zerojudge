#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

/*�Q�Ϊ���ɦV���{���]�p��k�ӳB�z���󪺱Ƨǰ��D*/

using namespace std;

class Node
{
	public:
		int *arr;
		int len;	
		
		Node(int i=0):len(i) //�w�q�غc�禡 
		{
			if(i<=0)
				arr = NULL;
			else if(i>0)
				arr = new int[i];
				
		}
		
		Node(const Node&n1) //�w�q�ƻs�غc�禡�A�]�������O����Ʀ��������Ϋ��Ы��V���Ŷ��A�ҥH�@�w�n�w�q�ƻs�غc�禡
		{
			
			int i;
			this->len = n1.len;
			this->arr = new int[n1.len];
			for(i=0;i<n1.len;i++)
				this->arr[i] = n1.arr[i];
		}
		
		~Node()       	  	//�w�q�Ѻc�禡�A�]�������O����Ʀ��������ΰʺA���t���O����Ŷ��A�ҥH�@�w�n�w�q�Ѻc�禡�Ӧ^���o�ǰO����Ŷ� 
		{
			delete [] this->arr;
		}
		
		
		void set_size(int M) //�w�N�����O��������ơA�Ӧ�����ƪ��\�άO�]�w��Ʀ������O����Ŷ� 
		{
			
			delete [] this->arr;
			this->arr = new int[M];
			this->len = M;
		}
		
		bool operator==(const Node&n1) const //�и�����B��l(==)�A�Щw�q���`�Ʀ����禡�A�_�h�b�ϥ�less<Node>()�禡����ɷ|�X���D 
		{
			int find=0;
			int i;
			for(i=0;i<n1.len;i++)
			{
				if(this->arr[i]!=n1.arr[i])
					return false;
			}
			return true;
		}
		bool operator>(const Node&n1) const //�и�����B��l(>)�A�Щw�q���`�Ʀ����禡�A�_�h�b�ϥ�less<Node>()�禡����ɷ|�X���D 
		{
			int find = 0;
			int i;
			for(i=0;i<n1.len;i++)
			{
				if(this->arr[i] < n1.arr[i])
					return false;
				else if(this->arr[i] > n1.arr[i])
					return true;
			}
			return false;
		}
		bool operator<(const Node&n1) const //�и�����B��l(<)�A�Щw�q���`�Ʀ����禡�A�_�h�b�ϥ�less<Node>()�禡����ɷ|�X���D 
		{
			if(*this > n1 || *this == n1)
				return false;
			else
				return true;
		}
		
		bool operator = (const Node&n1)  //�и����w�B��l(=)�A�]�������O����Ʀ��������Ϋ��Ы��V���Ŷ��A�ҥH�@�w�n�и����w�B��l 
		{
			delete [] this->arr;
			this->arr = new int[n1.len];
			for(int i=0;i<n1.len;i++)
				this->arr[i] = n1.arr[i];
		}
		
		
		friend ostream& operator<< (ostream&,const Node&);
};

ostream& operator<< (ostream&out,const Node&node) //�w�q��X���B��l 
{
	int i;
	for(i=0;i<node.len;i++)
		out<<node.arr[i]<<" ";
	return out;
}

bool small(const Node&a,const Node&b) // �w�q������ 
{
	int i;
	for(i=0;i<a.len;i++)
	{
		if(a.arr[i]<b.arr[i])
			return true;
		else if(a.arr[i]>b.arr[i])
			return false;
	}
}

struct cmp //�w�q�禡����(functor class) 
{
	bool operator()(const Node&a,const Node&b) 
	{
		int i;
		for(i=0;i<a.len;i++)
		{
			if(a.arr[i]<b.arr[i])
				return true;
			else if(a.arr[i]>b.arr[i])
				return false;
		}
	}
};

int main()
{
	vector<Node> node;
	vector<Node>::iterator iter;
	int N,M;
	int i,j,k;
	while(cin>>N>>M)
	{	
		for(i=0;i<N;i++)
		{
			node.push_back(Node());
			node[i].set_size(M);
			for(j=0;j<M;j++)
				cin>>node[i].arr[j];
		}
		
		sort(node.begin(),node.end(),less<Node>()); 
		//��i�g��
		//sort(node.begin(),node.end(),cmp());  //�Q�Ψ禡���� 
		//sort(node.begin(),node.end(),small);  //�Q�Ψ禡���� 
		for(iter=node.begin();iter!=node.end();iter++)
		{
			cout<<*iter<<endl;
		}
		node.clear();
		
	}
	return 0;

}











