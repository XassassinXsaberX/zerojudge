#include <iostream>
#include <algorithm>
#include <map>

/*利用STL的map實作hash table來解決問題*/

using namespace std;

int main()
{
	int n;
	int i,j,k;
	map<long long int,int> MAP;
	map<long long int,int>::iterator iter;
	int arr[5];
	long long int tmp,index;
	int max_value; 
	int count;
	
	while(cin>>n)
	{
		if(n == 0)
			break;
			
			
		for(i=0;i<n;i++)
		{
			for(j=0;j<5;j++)
				cin>>arr[j]; 
			sort(arr,arr+5); //對arr的元素排序 
			
			// 假如排序完後arr的元素變為 100 200 300 400 500
			// 我們把這5個整數看成一個大整數 100200300400500
			// 並在hash table的第 100200300400500 index中記錄值+1
			//
			//
			// ex1.
			// 假設 n = 3，其3個排序後的陣列值如下 
			// 100 101 102 103 488  其index為 100101102103488 
			// 100 101 102 200 300  其index為 100101102200300 
			// 100 101 102 103 488  其index為 100101102103488
			// 所以hash table為
			// ------------------------------
			// index                    value(人數) 
			// ------------------------------
			// 100101102103488            1
			// 100101102200300            2
			// ------------------------------
			// 所以value值最大為2 (只有一個紀錄的value值為2，代表只有一個課程為最受歡迎課程組合) 
			// 所以最受歡迎課程組合的總人數為 2x1=2 
			//
			//
			//
			// ex2.
			// 假設 n = 3，其3個排序後的陣列值如下 
			// 200 202 204 206 208  其index為 200202204206208 
			// 123 234 321 345 456  其index為 123234321345456
			// 100 200 300 400 444  其index為 100200300400444
			// 所以hash table為
			// ------------------------------
			// index                    value(人數) 
			// ------------------------------
			// 100200300400444            1
			// 123234321345456            1
			// 200202204206208            1
			// ------------------------------
			// 所以value最大值為1 (有3個紀錄的value值為1，代表3個課程都是最受歡迎課程組合)
			// 總所以最受歡迎課程組合的總人數為 1x3=3 
			
			
			
			
			index = 0;
			tmp = 1;
			//首先找出index 
			for(j=4;j>=0;j--)
			{
				index += arr[j]*tmp;
				tmp *= 1000;
			}
			
			iter = MAP.find(index);
			if(iter == MAP.end())
				MAP.insert(pair<long long int,int>(index,1));
			else
				iter->second += 1; 
			
		}
		
		//接著在hash table找出最大的紀錄值 
		max_value = 0;   //hash table中最大的紀錄值 
		count = 0;       //hash table中有count筆記錄，其紀錄值會等於最大紀錄值 
		for(iter = MAP.begin();iter != MAP.end();iter++)
		{
			if(iter->second > max_value)
			{
				max_value = iter->second;
				count = max_value;
			} 
			else if(iter->second == max_value)
				count += max_value;
		}
		cout<<count<<endl;
		MAP.clear(); 
		
	}
	return 0;
}
