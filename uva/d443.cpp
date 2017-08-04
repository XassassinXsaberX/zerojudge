#include <iostream>

using namespace std;

/*计笲衡(猭猭) + dp*/

class Int
{
	private:
		int arr[3000];  //ノㄓ计い计ㄤいarr[0]计arr[1]计.... 
		int digit;      //计Τ碭计
	
	public:
		Int(int input=0) //﹚竡篶ㄧΑ 
		{
			//盢input俱计锣Θ计Α 
			int i;
			if(input == 0)
				digit = 0;
			for(i=0;i<3000;i++)
			{
				arr[i] = input %10;
				input /= 10;
			}
			for(i=2999;i>=0;i--)
				if(arr[i]!=0)
				{
					digit = i+1;
					break;
				}			
		}
		
		Int operator+(const Int&i2) //﹚竡计猭 
		{
			Int c;
			int d;
			int i,j,k;
			//ㄓтт 砆计(*this)计(i2) 街计耕 
			if(i2.digit > (*this).digit)
				d = i2.digit;
			else
				d = (*this).digit;
				
			//钡ㄓ秨﹍秈︽计猭 
			for(i=0;i<d;i++)
			{
				c.arr[i] += (*this).arr[i] + i2.arr[i];
				if(c.arr[i]>9)
				{
					c.arr[i+1] += c.arr[i]/10;
					c.arr[i] %= 10;
				}
			}
			
			//程参璸计猭挡狦Τ碭计
			for(i=2999;i>=0;i--) 
				if(c.arr[i] != 0)
				{
					c.digit = i+1;
					break;
				}
			return c;
		}
		
		Int operator*(const Int&i2)  //﹚竡计猭 
		{
			Int c;
			int d;
			int i,j;
			//秈︽计猭 
			for(i=0;i<(*this).digit;i++)
				for(j=0;j<i2.digit;j++)
				{
					c.arr[i+j] += (*this).arr[i] * i2.arr[j];
					if(c.arr[i+j] > 9)
					{
						c.arr[i+j+1] += c.arr[i+j]/10;
						c.arr[i+j] %= 10;

					}
				}
			//程参璸计猭挡狦Τ碭计
			for(i=2999;i>=0;i--) 
				if(c.arr[i] != 0)
				{
					c.digit = i+1;
					break;
				}
				
			return c;
		}

		
		friend ostream& operator<<(ostream&,const Int&);
	 
};

ostream& operator<<(ostream&out, const Int&num)
{
	int i;
	if(num.digit == 0)
		out<<0;
	else
		for(i=num.digit-1;i>=0;i--)
			out<<num.arr[i];
	return out;	
}

// 患癹そΑ 
// dp[0]=1
// dp[1]=0
// dp[n]=(N[n-1]+N[n-2])*(n-1) 

int main()
{
	int i,j,k;
	int input;
	Int*dp = new Int[801];
	dp[0] = Int(1);
	dp[1] = Int(0);
	dp[2] = Int(1);
	for(i=3;i<801;i++)
		dp[i] = (dp[i-1] + dp[i-2]) * Int(i-1);
		
	while(cin>>input)
	{
		if(input == -1)
			break;
		cout<<dp[input]<<endl;
		
	}
	return 0;
}











