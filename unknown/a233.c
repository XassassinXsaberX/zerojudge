#include <stdio.h>
#include <stdlib.h>

/*�o�@�D���ؼЬO�Ʊ�ڭ̪��D�p��ϥ�c�y�����ت�qsort function�����ֳt�Ƨ�*/

int cmp(const void*,const void*);

int main()
{
	int N;
	int i;
	int *arr;
	while(scanf("%d",&N)!=EOF)
	{
		arr = (int*)malloc(sizeof(int)*N);
		for(i=0;i<N;i++)
			scanf("%d",&arr[i]);
		qsort(arr, N, sizeof(int), cmp);
		for(i=0;i<N;i++)
			printf("%d ",arr[i]);
		printf("\n");
		free(arr);
	}
	return 0;
}

//�q�p��j�Ƨ� 
int cmp(const void*p1,const void*p2)
{
	int*a1 = (int*)p1;
	int*a2 = (int*)p2;
	if(*a1 < *a2) 
		return -1;  //The element pointed to by p1 goes before the element pointed to by p2
	else if(*a1 == *a2)
		return 0;   //The element pointed to by p1 is equivalent to the element pointed to by p2
		
	else
		return 1;   //The element pointed to by p1 goes after the element pointed to by p2
}
