#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

/*利用物件導向的程式設計方法來處理物件的排序問題*/

using namespace std;

class Node
{
	public:
		int *arr;
		int len;	
		
		Node(int i=0):len(i) //定義建構函式 
		{
			if(i<=0)
				arr = NULL;
			else if(i>0)
				arr = new int[i];
				
		}
		
		Node(const Node&n1) //定義複製建構函式，因為該類別的資料成員中有用指標指向的空間，所以一定要定義複製建構函式
		{
			
			int i;
			this->len = n1.len;
			this->arr = new int[n1.len];
			for(i=0;i<n1.len;i++)
				this->arr[i] = n1.arr[i];
		}
		
		~Node()       	  	//定義解構函式，因為該類別的資料成員中有用動態分配的記憶體空間，所以一定要定義解構函式來回收這些記憶體空間 
		{
			delete [] this->arr;
		}
		
		
		void set_size(int M) //定意該類別的成員函數，該成員函數的功用是設定資料成員的記憶體空間 
		{
			
			delete [] this->arr;
			this->arr = new int[M];
			this->len = M;
		}
		
		bool operator==(const Node&n1) const //覆載比較運算子(==)，請定義成常數成員函式，否則在使用less<Node>()函式物件時會出問題 
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
		bool operator>(const Node&n1) const //覆載比較運算子(>)，請定義成常數成員函式，否則在使用less<Node>()函式物件時會出問題 
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
		bool operator<(const Node&n1) const //覆載比較運算子(<)，請定義成常數成員函式，否則在使用less<Node>()函式物件時會出問題 
		{
			if(*this > n1 || *this == n1)
				return false;
			else
				return true;
		}
		
		bool operator = (const Node&n1)  //覆載指定運算子(=)，因為該類別的資料成員中有用指標指向的空間，所以一定要覆載指定運算子 
		{
			delete [] this->arr;
			this->arr = new int[n1.len];
			for(int i=0;i<n1.len;i++)
				this->arr[i] = n1.arr[i];
		}
		
		
		friend ostream& operator<< (ostream&,const Node&);
};

ostream& operator<< (ostream&out,const Node&node) //定義輸出的運算子 
{
	int i;
	for(i=0;i<node.len;i++)
		out<<node.arr[i]<<" ";
	return out;
}

bool small(const Node&a,const Node&b) // 定義比較函數 
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

struct cmp //定義函式物件(functor class) 
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
		//亦可寫成
		//sort(node.begin(),node.end(),cmp());  //利用函式物件 
		//sort(node.begin(),node.end(),small);  //利用函式指標 
		for(iter=node.begin();iter!=node.end();iter++)
		{
			cout<<*iter<<endl;
		}
		node.clear();
		
	}
	return 0;

}











