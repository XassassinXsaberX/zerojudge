#include <iostream>
#include <set>

using namespace std;

/*�Q��multiset�e���ӸѨM���D*/

int main()
{
	long long int input;
	multiset<int> m;
	multiset<int>::iterator iter,iter2;
	int i,j;
	int count=0;
	
	while(cin>>input)
	{
		if(m.size()==0)
		{
			m.insert(input);  //�s�W�@�Ӽƨ춰�X��  
			iter = m.begin(); //iter�Ψӫ��V���X���������ơA�Y���X�����_�ƭӼơA�hiter���V����ơA�Y���X�������ƭӼơA�hiter���V�⤤���Ƥ����᭱���� 
			count++;          //count�ΨӬ������X�����X�Ӽ� 
			cout<<*iter<<endl;
		}
		else
		{
			m.insert(input); //�s�W�@�Ӽƨ춰�X�� 
			count++;         //count�ΨӬ����ثe���X�����X�Ӽ� 
			if(count%2==1)   //�Y�ثe���X�����_�ƭӼ� 
			{
				if(input >= *iter)
					cout<<*iter<<endl;
				else
				{
					iter--;
					cout<<*iter<<endl;
				}
				//����iter�|���V���X��������� 
			}
			else//�Y�ثe���X�������ƭӼ�
			{
				//���ɷ|����ӼƦb�����Aiter����V��Ƥ����᭱���� 
				if(input >= *iter)  
				{
					iter2 = iter;
					iter++;
					cout<<(int)( (*iter + (*iter2))/2 )<<endl;
				}
				else
				{
					iter2 = --iter;
					iter++;
					cout<<(int)( (*iter + (*iter2))/2 )<<endl;
				}
					
					
			}
		}
		
	}
	return 0;
	
}
