#include <iostream>
#include <algorithm>
#include <map>

/*�Q��STL��map��@hash table�ӸѨM���D*/

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
			sort(arr,arr+5); //��arr�������Ƨ� 
			
			// ���p�Ƨǧ���arr�������ܬ� 100 200 300 400 500
			// �ڭ̧�o5�Ӿ�Ƭݦ��@�Ӥj��� 100200300400500
			// �æbhash table���� 100200300400500 index���O����+1
			//
			//
			// ex1.
			// ���] n = 3�A��3�ӱƧǫ᪺�}�C�Ȧp�U 
			// 100 101 102 103 488  ��index�� 100101102103488 
			// 100 101 102 200 300  ��index�� 100101102200300 
			// 100 101 102 103 488  ��index�� 100101102103488
			// �ҥHhash table��
			// ------------------------------
			// index                    value(�H��) 
			// ------------------------------
			// 100101102103488            1
			// 100101102200300            2
			// ------------------------------
			// �ҥHvalue�ȳ̤j��2 (�u���@�Ӭ�����value�Ȭ�2�A�N��u���@�ӽҵ{���̨��w��ҵ{�զX) 
			// �ҥH�̨��w��ҵ{�զX���`�H�Ƭ� 2x1=2 
			//
			//
			//
			// ex2.
			// ���] n = 3�A��3�ӱƧǫ᪺�}�C�Ȧp�U 
			// 200 202 204 206 208  ��index�� 200202204206208 
			// 123 234 321 345 456  ��index�� 123234321345456
			// 100 200 300 400 444  ��index�� 100200300400444
			// �ҥHhash table��
			// ------------------------------
			// index                    value(�H��) 
			// ------------------------------
			// 100200300400444            1
			// 123234321345456            1
			// 200202204206208            1
			// ------------------------------
			// �ҥHvalue�̤j�Ȭ�1 (��3�Ӭ�����value�Ȭ�1�A�N��3�ӽҵ{���O�̨��w��ҵ{�զX)
			// �`�ҥH�̨��w��ҵ{�զX���`�H�Ƭ� 1x3=3 
			
			
			
			
			index = 0;
			tmp = 1;
			//������Xindex 
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
		
		//���ۦbhash table��X�̤j�������� 
		max_value = 0;   //hash table���̤j�������� 
		count = 0;       //hash table����count���O���A������ȷ|����̤j������ 
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
