//左旋转字符串
#include<stdio.h>
#include<string.h>





//1暴力法左移动一位
void leftshiftone(char *s,int n)
{
	char t = s[0];
	for(int i = 1;i < n;++i)
	{
		s[i-1]=s[i];
	}
	s[n-1] = t;
}
//左移m位
void leftshift(char *s,int n,int m)
{
	while(m--)
	{
		leftshiftone(s,n);
	}
}

//2指针旋转法
void rotate(char *s,int n,int m)
{
	int p1 = 0,p2 = m;
	int k =(n-m)-n%m;//得出交换轮数
	int temp = 0;
	while(k--)
	{
		temp = s[p1];
		s[p1] = s[p2];
		s[p2] = temp;
		p1++;
		p2++;
	}
	//尾部处理
	int r = n - p2;
	while(r--)
	{
		int i = p2;
		while(i>p1)
		{
			temp = s[i];
			s[i] = s[i-1];
			s[i-1] = temp;
			i--;
		}
		p1++;
		p2++;
	}
}

//3递归转换法
void urotate(char *s,int n,int m,int head,int tail,int flag)
{
	if(head==tail||m<=0)
		return;
	if(flag == 1)
	{
		int p1 = head;
		int p2 = head+m;
		int k = (n-m)-n%m;
		for(int i = 0;i<k;i++,p1++,p2++)
		{
			int temp =s[p1];
			s[p1]=s[p2];
			s[p2]=temp;
		}
		urotate(s,n-k,n%m,p1,tail,0);
	}else{
		int p1 = tail;
		int p2 = tail - m;
		int k =(n-m)-n%m;
		for(int i=0;i<k;i++,p1--,p2--)
		{
			int temp =s[p1];
			s[p1]=s[p2];
			s[p2]=temp;
		}
		urotate(s,n-k,n%m,head,p1,1);
	}
}

//4三步反转法
char *invert(char *start , char *end)
{
	char tmp,*ptmp = start;
	while(start != NULL&&end!=NULL&&start<end)
	{
		tmp = *start;     
		*start = *end;        
		*end = tmp;       
		start ++;     
		end --;
	}
	return ptmp;
}
char *left(char *s,int pos)
{
	int len = strlen(s);
	invert(s,s+(pos-1));
	invert(s+pos,s+(len-1));
	invert(s,s+(len-1));
	return s;
}


int main()
{
	//char s[10] = "abcdefg";
	//leftshiftone(s,strlen(s));
	//leftshift(s,strlen(s),2);

	char s[20] = "abcdefghijk";
	//rotate(s,strlen(s),3);

	urotate(s,strlen(s),3%strlen(s),0,strlen(s)-1,1);
	
	printf("%s\n",s);

	return 0;
}