#include <iostream>

/*�إ߽�ƪ�A�çP�_�O�_����ƪ��n�D��*/

using namespace std;

int main()
{
	int *prime_table = new int[50000]; //��ƪ� 
	int *prime,prime_number = 0;
	int i,j,k;
	int n;
	int success;
	prime = new int[25000]; //�ΨӦs����
	for(i=0;i<50000;i++)
		prime_table[i] = 1;
	prime_table[0] = 0;
	prime_table[1] = 0;
	for(i=2;i*i<50000;i++)
		if(prime_table[i] == 1)
			for(j=i*i;j<50000;j+=i)
				prime_table[j] = 0;
	//�H�W�N�O��ƪ��إߨB�J
	//���U�ӱq��ƪ���X��ƨç⥦�s�bprime���Ы��쪺�Ŷ���
	for(i=0;i<50000;i++)
	{
		if(prime_table[i] == 1)
			prime[prime_number++] = i;
	} 
	
	while(cin>>n)
	{
		success = 1;
		for(i=0;i<prime_number;i++)
		{
			if(n%prime[i] == 0 && n!=prime[i])
			{
				success = 0;
				break;
			}
			else if(n<prime[i])
				break;
		}
		if(success == 1)
			cout<<"���"<<endl;
		else
			cout<<"�D���"<<endl;
	}
	return 0;

}
