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


int main()
{
	char a[20] = "abcd";
	Permutation(a);

	return 0;
}