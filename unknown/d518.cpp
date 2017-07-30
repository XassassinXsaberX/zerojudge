#include <iostream>
#include <map>

using namespace std;

/*利用STL的map容器解決搜尋問題*/

int main()
{
	int i,j;
	int num;
	string s;
	map<string,int> m;
	map<string,int>::iterator iter;
	int count;
	
	while(cin>>num)
	{
		count = 0;
		for(i=0;i<num;i++)
		{
			cin>>s;
			iter = m.find(s);
			if(iter == m.end())//如果有搜尋到值 
			{
				count++;
				cout<<"New! "<<count<<endl;
				m.insert(pair<string,int>(s,count));
			}
			else//如果沒搜尋到值 
			{
				cout<<"Old! "<<iter->second<<endl;
			}
		}
		m.clear();
	}
	return 0;
}
