#include <iostream>
using namespace std;

/*
0/1�I�]���D (0/1 knapsack problem) 
0/1 ���N��O�G�C�ت��~�u�|��i�I�]�s�өΤ@�ӡC�@�Ӫ��~�n����Ӥ���i�I�]�B�n����ө�i�I�]�C���~�L�k���ΡC 
���D�n�ݪ��O "���I�]�̭������~�`��n�̤j" 
*/

int main()
{
	int v;            //�I�]��e�Ǫ��̤j��n 
	int n;            //�`�@��n�Ӫ��~ 
	int arr[30];      //arr�}�C�ΨӦs��C�Ӫ��~����n 
	char dp[20001];    
	int i,j,k;
	int max_volume;   //�qn�Ӫ��~���A��S�w�X�Ӫ��~�����`��n�̤j�ơA������W�Lv 
	
	while(cin>>v)
	{
		cin>>n;
		for(i=0;i<n;i++)
			cin>>arr[i];
			
		//���U�ӭn��l��dp�}�C
		for(i=0;i<=v;i++)
			dp[i] = 0;
		dp[0] = 1;
		 
		//�}�l�i��ʺA�W�� 
		max_volume = 0;  //�����Ҧ����~�ֿn���̤j��n (�`�N�G����W�L�I�]��e�Ǫ��̤j��nv) 
		for(i=0;i<n;i++) //�a�|�Ҧ��i�ફ�~����n (arr[i] �N���~i����n) 
		{
			for(j=v;j-arr[i]>=0;j--)
			{
				if(dp[j-arr[i]] == 1)     //�p�G�b����J���~i�ɡA��L���~���`��n�i�H�ֿn�� j-arr[i] 
				{
					dp[j] = 1;            //�N��[�W���~i����n�ɡA�`��n�i��Fj 
					if(j > max_volume)    //�Y�[�W���~i����narr[i]��A���`��n�W�Lmax_volume(�����W�Lv) 
						max_volume = j;   //�h��smax_volume�� 
				}			
			}
		}
		
		cout<<(v - max_volume)<<endl;
		 
	
	}
	return 0;
}
