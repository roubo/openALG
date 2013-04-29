/***********************************************
 * 测试插入排序，数值与字符
 * By roubo
 ***********************************************/ 
#include <stdio.h>
#include <string.h>
#include "inssort.h"
/**************
 * 数值比较函数
 *************/
int compare_int(const void *int1, const void *int2)
{
	if(*(const int *)int1 > *(const int *)int2)
		return 1;
	else if(*(const int *)int1 < *(const int *)int2)
		return -1;
	else return 0;
}
/**************
 * 字符比较函数
 **************/
int compare_str(const void *str1, const void *str2)
{
	int ret;
	if((ret = strcmp((const char *)str1,(const char *)str2))>0)
		return 1;
	else if (ret<0)
		return -1;
	else    return 0;
}

/*************
 * 测试
 *************/
int main(int argc, char **argv)
{
	int iarray[10];
	int carray[10] = {'a','c','d','z','x','m','n','h','q','f'};
	int i;
	char *key;
	iarray[0] = 2;	
	iarray[1] = 1;
	iarray[2] = 4;
	iarray[3] = 10;
	iarray[4] = 9;
	iarray[5] = 6;
	iarray[6] = 3;
	iarray[7] = 8;
	iarray[8] = 7;
	iarray[9] = 5;
	printf("Iarray before sort.\n");
	for(i=0;i<10;i++)
	{
		printf("iarray[%d] = %d \n",i, iarray[i]);
	}
	if(inssort(iarray, 10,sizeof(int),compare_int)!=0)
		return 1;
	printf("Iarray after sort.\n");
	for(i=0;i<10;i++)
	{
		printf("iarray[%d] = %d \n",i,iarray[i]);
	}

	key=(char *)malloc(2*sizeof(char));
	*(key+1) = '\0';
	printf("Carray before sort.\n");
	for(i=0;i<10;i++)
	{
		*key=carray[i];
		printf("carray[%d] = %s \n",i, key);
	}
	if(inssort(carray, 10,sizeof(char),compare_int)!=0)
		return 1;
	printf("Carray after sort.\n");
	for(i=0;i<10;i++)
	{
		*key = carray[i];
		printf("carray[%d] = %s \n",i,key);
	}
	return 0;
}
