#include <iostream>
#include <time.h>
#include <assert.h>
using namespace std;
 
const int size = 10000000;
int num[size];
 
int main()
{
	int n;
	FILE *fp = fopen("data.txt", "w");
	assert(fp);
 
	for (n = 1; n <= size; n++)  
		//之前此处写成了n=0;n<size。导致下面有一段小程序的测试数据出现了0，特此订正。
		num[n] = n;
	srand((unsigned)time(NULL));
	int i, j;
 
	for (n = 0; n < size; n++)
	{
		i = (rand() * RAND_MAX + rand()) % 10000000;
		j = (rand() * RAND_MAX + rand()) % 10000000;
		swap(num[i], num[j]);
	}
 
	for (n = 0; n < size; n++)
		fprintf(fp, "%d ", num[n]);
	fclose(fp);
	return 0;
}