#include <stdio.h>
#include <stdlib.h>

/*
tree����Ǩ��X(postoder traversal)�ܤƫ�

�L�Ҫ��[���O�p�G�w���@�ʤG���𪺫e�Ǩ��X�Τ��Ǩ��X
�h��ڦ��M�w�@�ʰߤ@���G����
�ҥH�]��o��Ӿ𪺫�Ǩ��X 
*/


void postorder(int pre_s,int pre_e,int in_s,int in_e,char*s1,char*s2);

int main()
{
	char str1[26],str2[26]; //���O�N��@�ʤG���𪺫e�Ǩ��X�r��B���Ǩ��X�r�� 
	int i,j,k;
	int len;
	while(scanf("%s %s",str1,str2)!=EOF)
	{
		for(i=0;;i++)
			if(str1[i]=='\0')
				break;
		len = i;
		postorder(0,len,0,len,str1,str2);
		printf("\n");
	}
	return 0;
}

void postorder(int pre_s,int pre_e,int in_s,int in_e,char*s1,char*s2)
{
	//pre_s�Bpre_e  �N��e�Ǩ��X�r�ꪺ�d��
	//in_s�Bin_e    �N���Ǩ��X�r�ꪺ�d��
	//s1�Bs2        �N��e�Ǩ��X�r��B���Ǩ��X�r�� 
	int i,j,k;
	int in_mid;
	int find=0;
	
	for(i=in_s;i<in_e;i++)
	{
		if(s1[pre_s] == s2[i])
		{
			in_mid = i;
			find = 1;
			break;
		}
	}
	if(find==1)
	{
		postorder(pre_s+1, pre_s+1+(in_mid-in_s), in_s, in_mid, s1, s2);
		postorder(pre_s+1+(in_mid-in_s), pre_e, in_mid+1, in_e, s1, s2);
		printf("%c",s1[pre_s]);
	}
		
	

}
