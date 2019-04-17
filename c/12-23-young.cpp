#include<stdio.h>
#define row 4
#define col 4

int young(int a[][col],int findnum)
{
	int i = 0;
	int j = col-1;
	int num = a[i][j];
	//定位法
	while(1)
	{
        if(num == findnum )
        	return 1;
        else if(num < findnum && i<row-1)
        	num = a[++i][j];
        else if(num>findnum && j>0)
        	num = a[i][--j];
        else return 0;
	}

	return 0;
}

int main()
{
	int a[row][col]={{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
	int m = young(a,6);

	printf("%d\n",m);

	return 0;
}
