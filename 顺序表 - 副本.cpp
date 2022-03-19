#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#define SEQ_INIT_SUZE 10//��ʼ����
#define SEQ_INC_SIZE 2  //
typedef int ElemType;
ElemType* data1 = NULL;
typedef struct
{
	ElemType* data;
	int capacity;//������
	int cursize;//Ԫ�ظ�����
}Seqlist;
int re_capacity(Seqlist* plist)//����������
{
	assert(plist);
	return plist->capacity;
}
int re_cursize(Seqlist* plist)//�����ִ�Ԫ�ظ�����
{
	assert(plist);
	return plist->cursize;
}
int add_capacity(Seqlist* plist)//�ж��Ƿ����ݣ�
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
void Judge_add_capacity(Seqlist* plist)//�ж��Ƿ����ݣ�
{
	if (add_capacity(plist))
	{
		ElemType* data = (ElemType*)realloc(plist->data, plist->capacity * SEQ_INC_SIZE);
		plist->capacity *= SEQ_INC_SIZE;
		if (NULL == data)
		{
			printf("����ʧ��");
		}
		//free(plist->data);
		//plist->data = data1;
	}
}
void Init(Seqlist* plist)//�ṹ���ʼ����
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
void Depo_data(Seqlist* plist)//˳���������ݣ�
{
	assert(plist);
	for (int i = 0; i < 8; i++)
	{
		plist->data[i] = i;
		plist->cursize++;
	}
}
int Insert_data(Seqlist* plist)//����һ�����ݣ�
{
	assert(plist);
	int n, num;//n����λ�ã�num������ӵ����ݣ�
	printf("���������λ�� n���������� num\n");
	scanf("%d %d", &n, &num);
	if (n > plist->cursize - 1 || n < 0)
	{
		printf("����λ�ô���\n");
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
void Insert_data_head(Seqlist* plist)//���в��룻
{
	assert(plist);
	int num = 0;
	printf("�����в���һ�����ݣ�������һ�����ݣ�\n");
	scanf("%d", &num);
	for (int i = plist->cursize - 1; i >= 0; i--)
	{
		plist->data[i + 1] = plist->data[i];
	}
	plist->data[0] = num;
	plist->cursize++;
	Judge_add_capacity(plist);
}
void Insert_data_back(Seqlist* plist)//ĩβ���룻
{
	assert(plist);
	int num = 0;
	printf("��β�в���һ�����ݣ�������һ�����ݣ�\n");
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
	printf("�ִ�Ԫ������%d\n", plist->cursize);
	printf("˳���������%d\n", plist->capacity);
}
int dele_data(Seqlist* plist)//ɾ��ָ����������ݣ�
{
	assert(plist);
	int pos = 0;
	printf("������ɾ�����ݵ��±�\n");
	scanf("%d", &pos);
	if (pos > plist->cursize || pos < 0)
	{
		printf("ɾ������\n");
		return 0;
	}
	for (int i = pos; i < plist->cursize - 1; i++)
	{
		plist->data[i] = plist->data[i + 1];
	}
	plist->cursize--;
}
void seek_data(Seqlist* plist)//����һ�����ݣ�
{
	assert(plist);
	int data_num = 0;
	int i = 0;
	printf("��������Ҫ���ҵ�����\n");
	scanf("%d", &data_num);
	for (i = 0; i <= plist->cursize - 1; i++)
	{
		if (plist->data[i] == data_num)
		{
			printf("�±�Ϊ%d\n", i);
			break;
		}
	}
	if (plist->data[i] != data_num)
	{
		printf("û�ҵ�\n");
	}
}
int change_data(Seqlist*plist)//�Ķ�ָ�������ݣ�
{
	assert(plist);
	int pos = 0;
	ElemType num;
	printf("��������Ҫ�޸ĵ����ݵ��±� pos ,�͸Ķ�������� num \n");
	scanf("%d %d", &pos,&num);
	if (pos > plist->cursize || pos < 0)
	{
		printf("�޸Ĵ���\n");
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