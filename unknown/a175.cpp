#include <iostream>
#include <vector>
#include <set>
#include <stdio.h>

using namespace std;

/*
�Q��vector<set<int> >�e������hash table
�o��hash table��hash function�� mod m�A�ҥHhash table�|��m��bucket
�䤤�C��bucket���e�q���L����slot
�������~���F�[�t�C��bucket���U�Ӥ������j�M�t�סA�ڭ̥ΤFset<int>�ӹ갵�C��bucket 
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
			if(oper == 1)//�n���J�@�ӭȨ�hash table��  (�N�ȩ���(value%m)��bucket��) 
			{
				cin>>value;
				hash[value%m].insert(value);
			}
			else if(oper == 2)//�n�qhash table���R���@�ӭ�  (�q(value%m)��bucket���R����) 
			{
				cin>>value;
				iter = hash[value%m].find(value);
				if(iter != hash[value%m].end()) //�Y�ӭȯu���bhash table��
					hash[value%m].erase(iter);  //�N��ӭȱqhash table�R�� 			 
					
			} 
			else //�L�Xhash table���Ҧ����e 
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
