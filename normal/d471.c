#include <stdio.h>
#include <stdlib.h>

/*²�檺���j�m��*/

void recursion(int current,int*arr,int n);

int main()
{
	int n;
	int arr[15];
	while(scanf("%d",&n)!=EOF)
	{
		recursion(0,arr,n);
	}
	return 0;
	
}

void recursion(int current,int*arr,int n)
{
	//current�ΨӬ����ثe���j��ĴX�Ӧ�m
	//n����arr�@���X�Ӥ��� 
	int i,j;
	if(current == n)
	{
		for(i=0;i<n;i++)
			printf("%d",arr[i]);
		printf("\n");
	}
	else
	{
		for(i=0;i<2;i++)
		{
			arr[current] = i;
			recursion(current+1,arr,n);
		}
	}
}
