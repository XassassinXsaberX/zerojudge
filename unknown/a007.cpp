#include <iostream>

/*建立質數表，並判斷是否為質數的好題目*/

using namespace std;

int main()
{
	int *prime_table = new int[50000]; //質數表 
	int *prime,prime_number = 0;
	int i,j,k;
	int n;
	int success;
	prime = new int[25000]; //用來存放質數
	for(i=0;i<50000;i++)
		prime_table[i] = 1;
	prime_table[0] = 0;
	prime_table[1] = 0;
	for(i=2;i*i<50000;i++)
		if(prime_table[i] == 1)
			for(j=i*i;j<50000;j+=i)
				prime_table[j] = 0;
	//以上就是質數表的建立步驟
	//接下來從質數表中找出質數並把它存在prime指標指到的空間中
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
			cout<<"質數"<<endl;
		else
			cout<<"非質數"<<endl;
	}
	return 0;

}
