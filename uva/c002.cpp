#include <iostream>

using namespace std;

/*��²�檺���j�m��*/

int f91(int n);

int main()
{	
	int N;
	while(cin>>N)
	{
		if(N==0)
			break;
		else
			cout<<"f91("<<N<<") = "<<f91(N)<<endl;
	}
	return 0;
}

int f91(int N)
{
	if(N>=101)
		return N-10;
	else
		return f91(f91(N+11));
}
