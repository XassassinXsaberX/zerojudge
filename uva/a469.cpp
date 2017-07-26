#include <iostream>
#include <list>

using namespace std;

/*利用linked list和遞迴來解排列組合的排列問題*/

void recursion(int count,char str[100],int use[100],list<char> node,int len);

int main()
{
	char str[100];
	int use[100];     //用來紀錄字串中的某一個字元是否被選取 
	int len;          //用來紀錄字串長度 
	int i,j;
	list<char> node;
	while(cin>>str)
	{
		//先來找字串長度 
		for(i=0;;i++)
			if(str[i]=='\0')
				break;
		len = i;
		
		//再來初始化use陣列
		for(i=0;i<len;i++)
			use[i] = 0; 
		
		recursion(0,str,use,node,len);
		
	}
	return 0;
}

void recursion(int count,char str[100],int use[100],list<char> node,int len)
{
	//count用來紀錄目前遞迴蒐集了多少字串
	//str記錄了一開始輸入的字串
	//use記錄了字串中的字元是否被使用
	//node用來紀錄目前排列後所累積的node 
	//len記錄了原先輸入字串的長度 
	list<char>::iterator iter;
	int i,j;
	int c=0;
	if(count == len)
	{
		for(iter=node.begin();iter!=node.end();iter++)
			cout<<*iter;
		cout<<endl;
	}
	else
	{
		for(i=0;i<len;i++)
		{
			if(use[i]==0)
			{
				for(iter=node.begin();iter!=node.end();iter++)
				{
					use[i] = 1;
					// 若此時iter指向 ptr1 
					iter = node.insert(iter,str[i]);  // str[i]元素會插入到iter指向的位置之前
					// 現在iter指向新插入的元素 
					
					recursion(count+1,str,use,node,len);
					iter = node.erase(iter);          // iter指向下一個元素
					// 現在iter仍指向 ptr1 
					use[i] = 0; 
				
				}
				
				// 當iter == node.end()時還要再做一次遞迴動作 
				use[i] = 1;
				// 此時iter指向node.end()
				iter = node.insert(iter,str[i]);  // str[i]元素會插入到iter指向的位置之前
				// 現在iter指向新插入的元素 
				
				recursion(count+1,str,use,node,len);
				iter = node.erase(iter);          // iter指向下一個元素
				// 現在iter仍指向node.end() 
				use[i] = 0; 
				
				break;
			}
		}
	}
}





