#include <iostream>
#include <stack>

//�Q��STL����stack���D 

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
			if(operation == 1)       //�R����stack���̳��ݤ����� 
				s.pop();
			else if(operation == 2)  //�L�Xstack���̳��ݤ��� 
				cout<<s.top()<<endl;
			else                     //�N��ƥ��stack�� 
			{
				cin>>input;
				s.push(input);
			}
		
		}
		//�̫�n�M��stack
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
