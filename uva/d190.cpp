#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

/*�ϥ�vector�e�� + STL����sort�禡�ӳB�z�}�C�Ƨ�*/

using namespace std;

int cmp(const void*a,const void*b);

int main()
{
	int n;
	vector<int> arr;
	int i,j,k;
	int input;
	while(cin>>n)
	{
		if(n==0)
			break;
		for(i=0;i<n;i++)
		{
			cin>>input;
			arr.push_back(input);
		}	
		sort(arr.begin(),arr.end(),less<int>());
		for(i=0;i<n;i++)
			cout<<arr[i]<<" ";
		cout<<endl;
		arr.clear();
	}
	return 0;
}


