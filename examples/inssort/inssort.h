#ifndef INSSORT_H
#define INSSORT_H

int inssort(void *data, int size, int esize, int(*compare)(const void *key1, const void *key2));
#endif
