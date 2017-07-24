#include <iostream>
#include <set>

using namespace std;

/*ノmultiset甧竟ㄓ秆∕拜肈*/

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
			m.insert(input);  //穝糤计栋い  
			iter = m.begin(); //iterノㄓ栋いい丁计璝栋いΤ计计玥iterい计璝栋いΤ案计计玥iterㄢい丁计い耕计 
			count++;          //countノㄓ魁栋いΤ碭计 
			cout<<*iter<<endl;
		}
		else
		{
			m.insert(input); //穝糤计栋い 
			count++;         //countノㄓ魁ヘ玡栋いΤ碭计 
			if(count%2==1)   //璝ヘ玡栋いΤ计计 
			{
				if(input >= *iter)
					cout<<*iter<<endl;
				else
				{
					iter--;
					cout<<*iter<<endl;
				}
				//iter穦栋いい计 
			}
			else//璝ヘ玡栋いΤ案计计
			{
				//穦Τㄢ计い丁iterㄢ计い耕计 
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
