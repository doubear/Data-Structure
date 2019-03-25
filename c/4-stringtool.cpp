#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//查找子串,返回查找个数
int strstr(char *string,char *substring)
{
	int m = 0;
	if (string == NULL || substring == NULL)        
		return -1; 
	int lenstr = strlen(string);     
	int lensub = strlen(substring);
	if (lenstr < lensub)        
		return -1;
	int len = lenstr - lensub;
	int i,j;
	for(i=0;i<=len;i++)
	{
		for(j=0;j<lensub;j++)
		{	
			if(*(string+i+j)!=*(substring+j))
				break;
		}
		if(j==lensub)
			m++;
			//return i+1;
	}
	return m;
}

//字符串拷贝
char *strstrcpy(char *strdest,char *src)
{
	char *address = strdest;
	while((*strdest++ = *src++)!='\0');
	return address;
}

//字符串比较
int strstrcmp(char *s,char *t)
{
	while(*s&&*t&&*t==*s)
	{
		++s;
		++t;

	}
	return(*s-*t);
}
//内存拷贝
void *memcpy(void *dest, const void *src, unsigned int count)   
{   
    
    void *address = dest;   
    while (count --)   
    {   
        *(char *) dest = *(char *) src;   
        dest = (char *) dest + 1;   
        src = (char *) src + 1;   
    }   
    return address;   
}   


int main()
{
	char a[20]="qabcdefcdeg";
	char b[10]="cde";
	int i = strstr(a,b);
	printf("%d\n",i);

	char dest[30] = {""};
	char *deststr = dest;
	deststr = strstrcpy(dest,a);
	printf("%s\n",deststr);
	return 0;
}