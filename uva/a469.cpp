#include <iostream>
#include <list>

using namespace std;

/*�Q��linked list�M���j�ӸѱƦC�զX���ƦC���D*/

void recursion(int count,char str[100],int use[100],list<char> node,int len);

int main()
{
	char str[100];
	int use[100];     //�ΨӬ����r�ꤤ���Y�@�Ӧr���O�_�Q��� 
	int len;          //�ΨӬ����r����� 
	int i,j;
	list<char> node;
	while(cin>>str)
	{
		//���ӧ�r����� 
		for(i=0;;i++)
			if(str[i]=='\0')
				break;
		len = i;
		
		//�A�Ӫ�l��use�}�C
		for(i=0;i<len;i++)
			use[i] = 0; 
		
		recursion(0,str,use,node,len);
		
	}
	return 0;
}

void recursion(int count,char str[100],int use[100],list<char> node,int len)
{
	//count�ΨӬ����ثe���j�`���F�h�֦r��
	//str�O���F�@�}�l��J���r��
	//use�O���F�r�ꤤ���r���O�_�Q�ϥ�
	//node�ΨӬ����ثe�ƦC��Ҳֿn��node 
	//len�O���F�����J�r�ꪺ���� 
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
					// �Y����iter���V ptr1 
					iter = node.insert(iter,str[i]);  // str[i]�����|���J��iter���V����m���e
					// �{�biter���V�s���J������ 
					
					recursion(count+1,str,use,node,len);
					iter = node.erase(iter);          // iter���V�U�@�Ӥ���
					// �{�biter�����V ptr1 
					use[i] = 0; 
				
				}
				
				// ��iter == node.end()���٭n�A���@�����j�ʧ@ 
				use[i] = 1;
				// ����iter���Vnode.end()
				iter = node.insert(iter,str[i]);  // str[i]�����|���J��iter���V����m���e
				// �{�biter���V�s���J������ 
				
				recursion(count+1,str,use,node,len);
				iter = node.erase(iter);          // iter���V�U�@�Ӥ���
				// �{�biter�����Vnode.end() 
				use[i] = 0; 
				
				break;
			}
		}
	}
}





