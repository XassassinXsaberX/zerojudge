#include <stdio.h>
#include <stdlib.h>

/*
Euler�ϧΤ@���e���D
�i�ѦҺ���ʬ�  https://zh.wikipedia.org/wiki/%E4%B8%80%E7%AC%94%E7%94%BB%E9%97%AE%E9%A2%98 
*/

int main()
{
	int degree[10000];  //degree[i]�N��`�Ii�������(degree) 
	int i,j,k;
	int n,m;
	int node1,node2;
	int odd;           //�������h�֭Ӹ`�I����׬��_�� 
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		for(i=0;i<=n;i++)
			degree[i] = 0;
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&node1,&node2);
			degree[node1]++;
			degree[node2]++; 
		}
		
		//�έp����׬��_�ƪ��`�I���X�� 
		odd = 0;
		for(i=1;i<=n;i++)
		{
			if(degree[i]%2==1)
				odd++;
			if(odd > 2)
				break;
		}
		
		//�Y���׬��_�ƪ��`�I�ӼƬ�0��2�ӡA�h�ϧΥi�@���e�s�� 
		if(odd == 0 || odd == 2)
			printf("YES\n");
		else
			printf("NO\n"); 
		
	}
	return 0;
	
}
