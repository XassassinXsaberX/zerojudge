#include <stdio.h>
#include <stdlib.h>

/*
很簡單的遞迴題目，別想太複雜
本來想用dfs，甚至bfs。後來才發現根本不用... 
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
	//arr0陣列會存放資料、並將轉移後的資料存在arr1陣列 
	//use變數用來判斷目前是哪個陣列放資料、count用來紀錄這個變數有多少資料 
	int recursion=0;//這個變數用來判斷是否要做遞迴 
	int i,j,k;
	int count2 = 0;//用來紀錄另一個陣列存放幾個元素 
	for(i=0;i<count;i++)
	{
		
		if(arr0[i]>1)
		{
			recursion = 1; //這一層有>1的數字，還要繼續做遞迴 
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
