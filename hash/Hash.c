//˳�������������������̽����ɢ�л�����ַ��
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>

typedef char DTtype;
typedef struct node
{
	DTtype num[15];
	char name[20];
	char addrass[30];
	struct node* next;
}node;
typedef struct Hash
{
	node* array;
	int size;
}Hash;


int ha_value(DTtype key[], int p)
{
	int i = 0;
	int j = 0;
	while (key[i] != '\0'){
		j += key[i] - '0';
		i++;
	}
	return j%p;
}

//ɢ�г�ʼ��
void init(Hash* p, int q)
{
	assert(p != NULL);
	p->array = (node*)malloc(sizeof(node)*q);
	p->size = q;
	for (int i = 0; i < p->size; i++){
		p->array[i].next = NULL;
	}
}
//����(ͷ��)
void insert(Hash* p)
{
	assert(p != NULL);
	node *k = (node*)malloc(sizeof(node));
	k->next = NULL;
	printf("������������\n");
	scanf("%s", k->name);
	printf("������绰��\n");
	scanf("%s", k->num);
	printf("�������ַ��\n");
	scanf("%s", k->addrass);
	int value = ha_value(k->num, p->size);
	node* temp = p->array[value].next;
	while (temp != NULL){   //�ж��Ƿ����ظ���������
		if (temp->num == k->num){
			free(k);
			printf("�ظ����룬����ʧ�ܣ�\n");
			return;
		}
	}
	k->next = p->array[value].next;
	p->array[value].next = k;
}
//����
void search(Hash* p)
{
	assert(p != NULL);
	DTtype x[12];
	printf("��������Ҫ���ҵĺ��룺");
	scanf("%s", x);
	printf("\n");
	int value = ha_value(x, p->size);
	node* temp = p->array[value].next;
	while (temp != NULL){
		if (strcmp(temp->num, x)==0){
			printf("%s ", temp->name);
			printf("%s ", temp->num);
			printf("%s ", temp->addrass);
			return;
		}
		temp = temp->next;
	}
	printf("����ʧ��\n");
}
//��ʾ
void print(Hash* p)
{
	assert(p != NULL);
	for (int i = 0; i < p->size; i++){
		printf("%d ", i);
		node* temp = p->array[i].next;
		while (temp != NULL){
			printf("%s ", temp->name);
			printf("%s ", temp->num);
			printf("%s ", temp->addrass);
			temp = temp->next;
		}
		printf("\n");
	}
}
//�˵�
void menu()
{
	printf("*************************\n");
	printf("\t1.����\t\n");
	printf("\t2.����\t\n");
	printf("\t3.��ʾ\t\n"); 
	printf("\t4.\t\n");
	printf("*************************\n");
}
int main()
	{
		Hash p;
		int q = 10;
		init(&p, q);
		//char n;
		while (1){
			menu();
			printf("������ѡ��:");
			int n;
			scanf("%d", &n);
			//getchar();
			if (n == 1){
				insert(&p);
			}
			else if (n == 2){
				search(&p);
			}
			else if (n == 3){
				print(&p);
			}
			else{
				printf("��������\n");
			}
			system("pause");
			system("cls");
		}

		return 0;
	}


