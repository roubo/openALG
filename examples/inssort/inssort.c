#include <stdio.h>
#include <string.h>

#include "inssort.h"

int inssort(void *data, int size, int esize, int(*compare)(const void *key1, const void *key2))
{
	char *a = data;//相当于指向了data的第一个字节
	void *key;//中间变量,用来放置一个元素
	int i,j;
	if((key = (char *)malloc(sizeof(esize))) == NULL)
		return -1;
	for(i=1;i<size;i++)
	{
		memcpy(key,&a[i*esize],esize);//key<=a[i*esize]
		j=i-1;//指向前一个元素，从该元素开始往前遍历
		while(j>=0 && compare(key,&a[j*esize])<0)//只要遍历未到头，或未找到比key更小的则继续
		{
			memcpy(&a[(j+1)*esize], &a[j*esize], esize);//大数后退一个位置，当前值还有一个副本在key中
			j--;
			
		}
		memcpy(&a[(j+1)*esize],key,esize);//key插入正确位子，一个数据插入完成
	}
	free(key);
	return 0;
}
