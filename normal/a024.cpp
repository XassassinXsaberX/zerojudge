#include <iostream>

using namespace std;

// 利用遞迴來解決gcd最大公因式問題 

int gcd(int,int);

int main()
{
	int a,b;
	while(cin>>a>>b)
	{
		cout<<gcd(a,b)<<endl;
	}
	return 0;
}

int gcd(int a,int b)
{
	int c;
	if(a%b == 0)
		return b;
	else
		return gcd(b,a%b);
}
