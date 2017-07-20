#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

/*使用vector容器 + STL中的sort函式來處理陣列排序*/

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


