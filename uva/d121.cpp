#include <iostream>

using namespace std;

/*
�إ߽�ƪ�(prime_talbe)�ðʺA���t�@��int�Ŷ�(prime)�s����
�̫�A��prime������ƹ�input����]�Ƥ��� 
�������~�ڭ̤��ξ��prime������Ƥ�����

ex  �H334142����
    334142����Ʀ�2�A�ҥH334142/2 = 167071
    ���U��1~46341����Ƥ��S����ƥi�H�A�㰣167071�A�ҥH167071����� 
*/ 

int main()
{
	char*prime_table = new char[46341];  //��ƪ� 
	int*prime = new int[20000];          //�ΨӦs��1~46340�d�򤺪���� 
	int prime_num = 0;                   //�ΨӬ���1~46340�����X�ӽ�� 
	int i,j,k;
	int n,positive;   //n�s��ݽ�]�Ƥ��Ѫ��Ʀr�Bpositive�h�O��n�O�����٬O�t�� 
	int first;        //���ܼƬO�ΨӧP�_���ѥX�Ӫ���]�ƬO�_�A�Ĥ@�Ӧ�m 
	
	//�}�l�إ߽�ƪ�
	for(i=0;i<46341;i++)
		prime_table[i] = 1;
	prime_table[0] = 0;
	prime_table[1] = 0;
	for(i=2;i*i<46341;i++)
		if(prime_table[i])
			for(j=i*i;j<46341;j+=i)
				prime_table[j] = 0;
	//�إߦn��ƪ��i�H�}�l�䦳���ǼƦr�O���
	for(i=0;i<46341;i++)
		if(prime_table[i])
			prime[prime_num++] = i;
	
	while(cin>>n)
	{
		if(n == 0)
			break;
		else if(n < 0)
		{
			cout<<n<<" = -1";
			first = 0;    
			positive = 0;
			n = -n;
		}
		else if(n == 1)
			cout<<"1 = 1";
		else
		{
			cout<<n<<" = ";
			first = 1;
			positive = 1;
		}
		
		//�Q��prime�s�񪺽�ƨӹ�n����]�Ƥ��� 
		for(i=0;i<prime_num;i++)
		{
			if(n%prime[i] == 0)//�p�G�Ʀrn��Q���prime[i]�㰣�� 
			{
				//���_���Nn���Hprime[i]�A�ç�sn�A����n����A�Qprime[i]�㰣���� 
				while(1)
				{
					if(n%prime[i] == 0)
					{
						if(first)
						{
							first = 0;
							cout<<prime[i];
						}
						else
							cout<<" x "<<prime[i];
						
						n /= prime[i];
					}
					else
						break;
				}
			}
			if(n == 1)  //prime�s�񪺽�Ƥw�L�k�A��n����]�Ƥ��� 
				break;
		}	
		
		if(n != 1)  //�Y��]�Ƥ��Ѥ������A�h�ѤU���Ʀrn������� 
		{
			if(first)
				cout<<n;
			else
				cout<<" x "<<n;
		}
		cout<<endl;
		
	}
	delete [] prime_table;
	delete [] prime;
		
	return 0;	
}



