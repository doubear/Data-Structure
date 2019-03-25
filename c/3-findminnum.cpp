#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define maxlen 123456
#define K 100

//堆排序取出最小的前几个
void swap(int *a,int *b)
{
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}

void heapjust(int *array,int i,int length)
{
	int child,temp;
	for(temp = array[i];2*i+1<length;i = child)
	{
		child = 2*i+1;
		if(child<length-1&&array[child+1]<array[child])
			child++;
		if(temp > array[i])
			array[i] =array[child];
		else
			break;
		array[child] = temp;
	}
}

int getmin(int *array,int Length,int k)
{
	int min=array[0];
	swap(&array[0],&array[Length-1]);
	
	int child,temp;
	int i=0,j=k-1;
	for (temp=array[0]; j>0 && 2*i+1<Length; --j,i=child)
	{
		child = 2*i+1;
		if(child<Length-1 && array[child+1]<array[child])
			child++;
		if (temp>array[child])
			array[i]=array[child];
		else
			break;
		array[child]=temp;
	}
	
	return min;
}

void Kmin(int array[] , int Length , int k)
{
	for(int i=Length/2-1;i>=0;--i) 
		//初始建堆，时间复杂度为O(n)
		heapjust(array,i,Length);
	
	int j=Length;
	for( int i=k;i>0;--i,--j) 
		//k次循环，每次循环的复杂度最多为k次交换，复杂度为o(k^2)
	{
		int min=getmin(array,j,i);
		printf("%d,", min);
	}
}


//三-二 随机选取枢纽元，寻找最小k个数
int my_rand(int low,int high)
{
	int size =high-low+1;
	return low+rand()%size;
}

int q_select(int *a,int k,int left,int right)
{
	if(k>right||k<left)
	{
		return 0;
	}
	int midindex = (left+right)/2;
	if(a[left]<a[midindex])
		swap(a+left,a+midindex);
	if(a[right]<a[midindex])
		swap(a+right,a+midindex);
	if(a[right]<a[left])
		swap(a+left,a+right);
	int pivot = a[left];
	printf("%d\n",pivot );

	int i = left;
	int j = right;
	//此循环负责把小的放前面
	for(;;)
	{
		while(a[i]<pivot)
			i++;
        while(a[j] >pivot)
            j--;
		//a[i] >= pivot, a[j] <= pivot
        if (i < j){
        	printf("%d%d\n",i,j);
        	swap(a+i,a+j);
        }
        else 
        	break;
	}

	//swap(a+i,a+right);
	if (i == k)
	{
		for(int m=0;m<k;m++)
		{
			printf("%d ",a[m]);
		}
		return 1;
	}
	else if (i > k)
		return q_select(a, k, left, i-1);
	else return q_select(a, k, i+1, right);
}

int main()
{
	int array[maxlen];
	for(int i=maxlen;i>0;--i)
		array[maxlen-i] = i;
	
	Kmin(array,maxlen,K);
	
	int i;  
    int a[] = {7, 8, 9, 54, 6, 4, 11, 1, 2, 33};  
    q_select(a,2, 0, sizeof(a) / sizeof(int) - 1);
	return 0;
}