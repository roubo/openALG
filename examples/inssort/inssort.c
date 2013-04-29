#include <stdio.h>
#include <string.h>

#include "inssort.h"

int inssort(void *data, int size, int esize, int(*compare)(const void *key1, const void *key2))
{
	char *a = data;//�൱��ָ����data�ĵ�һ���ֽ�
	void *key;//�м����,��������һ��Ԫ��
	int i,j;
	if((key = (char *)malloc(sizeof(esize))) == NULL)
		return -1;
	for(i=1;i<size;i++)
	{
		memcpy(key,&a[i*esize],esize);//key<=a[i*esize]
		j=i-1;//ָ��ǰһ��Ԫ�أ��Ӹ�Ԫ�ؿ�ʼ��ǰ����
		while(j>=0 && compare(key,&a[j*esize])<0)//ֻҪ����δ��ͷ����δ�ҵ���key��С�������
		{
			memcpy(&a[(j+1)*esize], &a[j*esize], esize);//��������һ��λ�ã���ǰֵ����һ��������key��
			j--;
			
		}
		memcpy(&a[(j+1)*esize],key,esize);//key������ȷλ�ӣ�һ�����ݲ������
	}
	free(key);
	return 0;
}
