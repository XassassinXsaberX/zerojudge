#include <iostream>
#include <map>

using namespace std;

/*�Q��map�e�������j�M���D*/

int main()
{
	int n;
	int i,j;
	int input;
	map<int,int> m;
	map<int,int>::iterator iter;
	
	while(cin>>n)
	{
		for(i=0;i<n;i++)
		{
			cin>>input;
			iter = m.find(input); //�M��input�O�_�bmap�� 
			if(iter == m.end())   //�Y�S�����ܡA�N�N�o��key = input , value = 1����ƥ[�J��map����
				m.insert(pair<int,int>(input,1));
			else
				iter->second++;   //�Y�����ܡA�Nkey = input ����ơA��value�ȥ[1 	
		}
		
		//�L�Xmap�e�������Ҧ���� 
		for(iter=m.begin();iter!=m.end();iter++)
			cout<<iter->first<<" "<<iter->second<<endl; 
		m.clear();
	}
	return 0;
	
}
