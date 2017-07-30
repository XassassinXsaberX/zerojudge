#include <iostream>
#include <map>

using namespace std;

/*利用map容器完成搜尋問題*/

int main()
{
	int n;
	int i,j;
	int input;
	map<int,int> m;
	map<int,int>::iterator iter;
	
	while(cin>>n)
	{
		for(i=0;i<n;i++)
		{
			cin>>input;
			iter = m.find(input); //尋找input是否在map中 
			if(iter == m.end())   //若沒有的話，就將這筆key = input , value = 1的資料加入到map物件中
				m.insert(pair<int,int>(input,1));
			else
				iter->second++;   //若有的話，將key = input 的資料，其value值加1 	
		}
		
		//印出map容器中的所有資料 
		for(iter=m.begin();iter!=m.end();iter++)
			cout<<iter->first<<" "<<iter->second<<endl; 
		m.clear();
	}
	return 0;
	
}
