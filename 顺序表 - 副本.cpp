#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#define SEQ_INIT_SUZE 10//初始容量
#define SEQ_INC_SIZE 2  //
typedef int ElemType;
ElemType* data1 = NULL;
typedef struct
{
	ElemType* data;
	int capacity;//容量；
	int cursize;//元素个数；
}Seqlist;
int re_capacity(Seqlist* plist)//返回容量；
{
	assert(plist);
	return plist->capacity;
}
int re_cursize(Seqlist* plist)//返回现存元素个数；
{
	assert(plist);
	return plist->cursize;
}
int add_capacity(Seqlist* plist)//判断是否增容；
{
	assert(plist);
	if (re_capacity(plist) == re_cursize(plist))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void Judge_add_capacity(Seqlist* plist)//判断是否增容；
{
	if (add_capacity(plist))
	{
		ElemType* data = (ElemType*)realloc(plist->data, plist->capacity * SEQ_INC_SIZE);
		plist->capacity *= SEQ_INC_SIZE;
		if (NULL == data)
		{
			printf("增容失败");
		}
		//free(plist->data);
		//plist->data = data1;
	}
}
void Init(Seqlist* plist)//结构体初始化；
{
	assert(plist);
	plist->capacity = SEQ_INIT_SUZE;
	plist->cursize = 0;
	plist->data = (ElemType*)malloc(sizeof(ElemType) * plist->capacity);
	if (plist->data == NULL)
	{
		exit(EXIT_FAILURE);
	}
}
void Depo_data(Seqlist* plist)//顺序表填充数据；
{
	assert(plist);
	for (int i = 0; i < 8; i++)
	{
		plist->data[i] = i;
		plist->cursize++;
	}
}
int Insert_data(Seqlist* plist)//插入一个数据；
{
	assert(plist);
	int n, num;//n——位置，num——添加的数据；
	printf("请输入插入位置 n，插入数据 num\n");
	scanf("%d %d", &n, &num);
	if (n > plist->cursize - 1 || n < 0)
	{
		printf("插入位置错误\n");
		return 0;
	}
	for (int i = plist->cursize - 1; i >= n; i--)
	{
		plist->data[i + 1] = plist->data[i];
	}
	plist->data[n] = num;
	plist->cursize++;
	Judge_add_capacity(plist);
}
void Insert_data_head(Seqlist* plist)//首行插入；
{
	assert(plist);
	int num = 0;
	printf("在首行插入一个数据，请输入一个数据：\n");
	scanf("%d", &num);
	for (int i = plist->cursize - 1; i >= 0; i--)
	{
		plist->data[i + 1] = plist->data[i];
	}
	plist->data[0] = num;
	plist->cursize++;
	Judge_add_capacity(plist);
}
void Insert_data_back(Seqlist* plist)//末尾插入；
{
	assert(plist);
	int num = 0;
	printf("在尾行插入一个数据，请输入一个数据：\n");
	scanf("%d", &num);
	plist->data[plist->cursize] = num;
	plist->cursize++;
	Judge_add_capacity(plist);
}
void print(Seqlist* plist)
{
	assert(plist);
	for (int i = 0; i < plist->cursize; i++)
	{
		printf("%d ", plist->data[i]);
	}
	printf("\n");
	printf("现存元素数：%d\n", plist->cursize);
	printf("顺序表容量：%d\n", plist->capacity);
}
int dele_data(Seqlist* plist)//删除指定坐标的数据；
{
	assert(plist);
	int pos = 0;
	printf("请输入删除数据的下标\n");
	scanf("%d", &pos);
	if (pos > plist->cursize || pos < 0)
	{
		printf("删除错误\n");
		return 0;
	}
	for (int i = pos; i < plist->cursize - 1; i++)
	{
		plist->data[i] = plist->data[i + 1];
	}
	plist->cursize--;
}
void seek_data(Seqlist* plist)//查找一个数据；
{
	assert(plist);
	int data_num = 0;
	int i = 0;
	printf("请输入需要查找的数据\n");
	scanf("%d", &data_num);
	for (i = 0; i <= plist->cursize - 1; i++)
	{
		if (plist->data[i] == data_num)
		{
			printf("下表为%d\n", i);
			break;
		}
	}
	if (plist->data[i] != data_num)
	{
		printf("没找到\n");
	}
}
int change_data(Seqlist*plist)//改动指定的数据；
{
	assert(plist);
	int pos = 0;
	ElemType num;
	printf("请输入需要修改的数据的下表 pos ,和改动后的数据 num \n");
	scanf("%d %d", &pos,&num);
	if (pos > plist->cursize || pos < 0)
	{
		printf("修改错误\n");
		return 0;
	}
	plist->data[pos] = num;
}
int main()
{
	Seqlist plist = { 0 };
	Init(&plist);
	Depo_data(&plist);
	print(&plist);
	Insert_data(&plist);
	print(&plist);
	Insert_data_head(&plist);
	print(&plist);
	Insert_data_back(&plist);
	print(&plist);
	seek_data(&plist);
	dele_data(&plist);
	print(&plist);
	change_data(&plist);
	print(&plist);
	return 0;
}