#include <stdio.h>
#include <stdlib.h>

/*
��²�檺���j�D�ءA�O�Q�ӽ���
���ӷQ��dfs�A�Ʀ�bfs�C��Ӥ~�o�{�ڥ�����... 
*/


void Fibonacci(int arr0[10000],int arr1[10000],int count,int*total);

int main()
{
	int input;
	int i,j;
	int total;
	int arr0[10000],arr1[10000];
	while(scanf("%d",&input)!=EOF)
	{
		if(input == 0)
			break;
		arr0[0] = input;
		Fibonacci(arr0,arr1,1,&total);
		printf("f(%d) = %d\n\n",input,total);
	}
	return 0;
}

void Fibonacci(int arr0[10000],int arr1[10000],int count,int*total)
{		
	//arr0�}�C�|�s���ơB�ñN�ಾ�᪺��Ʀs�barr1�}�C 
	//use�ܼƥΨӧP�_�ثe�O���Ӱ}�C���ơBcount�ΨӬ����o���ܼƦ��h�ָ�� 
	int recursion=0;//�o���ܼƥΨӧP�_�O�_�n�����j 
	int i,j,k;
	int count2 = 0;//�ΨӬ����t�@�Ӱ}�C�s��X�Ӥ��� 
	for(i=0;i<count;i++)
	{
		
		if(arr0[i]>1)
		{
			recursion = 1; //�o�@�h��>1���Ʀr�A�٭n�~�򰵻��j 
			arr1[count2++] = arr0[i]-1;
			arr1[count2++] = arr0[i]-2;
		}
		else
		{
			arr1[count2] = arr0[i];
			count2+=1;
		}
			
		printf("f(%d) ",arr0[i]);
		
	}
	printf("\n");
	if(recursion)
		Fibonacci(arr1,arr0,count2,total);
	else
		*total = count2;
	
	
}
