#include <stdio.h>
#include <stdlib.h>

/*練習對已排序好的數列進行 binary search*/

int binary_search(int*arr,int value,int n);

int main()
{
	int n,k;
	int *arr;
	int i,j;
	int value;
	while(scanf("%d %d",&n,&k)!=EOF)
	{
		arr = (int*)malloc(sizeof(int)*n);
		
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);
		for(i=0;i<k;i++)
		{
			scanf("%d",&value);
			printf("%d\n",binary_search(arr,value,n));
		}	
				
		
		free(arr);
	
	}
	return 0;

}

int binary_search(int*arr,int value,int n)
{  //arr為已從小到大排序好的陣列
   //value為要搜尋的值
   //n代表陣列共有多少元素 
	int i,j,k;
	int start=0,end=n; //分別代表起點及終點 
	int mid;           //代表中間位置 
	
	while(1)
	{
		mid = (start + end) / 2;   // 先找出中間位置 
		if(arr[mid] == value)      // 如果在arr陣列中搜尋到value  
			return mid+1;          // 就回傳其位置 
			
		else if(arr[mid] < value)  // 如果arr陣列中間值 < value 
			start = mid+1;         // 改成搜尋陣列的後半部分 
			
		else if(value < arr[mid])  // 如果arr陣列中間值 > value 
			end = mid;             // 改成搜尋陣列的前半部分 
			
		if(start == end)           // 如果搜尋完畢後，仍未找到值 
			return 0;	           // 則回傳0 
	}
	
}









