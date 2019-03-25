#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//求最大连续子数组和，暴力法
int maxsum(int *a,int n,int allsum)
{
	int sum = 0;
	int maxnum = allsum;
	for(int i = 0;i<n;i++)
	{
		for(int j = i;j<n;j++)
		{
			for(int k = 0;k<j;k++)
			{
				sum +=a[k];
			}
			if(sum>maxnum)
				maxnum = sum;
			sum = 0;
		}
	}
	return maxnum;
}


int maxSum(int* a, int n)
{
	int sum=0;
	//其实要处理全是负数的情况，很简单，如稍后下面第3点所见，直接把这句改成："int sum=a[0]"即可
	//也可以不改，当全是负数的情况，直接返回0，也不见得不行。
	int b=0;
	
	for(int i=0; i<n; i++)
	{
		if(b<0)           //...
			b=a[i];
		else
			b+=a[i];
		if(sum<b)
			sum=b;
	}
	return sum;
}

int main()
{
    int a[10]={1, -2, 3, 10, -4, 7, 2, -5};
	//int a[]={-1,-2,-3,-4};  //测试全是负数的用例
    maxSum(a,8);
    return 0;
}
/*
//处理全是负数情况
#define n 4           //多定义了一个变量

int maxsum(int a[n])  
//于此处，你能看到上述思路2代码（指针）的优势
{
    int max=a[0];       //全负情况，返回最大数
    int sum=0;
    for(int j=0;j<n;j++)
    {
        if(sum>=0)     //如果加上某个元素，sum>=0的话，就加
            sum+=a[j];
        else   
            sum=a[j];  //如果加上某个元素，sum<0了，就不加
        if(sum>max)
            max=sum;
    }
    return max;
}

int main()
{
    int a[]={-1,-2,-3,-4};
    maxsum(a);
    return 0;
}
*/