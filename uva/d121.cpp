#include <iostream>

using namespace std;

/*
建立質數表(prime_talbe)並動態分配一個int空間(prime)存放質數
最後再用prime中的質數對input做質因數分解 
除此之外我們不用擔心prime中的質數不夠用

ex  以334142為例
    334142的質數有2，所以334142/2 = 167071
    接下來1~46341的質數中沒有質數可以再整除167071，所以167071為質數 
*/ 

int main()
{
	char*prime_table = new char[46341];  //質數表 
	int*prime = new int[20000];          //用來存放1~46340範圍內的質數 
	int prime_num = 0;                   //用來紀錄1~46340中有幾個質數 
	int i,j,k;
	int n,positive;   //n存放待質因數分解的數字、positive則記錄n是正數還是負數 
	int first;        //該變數是用來判斷分解出來的質因數是否再第一個位置 
	
	//開始建立質數表
	for(i=0;i<46341;i++)
		prime_table[i] = 1;
	prime_table[0] = 0;
	prime_table[1] = 0;
	for(i=2;i*i<46341;i++)
		if(prime_table[i])
			for(j=i*i;j<46341;j+=i)
				prime_table[j] = 0;
	//建立好質數表後可以開始找有哪些數字是質數
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
		
		//利用prime存放的質數來對n做質因數分解 
		for(i=0;i<prime_num;i++)
		{
			if(n%prime[i] == 0)//如果數字n能被質數prime[i]整除時 
			{
				//不斷的將n除以prime[i]，並更新n，直到n不能再被prime[i]整除為止 
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
			if(n == 1)  //prime存放的質數已無法再對n做質因數分解 
				break;
		}	
		
		if(n != 1)  //若質因數分解不完全，則剩下的數字n必為質數 
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



