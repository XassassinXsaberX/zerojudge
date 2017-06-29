#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*練習linked list的好題目*/

typedef struct newNode
{
	char*word;
	int position;
	struct newNode*next;
}Node;


int Strlen(const char*);
int Strcmp(const char*,const char*); 
int find(Node*,const char*);
void insert(Node*head, const char*str);
void delete_Node(Node*head, const char*str);
void delete_all(Node*head);


int main()
{
	char str[1000];
	char word[1000];
	char *start,*current;
	int len;
	int f;
	int i,j,k;
	Node *head=(Node*)malloc(sizeof(Node));
	head->next = NULL;
	while(1)
	{
		gets(str);
		//scanf("%s",str);
		if(str[0]=='0' && str[1]=='\0')
			break;
		
		start = str;
		while(1)
		{
			if(*start == '\0')
			{
				printf("\n");
				break;
			}
			else if((*start>='a'&&*start<='z') || (*start>='A'&&*start<='Z'))
			{
				//再來要正式尋找單字
				current = start;
				len = 0; //紀錄單字長度 
				while(1)
				{
					if((*current>='a'&&*current<='z') || (*current>='A'&&*current<='Z'))
					{}
					else
						break;
					current++;
					len++;			
				}

				//並將單字存在word指向的空間中
				for(i=0;i<len;i++)
					word[i] = *(start+i);
				word[len] = '\0';
				
				//判斷word是否在link list中
				f = find(head,word);
				if(f == 0) //若word不在link list中 
				{
					printf("%s",word);
					insert(head,word);
				} 
				else
				{
					printf("%d",f);
					delete_Node(head,word);
					insert(head,word);
				}
				start = current;
			}	
			else
			{
				printf("%c",*start);
				start += 1;
			}
			 
		}
		
		
	}
}

int Strlen(const char*str) //回傳字串長度 
{
	int i;
	for(i=0;;i++)
		if(str[i] == '\0')
			return i;
	
}

int Strcmp(const char*s1,const char*s2) //若兩字串相同回傳0，否則回傳1 
{
	int i;
	for(i=0;;i++)
	{ 
		if(s1[i]=='\0'&&s2[i]=='\0')
			return 0;
		if(s1[i] != s2[i])
			return 1;
	} 
	return 0; 
} 

int find(Node*head,const char*str)//尋找link list中是否有字串元素為str的node，若有則回傳在第幾個位置，若無回傳0 
{
	Node*current,*previous;
	current = head->next;
	previous = head;
	int position = 1;
	while(1)
	{
		if(current == NULL)
			return 0;
		if(Strcmp(current->word, str)!=0) //如果字串不同的情況下 
		{
			previous = current;
			current = current->next;
		} 
		else
			return position;
		position++;
	}	
}

void insert(Node*head, const char*str) //在link list的頂端插入新節點
{
	int i;
	Node * newnode = (Node*)malloc(sizeof(Node));
	newnode->word = (char*)malloc(sizeof(char)*(Strlen(str)+1));
	newnode->next = head->next;
	head->next = newnode;
	for(i=0;;i++)
	{
		newnode->word[i] = str[i];
		if(str[i]=='\0')
			break;
	}
}

void delete_Node(Node*head, const char*str)  // 在link list中刪除一個字串元素為str的節點 
{
	Node*current,*previous;
	current = head->next;
	previous = head;
	while(1)
	{
		if(Strcmp(current->word, str)==0)
		{
			previous->next = current->next;
			free(current->word);
			free(current);
			break;
		}
		else
		{
			previous = current;
			current = current->next;
		}
	}
}

void delete_all(Node*head)//刪除link list中的所有節點 
{
	Node*current,*previous;
	current = head->next;
	previous = head;
	while(1)
	{
		if(current==NULL)
			break;
		previous->next = current->next;
		free(current->word);
		free(current);
		current = previous->next;
	}
}








