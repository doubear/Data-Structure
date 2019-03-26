#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}

//1全排列问题-递归实现
void Permutation(char* pStr, char* pBegin);
void Permutation(char* pStr)
{
      Permutation(pStr, pStr);
}
 
void Permutation(char* pStr, char* pBegin)
{
	if(!pStr || !pBegin)
		return;
	
	if(*pBegin == '\0')
	{
		printf("%s\n", pStr);
	}
	else
	{
		for(char* pCh = pBegin; *pCh != '\0'; ++ pCh)
		{
			// swap pCh and pBegin
			char temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;
			
			Permutation(pStr, pBegin + 1);	
			// restore pCh and pBegin
			temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;
		}
	}
}
//跳台阶问题=求斐波那契数列-递归
int fibo(int n)
{
	if(n == 1)
		return 1;
	else if (n == 2)
		return 2;
	else 
		return fibo(n-1)+fibo(n-2);
}
//递推
int fibo2(int n)
{
	int a[n];

	if(n == 1)
		return 1;
	else if (n == 2)
		return 2;
	a[0] = 1;
	a[1] = 1;
	int i;
	for(i = 2; i <= n;i++)
	{
		a[i] = a[i-1]+a[i-2];
	}
	return a[n];
}
//奇偶排序,指针头尾开始交换
int sort(int *a,int n)
{
	int *i,*j;
	i = &a[0];
	j = &a[n-1];
	while(i<=j)
	{
		if(*i%2==0)
		{
			if(*j%2==0)
			{
				j=j-1;
			}else{
				swap(i,j);
			}
		}else{
			i = i+1;
			if(*j%2==0)
			{
				j=j-1;
			}
		}
	}
	return 0;
}

//记录第一个只出现一次的字符
int findchar(char *a)
{
	int data[256]={0};
	char *p;
	p = a;
	while(*p!='\0')
	{
		data[*p]++;
		p++;
	}
	p = a;
	while(*p!='\0')
	{
		if(data[*p]==1)
		{
			printf("%c\n",*p);
			return 0;
		}
		p++;
	}

	
}

int main()
{
	char a[20] = "adadsdfafwdw";
	//Permutation(a);

	 // int num = fibo2(6);
	 // printf("%d\n",num);

	// int b[8]={3,6,4,7,9,5};
	// sort(b,6);
	// for (int i=0;i<6;i++)
	// {
	// 	printf("%d ",b[i]);
	// }

	findchar(a);
	
	return 0;
}
