#include <iostream>
#include <set>

/*�Q��STL��set�e���ѨM��Ƶ��c���D*/

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
		node.clear();  //�M��set�e�� 
		
	}
	return 0;
}
