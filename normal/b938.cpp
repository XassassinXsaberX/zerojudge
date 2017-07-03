#include <iostream>
#include <set>

/*利用STL的set容器解決資料結構問題*/

using namespace std;

int main()
{
	set<int> node;
	set<int>::iterator iter,iter2;
	int n,m;
	int input;
	int fail;
	int i,j,k;
	while(cin>>n>>m)
	{
		for(i=1;i<=n;i++)
			node.insert(i);
		for(i=0;i<m;i++)
		{
			cin>>input;
			iter = node.find(input);
			if(iter == node.end())
				cout<<"0u0 ...... ?"<<endl;
			else
			{
				iter++;
				if(iter == node.end())
					cout<<"0u0 ...... ?"<<endl;
				else
				{
					cout<<*iter<<endl;
					node.erase(iter);
				}
				
				
			}
			
		}
		node.clear();  //清空set容器 
		
	}
	return 0;
}
