#include <stdio.h>
#include <stdlib.h>

/*
tree的後序走訪(postoder traversal)變化型

他考的觀念是如果已知一棵二元樹的前序走訪及中序走訪
則能據此決定一棵唯一的二元樹
所以也能得到該樹的後序走訪 
*/


void postorder(int pre_s,int pre_e,int in_s,int in_e,char*s1,char*s2);

int main()
{
	char str1[26],str2[26]; //分別代表一棵二元樹的前序走訪字串、中序走訪字串 
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
	//pre_s、pre_e  代表前序走訪字串的範圍
	//in_s、in_e    代表中序走訪字串的範圍
	//s1、s2        代表前序走訪字串、中序走訪字串 
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
