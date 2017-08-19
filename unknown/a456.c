#include <stdio.h>
#include <stdlib.h>

/*�Q�λ��j�ӧ�X�Ҧ��i�઺�զX���D*/

void recursion(int current,int last,int use[15],int num,int N);

int main()
{
	int T,N;
	int arr[15];
	int use[15];
	int i,j,k;
	
	while(scanf("%d",&T)!=EOF)
	{
		for(i=0;i<T;i++)
		{
			scanf("%d",&N);
			
			//��l��use�}�C
			for(j=0;j<N;j++) 
				use[j] = 0;
				
			for(j=0;j<=N;j++)
				recursion(0,0,use,j,N);
		}
	
	
	}
	return 0;
}

void recursion(int current,int last,int use[15],int num,int N)
{
	//current�N��ثe������h�ּƦr
	//last�������X���̫�@���Ʀr 
	//use�������ǼƦr�Q�ϥ�(use[i] == 1 �N��Ʀri+1�Q�ϥ�)
	//num�N��n����h�֭ӼƦr 
	//N�N���`�@���h�ּƦr 
	int i,j,k;
	int first_number = 1; //�ΨӨM�w�O�_���Ĥ@�ӥX�{���Ʀr 
	if(num==0)
		printf("{0}\n");
	
	else if(current == num)
	{
		printf("{");
		for(i=0;i<N;i++)
		{
			if(use[i]==1 && first_number==1)
			{	
				printf("%d",i+1);
				first_number = 0;
			}
			else if(use[i]==1 && first_number==0)
			{
				printf(",%d",i+1);
			}
		}
		printf("}\n");
	}
	else
	{
		for(i=last;i+(num-current)-1<N;i++)
		{
			if(use[i]==0)
			{
				use[i] = 1;//�N�o�ӼƦr��춰�X�� �A�ҥH�N��Q�ϥΤF 
				recursion(current+1,i+1,use,num,N);
				use[i] = 0;
			}
		}
	}
}













