#include <iostream>
#include <stack>

//利用STL完成stack問題 

using namespace std;

int main()
{
	stack<int> s;
	
	int n;
	int i,j,k;
	int operation,input;
	while(cin>>n)
	{
		for(i=0;i<n;i++)
		{
			cin>>operation;
			if(operation == 1)       //刪除元stack中最頂端元素素 
				s.pop();
			else if(operation == 2)  //印出stack中最頂端元素 
				cout<<s.top()<<endl;
			else                     //將資料丟到stack中 
			{
				cin>>input;
				s.push(input);
			}
		
		}
		//最後要清空stack
		while(1)
		{
			if(s.size() == 0)
				break;
			else
				s.pop(); 
		} 
	}
	return 0;
}
