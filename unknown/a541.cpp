#include <iostream>
#include <map>
#include <string>

/*利用STL的map容器處理資料結構的問題*/

using namespace std;

int main()
{
	int n;
	string str;
	map<string,int> dict;
	map<string,int>::iterator iter;
	int i,j,k;
	
	
	while(cin>>n)
	{
		for(i=0;i<n;i++)
		{
			cin >> str;
			dict.insert(pair<string,int>(str,1));
		}
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin >> str;
			iter = dict.find(str);
			
			if(iter == dict.end())
			{
				cout<<"no"<<endl;
				dict.insert(pair<string,int>(str,1));
			}
			else
				cout<<"yes"<<endl;
			
			/*
			// another solution
			if(dict[str] == 1)
				cout<<"yes"<<endl;
			else
			{
				cout<<"no"<<endl;
				dict[str] = 1;
			}
			*/
		}
		dict.clear();
	}
	return 0;
}
