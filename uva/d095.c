#include <stdio.h>
#include <stdlib.h>

/*
聯發科的面試考古題
英文題目請見 https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=520 
題目：找出時針分針的夾角 
*/

int main()
{
	int hour,min;
	char s[3];
	char c;
	int i,j,k;
	double angle1,angle2;
	double angle;
	while(scanf("%d%c%s",&hour,&c,s)!=EOF)
	{
		sscanf(s,"%d",&min);
		if(hour == 0 && min == 0)
			break;
			
		angle1 = hour*30;
		angle2 = min*6;
		angle1 = angle1 + 30*((double)min/60);
		if(angle1 > angle2)
			angle = angle1 - angle2;
		else
			angle = angle2 - angle1;
		if(angle > 180)
			angle = 360 - angle;
		
		printf("%0.3lf\n",angle);
		
	}
	return 0;
	
	
}
