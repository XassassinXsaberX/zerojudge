#include <iostream>
#include <vector>
#include <set>
#include <stdio.h>

using namespace std;

/*
利用vector<set<int> >容器做的hash table
這個hash table的hash function為 mod m，所以hash table會有m個bucket
其中每個bucket的容量為無限個slot
除此之外為了加速每個bucket中各個元素的搜尋速度，我們用了set<int>來實做每個bucket 
*/


int main()
{
	int k,m;
	int oper;
	int value;
	int i,j;
	vector<set<int> > hash;
	set<int>::iterator iter;
	
	while(cin>>k>>m)
	{
		for(i=0;i<m;i++)
			hash.push_back(set<int>());
		for(i=0;i<k;i++)
		{
			cin>>oper;
			if(oper == 1)//要插入一個值到hash table中  (將值放到第(value%m)個bucket中) 
			{
				cin>>value;
				hash[value%m].insert(value);
			}
			else if(oper == 2)//要從hash table中刪除一個值  (從(value%m)個bucket中刪除值) 
			{
				cin>>value;
				iter = hash[value%m].find(value);
				if(iter != hash[value%m].end()) //若該值真的在hash table中
					hash[value%m].erase(iter);  //就把該值從hash table刪除 			 
					
			} 
			else //印出hash table的所有內容 
			{
				cout<<"===== s ====="<<endl;
				for(j=0;j<m;j++)
				{
					printf("[%03d]:",j);
					for(iter=hash[j].begin();iter!=hash[j].end();iter++)
					{
						cout<<*iter<<" -> ";
					}
					cout<<"NULL"<<endl;
				}
				cout<<"===== e ====="<<endl;
			}
		}
		hash.clear();
	}
	return 0;
}
