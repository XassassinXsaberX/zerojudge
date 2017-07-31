#include <stdio.h>
#include <stdlib.h>

/*�Q�λ��j�ѨM�ƦC�զX���D*/

void recursion(int current,int*arr,int*use,int n);

int main()
{
	int n;
	int i,j;
	int arr[8],use[8];
	while(scanf("%d",&n)!=EOF)
	{
		//��l��use�}�C
		//use�}�C�O�ΨӬ������ǼƦr�w�Q�ιL 
		for(i=0;i<n;i++)
			use[i] = 0; 
		recursion(0,arr,use,n);
	}
	return 0;
}

void recursion(int current,int*arr,int*use,int n)
{
	int i,j,k;
	if(current == n)
	{
		for(i=0;i<n;i++)
			printf("%d",arr[i]);
		printf("\n");
	}
	else
	{
		for(i=n-1;i>=0;i--)
		{
			//��Y�ӼƦr�٨S�Q�ϥΡA�~��ΥL�ӱƦC 
			if(use[i]==0)
			{
				use[i] = 1;
				arr[current] = i+1;
				recursion(current+1,arr,use,n);
				use[i] = 0;
			}
		}
	}
}
