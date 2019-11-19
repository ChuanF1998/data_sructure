#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
//����һ��ͨѶ¼����
typedef struct communicate{
	char name[20];
	char sex[10];
	char num[15];
}com;
//����һ��ͨѶ¼
typedef struct note{
	com* array;    //ͨѶ¼�д�ĸ���
	int capacity;  //����
	int size;     //��Ч����
}note;
//ͨѶ¼��ʼ��
void note_Init(note* seq){
	assert(seq != NULL);  //��������ͨѶ¼��Ϊ��
	seq->capacity = 5;   //������һ������Ϊ5�ģ������������ã�
	seq->array = (com*)malloc(sizeof(com)*seq->capacity); //�����ڴ�ռ�
	seq->size = 0;  //��Ч����Ϊ0
}
//����
void note_destory(note* seq){
	assert(seq != NULL);
	free(seq->array);
}
//�ж�+����
void note_check(note* seq){
	if (seq->size < seq->capacity){  //��Ч����С��������������
		return;
	}
	else if (seq->size == seq->capacity){  
		int newcapacity = seq->capacity + 2;  
		com* newarray = (com*)realloc(seq->array,sizeof(com)*newcapacity);
		seq->array = newarray;
		seq->capacity = newcapacity;
	}
}

//��Ӻ���
void note_insert(note* seq){
	note_check(seq);      //���ж�����
	printf("������������");
	scanf("%s", seq->array[seq->size].name);
	printf("\n");
	printf("�������Ա�");
	scanf("%s", seq->array[seq->size].sex);
	printf("\n");
	printf("������ѧ�ţ�");
	scanf("%s", seq->array[seq->size].num);
	printf("\n");
	seq->size++;
	printf("��ӳɹ���\n");
}

//����(������)
void name_search(note* seq){
	assert(seq->size > 0);  
	char sname[20];
	printf("����������:\n");
	scanf("%s", sname);
	for (int i = 0; i < seq->size; i++){
		if (strcmp(sname,seq->array[i].name)==0){
			printf("�ҵ��˸���ϵ�ˣ�\n");
			printf("%s  %s  %s \n", seq->array[i].name,
				seq->array[i].sex, seq->array[i].num);
			return;
		}

	}
		printf("δ�ҵ���Ч����\n");
		
}
//ɾ��
void note_eraser(note* seq){
	assert(seq ->size> 0);
	printf("��������ɾ�����ˣ�\n");
	char sname[20];
	scanf("%s",sname);
	
	for (int i = 0; i < seq->size; i++){
		if (strcmp(sname, seq->array[i].name) == 0){
			for (int j = i; j < seq->size-1; j++){
				seq->array[j] = seq->array[j+1];
			}
			seq->size--;
		}
		else{
			printf("δ�ҵ���Ч���ݣ�ɾ��ʧ�ܣ�\n");
		}
	}
}

//��ӡ
void note_print(note* seq){
	assert(seq->size > 0);
	for (int i = 0; i < seq->size; i++){
		printf("%s\t%s\t%s\t ", seq->array[i].name, 
			seq->array[i].sex, seq->array[i].num);
		printf("\n");
	}
}
void menu(){
	printf("*********************\n");
	printf("   1.�����ϵ��\n");
	printf("   2.ɾ����ϵ��\n");
	printf("   3.������������ϵ��\n");
	printf("   4.�����������ϵ��\n");
	printf("   5.��ӡ��ϵ��\n");
	printf("   6.�˳�����\n");
}

int main(){
	menu();
	note p;
	note_Init(&p);
	while (true)
	{
		int i;
		scanf("%d", &i);
		if (i == 1){
			note_insert(&p);
		}
		else if (i==2){
			note_print(&p);
		}
		else if (i == 3){
			name_search(&p);
		}
		else if(i==4){
			note_eraser(&p);
		}
		else if (i == 6){
			break;
		}
		else{
			printf("����ѡ������\n");
		}

	}
	system("pause");
	return 0;
}