#include <iostream>
#include <map>

/*利用STL的map container來解決搜尋問題*/

using namespace std;

int main()
{
	int n,k;
	int i,j;
	map<int,int> m;
	map<int,int>::iterator iter;
	int value;
	while(cin>>n>>k)
	{
		for(i=0;i<n;i++)
		{
			cin>>value;
			m.insert(pair<int,int>(value,i+1));
		}
		for(i=0;i<k;i++)
		{
			cin>>value;
			iter = m.find(value);
			if(iter == m.end())
				cout<<"0"<<endl;
			else
				cout<<iter->second<<endl;
		}
		m.clear();
	}
	return 0;
}
