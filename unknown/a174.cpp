#include <iostream>
#include <vector>
#include <list>
#include <stdio.h>

/*
�Q��vector<list<int> >�e������hash table
�o��hash table��hash function�� mod m�A�ҥHhash table�|��m��bucket
�䤤�C��bucket���e�q���L����slot(�ҥH�|��list<int>�ӹ갵) 
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
			if(oper == 1)//�n���J�@�ӭȨ�hash table�� 
			{
				cin>>value;
				//���U�ӭn�N�o����ƥ��hash[value % m]���A�]�N�O����(value%m)��bucket�� 
				for(iter=hash[value%m].begin();;iter++)
				{
					if(iter == hash[value%m].end() || value < *iter) //�Yhash table����(value%m)��bucket���S���o����ƴN�n�i��K�[��ƪ��ʧ@ 
					{
						hash[value%m].insert(iter,value);
						break;
					}
					else if(*iter == value)  //�Yhash table���w���o����ơA�N���i��K�[��ƪ��ʧ@ 
						break;
				}			
				
			}
			else if(oper == 2)//�n�qhash table���R���@�ӭ�
			{
				cin>>value;
				//�q��(value%m)��bucket���A�ݬݬO�_���o�Ӹ�� 
				for(iter=hash[value%m].begin();iter!=hash[value%m].end();iter++)
				{
					if(*iter == value) //�bhash table����(value%m)��bucket������� 
					{
						hash[value%m].erase(iter);
						break;
					}
					else if(*iter > value) //�bhash table���䤣���� 
						break;
				}	
			} 
			else  //�L�Xhash table�����e 
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
