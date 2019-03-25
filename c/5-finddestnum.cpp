#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp; 
}
int partition(int *s,int lo,int hi)
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
void quicksort(int *s,int lo,int hi)
{
	if(lo<hi)
	{
		int k = partition(s,lo,hi);
		quicksort(s,lo,k-1);
		quicksort(s,k+1,hi);
	}
}

int findnum(int *a,int length,int sum,int *i,int *j)
{
	int begin = 0;
	int end = length - 1;
	while(end>begin)
	{
		int nowsum = a[begin]+a[end];
		if(nowsum == sum)
		{
			*i = a[begin];
			*j = a[end];
			printf("%d %d %d %d\n",*i,*j,begin,end);
			begin++;
			//return 0;
		}else if(nowsum>sum)
			end--;
		else
			begin++;
	} 
	return 0;
}


//二分查找
int search(int array[],int n,int v)
{
	int left,right,middle;
	left = 0;
	right = n - 1;
	while(left<=right)
	{
		middle = left+(right-left)/2;
		if(array[middle]>v)
		{
			right = middle - 1;
		}else if(array[middle]<v)
		{
			left = middle + 1;
		}else
		{
			return middle;
		}
	}

	return -1;
}
int main()
{
	int a[10]={2,1,3,4,5,6,8,9,10,12};
	quicksort(a,0,9);
	int i = 0;
	int j = 0; 
	findnum(a,10,15,&i,&j);

	return 0;
}