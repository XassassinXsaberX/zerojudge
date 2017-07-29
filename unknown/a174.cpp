#include <iostream>
#include <vector>
#include <list>
#include <stdio.h>

/*
利用vector<list<int> >容器做的hash table
這個hash table的hash function為 mod m，所以hash table會有m個bucket
其中每個bucket的容量為無限個slot(所以會用list<int>來實做) 
*/

using namespace std;

int main()
{
	int k,m;
	int oper;
	int value;
	int i,j;
	vector<list<int> > hash;
	list<int>::iterator iter;
	
	while(cin>>k>>m)
	{
		for(i=0;i<m;i++)
			hash.push_back(list<int>());
		for(i=0;i<k;i++)
		{
			cin>>oper;
			if(oper == 1)//要插入一個值到hash table中 
			{
				cin>>value;
				//接下來要將這筆資料丟到hash[value % m]中，也就是丟到第(value%m)個bucket中 
				for(iter=hash[value%m].begin();;iter++)
				{
					if(iter == hash[value%m].end() || value < *iter) //若hash table的第(value%m)個bucket中沒有這筆資料就要進行添加資料的動作 
					{
						hash[value%m].insert(iter,value);
						break;
					}
					else if(*iter == value)  //若hash table中已有這筆資料，就不進行添加資料的動作 
						break;
				}			
				
			}
			else if(oper == 2)//要從hash table中刪除一個值
			{
				cin>>value;
				//從第(value%m)個bucket中，看看是否有這個資料 
				for(iter=hash[value%m].begin();iter!=hash[value%m].end();iter++)
				{
					if(*iter == value) //在hash table的第(value%m)個bucket中找到資料 
					{
						hash[value%m].erase(iter);
						break;
					}
					else if(*iter > value) //在hash table中找不到資料 
						break;
				}	
			} 
			else  //印出hash table的內容 
			{
				cout<<"===== s ====="<<endl;
				for(j=0;j<hash.size();j++)
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
