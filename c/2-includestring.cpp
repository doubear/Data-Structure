#include<stdio.h>
#include<string.h>
//检测大字符串是否包含小字符串所有字母
//1、n*m轮询法
int comparestring(char *s1,char *s2)
{
	int i,j;
	for(i = 0;i<strlen(s1);i++)
	{
		for(j = 0;j<strlen(s2);j++)
		{
			if(*(s1+i)==*(s2+j))
			{				
				break;
			}
		}
		if(j==strlen(s2))
		{
			return 0;
		}
	}
	return 1;
} 

//mlogm+nlogn+m+n快排法
void swap(char *a,char *b)
{
	char temp;
	temp = *a;
	*a = *b;
	*b = temp; 
}
int partition(char *s,int lo,int hi)
{
	int key = s[hi];
	int i = lo-1;
	for(int j = lo;j<hi;j++)
	{
		if(s[j]<=key)
		{
			i++;
			swap(s+i,s+j);
		}
	}
	swap(s+i+1,s+hi);
	return i+1;
}
void quicksort(char *s,int lo,int hi)
{
	if(lo<hi)
	{
		int k = partition(s,lo,hi);
		quicksort(s,lo,k-1);
		quicksort(s,k+1,hi);
	}
}
int compare(char *s1,char *s2)
{
	int pos1 = 0;
	int pos2 = 0;
	while(pos2<strlen(s2)&&pos1<strlen(s1))
	{
		while(s1[pos1]<s2[pos2]&&pos1<strlen(s1)-1)
			pos1++;
		if(s1[pos1]!=s2[pos2])
			break;
		pos2++;	
	}
	if(pos2==strlen(s2))
		return 1;
	else
		return 0;
}

//计数查找
int countort(char *s1,char *s2)
{
	int help[26] = {0};
	for(int i=0;i<strlen(s1);i++)
	{
		int inm = s1[i]-'A';
		if(help[inm] == 0)
			help[inm]++;
	}
	for(int j=0;j<strlen(s2);j++)
	{
		int temp = s2[j]-'A';
		if(help[temp] == 0)
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	char s1[30] = "ABCDEFGHLMNOPQRS";
	char s2[20] = "DCSGRQPO";
	char s3[10] = "CZ";
	/*int m = comparestring(s1,s3);
	printf("%d\n",m);
	*/

	char a ='a';
	char b ='b';
	//swap(&a,&b);
	//printf("%c %c\n",a,b );
	/*
	quicksort(s1,0,strlen(s1)-1);
	quicksort(s3,0,strlen(s3)-1);
	int k =compare(s1,s3);
	printf("%d\n", k);
	*/
	int k = countort(s1,s3);
	printf("%d\n",k );
	


	return 0;
}