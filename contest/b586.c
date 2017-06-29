#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*�m��linked list���n�D��*/

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
				//�A�ӭn�����M���r
				current = start;
				len = 0; //������r���� 
				while(1)
				{
					if((*current>='a'&&*current<='z') || (*current>='A'&&*current<='Z'))
					{}
					else
						break;
					current++;
					len++;			
				}

				//�ñN��r�s�bword���V���Ŷ���
				for(i=0;i<len;i++)
					word[i] = *(start+i);
				word[len] = '\0';
				
				//�P�_word�O�_�blink list��
				f = find(head,word);
				if(f == 0) //�Yword���blink list�� 
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

int Strlen(const char*str) //�^�Ǧr����� 
{
	int i;
	for(i=0;;i++)
		if(str[i] == '\0')
			return i;
	
}

int Strcmp(const char*s1,const char*s2) //�Y��r��ۦP�^��0�A�_�h�^��1 
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

int find(Node*head,const char*str)//�M��link list���O�_���r�ꤸ����str��node�A�Y���h�^�Ǧb�ĴX�Ӧ�m�A�Y�L�^��0 
{
	Node*current,*previous;
	current = head->next;
	previous = head;
	int position = 1;
	while(1)
	{
		if(current == NULL)
			return 0;
		if(Strcmp(current->word, str)!=0) //�p�G�r�ꤣ�P�����p�U 
		{
			previous = current;
			current = current->next;
		} 
		else
			return position;
		position++;
	}	
}

void insert(Node*head, const char*str) //�blink list�����ݴ��J�s�`�I
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

void delete_Node(Node*head, const char*str)  // �blink list���R���@�Ӧr�ꤸ����str���`�I 
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

void delete_all(Node*head)//�R��link list�����Ҧ��`�I 
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








