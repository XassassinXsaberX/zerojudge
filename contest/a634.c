#include <stdio.h>
#include <stdlib.h>

/*�Q�ΤFDFS�BBFS��linked list�ӸѨM���D...*/

typedef struct newNode
{
	int row,col;
	int count;
	struct newNode *next;
}Node;

int bfs(int map[8][8],int s_row,int s_col,int e_row,int e_col); 
void dfs(int map[8][8],int s_row,int s_col,int e_row,int e_col,int c_row,int c_col,int current_step,int short_distance,Node*head);
void push_node(Node*head,int row,int col);
void pop_node(Node*head);
void delete_all(Node*head);
void print_node(Node*head);

int main()
{
	int map[8][8];
	int i,j,k;
	char start[3],end[3],obstacle[3];
	int start_row,start_col,end_row,end_col,obstacle_row,obstacle_col;
	int short_distance; //�N��̵u�Z�� 
	Node*head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	while(scanf("%s %s",start,end)!=EOF)
	{
		//������l�Ʀa�� 
		for(i=0;i<8;i++)
			for(j=0;j<8;j++)
				map[i][j] = 0;
		start_row = -(start[1] - '1') + 7;
		start_col = start[0] - 'a';		
		end_row = -(end[1] - '1') + 7;
		end_col = end[0] - 'a';
		
		map[start_row][start_col] = 1; //�N��_�I
		map[end_row][end_col] = 2;     //�N����I 
		
		//���U�ӳ]�w�Ҧ��i�઺��ê�I 
		while(1)
		{
			scanf("%s",obstacle);
			if(obstacle[0] == 'x' && obstacle[1] == 'x')
				break;
			else
			{
				obstacle_row = -(obstacle[1]-'1') + 7;
				obstacle_col = obstacle[0] - 'a'; 
				map[obstacle_row][obstacle_col] = 3;  //�N���ê 
			}
		}
		
		//���Q��bfs�D�X�̵u�Z��
		short_distance = bfs(map,start_row,start_col,end_row,end_col);
		
		printf("The shortest solution is %d move(s).\n",short_distance);
		
		//�b��dfs���j��X�Ҧ��i��� 
		push_node(head,start_row,start_col);
		dfs(map,start_row,start_col,end_row,end_col,start_row,start_col,0,short_distance,head);
		delete_all(head);
		
	}

}

//�Q��bfs��X�̰_�I����I���̵u���|���� 
int bfs(int map[8][8],int s_row,int s_col,int e_row,int e_col)
{
	Node queue[100];
	int oper_row[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
	int oper_col[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
	int rear=0,front=-1;
	int i,j,k;
	queue[rear].row = s_row;
	queue[rear].col = s_col;
	queue[rear].count = 0;
	
	if(s_row == e_row && s_col == e_col)
		return 0;
		
	while(1)
	{
		if(front == rear)//�N��queue�w��
			break;
		front = (front+1)%100;
		for(i=0;i<8;i++)
		{
			if(queue[front].row+oper_row[i] >= 0 && queue[front].row+oper_row[i] < 8 &&   //�N���ʳo�@�B��A���|�W�X�a�Ϫ�row 
			   queue[front].col+oper_col[i] >= 0 && queue[front].col+oper_col[i] < 8 &&   //�N���ʳo�@�B��A���|�W�X�a�Ϫ�col 
			   map[queue[front].row+oper_row[i]][queue[front].col+oper_col[i]] != 1 &&    //�N���ʳo�@�B��Ҩ�F���I�A���O�_�I
			   map[queue[front].row+oper_row[i]][queue[front].col+oper_col[i]] != 3 &&    //�N���ʳo�@�B��Ҩ�F���I�A���O��ê�I 
			   map[queue[front].row+oper_row[i]][queue[front].col+oper_col[i]] != 4 )     //�N���ʳo�@�B��Ҩ�F���I�A�|���g�L 
			{
				if(map[queue[front].row+oper_row[i]][queue[front].col+oper_col[i]] == 2)  //�Y���ʳo�@�B��Ҩ�F���I�����I
				{
					//��a���٭즨��l���A
					for(j=0;j<8;j++)
						for(k=0;k<8;k++)
							if(map[j][k] == 4) 
								map[j][k] = 0; 
						
					return queue[front].count + 1;  //�Ǧ^�Ȭ��_�I�ܤ֭n�g�L�X�B�~�����I 
				} 
					 
				map[queue[front].row+oper_row[i]][queue[front].col+oper_col[i]] = 4;      //���I�]���w�g�L�F 
				
				//�̫��Ӹ`�I���queue�� 
				rear = (rear+1)%100;
				queue[rear].row = queue[front].row+oper_row[i];
				queue[rear].col = queue[front].col+oper_col[i];
				queue[rear].count = queue[front].count + 1;
			}
		}
		if(rear == front)
			break; 
	}
	return 0; //�N��_�I�L�k����I 
}

//�Q��dfs��X�Ҧ��i���
void dfs(int map[8][8],int s_row,int s_col,int e_row,int e_col,int c_row,int c_col,int current_step,int short_distance,Node*head)
{
	int i,j,k;
	int oper_row[8] = {1, -1, 2, -2, 2, -2, 1, -1};
	int oper_col[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
	if(c_row == e_row && c_col == e_col)
	{
		printf("Solution:");
		print_node(head);
		printf("\n");
	}
	else if(current_step >= short_distance)
		return ;
	else
	{
		for(i=0;i<8;i++)
		{
			if(c_row+oper_row[i] >= 0 && c_row+oper_row[i] < 8 &&  //�N���ʳo�@�B��A���|�W�X�a�Ϫ�row 
			   c_col+oper_col[i] >= 0 && c_col+oper_col[i] < 8 &&  //�N���ʳo�@�B��A���|�W�X�a�Ϫ�col
			   map[c_row+oper_row[i]][c_col+oper_col[i]] != 1 &&   //�N���ʳo�@�B��Ҩ�F���I�A���O��ê�I
			   map[c_row+oper_row[i]][c_col+oper_col[i]] != 3 &&   //�N���ʳo�@�B��Ҩ�F���I�A���O��ê�I
			   map[c_row+oper_row[i]][c_col+oper_col[i]] != 4)     //�N���ʳo�@�B��Ҩ�F���I�A�|���g�L
			{
				//�Q��linked list����k�ӰO���g�L���| 
				map[c_row+oper_row[i]][c_col+oper_col[i]] = 4;
				push_node(head,c_row+oper_row[i],c_col+oper_col[i]);
				dfs(map,s_row,s_col,e_row,e_col,c_row+oper_row[i],c_col+oper_col[i],current_step+1,short_distance,head);
				map[c_row+oper_row[i]][c_col+oper_col[i]] = 0;
				pop_node(head);
			} 
		}
	}

	
} 

void push_node(Node*head,int row,int col)  //�blinked list���̩������J�@�Ӹ`�I 
{
	Node*current,*newnode;
	newnode = (Node*)malloc(sizeof(Node));
	newnode->row = row;
	newnode->col = col;
	newnode->next = NULL;
	
	current = head;
	while(1)
	{
		if(current->next == NULL)
		{
			current -> next = newnode;
			return;
		}
		else
			current = current->next;
	}
}

void pop_node(Node*head)  //�blinked list���̩����R���@�Ӹ`�I 
{
	Node*current,*previous;
	current = head->next;
	previous = head;
	
	if(current == NULL)
		return ;
	
	while(1)
	{
		if(current->next == NULL)
		{
			previous->next = NULL;
			free(current);
			return ;
		}
		else
		{
			previous = current;
			current = current->next;
		}
			
	}
	
}

void delete_all(Node*head) //�R��linked list�Ҧ��`�I
{
	Node*previous=head->next,*current;
	if(previous == NULL)
		return ;
	else
		current = previous->next;
	
	while(1)
	{
		free(previous);
		if(current == NULL)
			break;
		previous = current;
		current = current->next;
	}
	head->next = NULL;
} 

void print_node(Node*head)  //�L�Xlinked list�W���Ҧ��`�I 
{
	Node*current;
	current = head->next;
	while(1)
	{
		if(current == NULL)
			break;
		printf(" %c%d",current->col+'a',-current->row+8);
		current = current->next;
	}
}




