#include <iostream>
#include <map>

using namespace std;

/*�Q��STL��map�e���ѨM�j�M���D*/

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
			if(iter == m.end())//�p�G���j�M��� 
			{
				count++;
				cout<<"New! "<<count<<endl;
				m.insert(pair<string,int>(s,count));
			}
			else//�p�G�S�j�M��� 
			{
				cout<<"Old! "<<iter->second<<endl;
			}
		}
		m.clear();
	}
	return 0;
}
