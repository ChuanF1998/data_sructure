#include"linklist.h"
#include<malloc.h>
#include<assert.h>

//ͷ����ʼ��
void init(Node* link){
	assert(link != NULL);
	link->head = NULL;
}
//ͷ��
void head_insert(Node* link, datatype value){
	assert(link != NULL);
	linklist* newnode = (linklist*)malloc(sizeof(linklist));
	newnode->array = value;
	newnode->next = link->head;  //�½���next����һ�������׵�ַ
	link->head = newnode;
}
//β��
void tail_insert(Node* link, datatype value){
	assert(link != NULL);
	linklist* newnode = (linklist*)malloc(sizeof(linklist));
	newnode->array = value;
	newnode->next = NULL;
	if (link->head == NULL){  //β��Ҫ�������޽������
		link->head = newnode;
	}
	else{
		linklist* cur = link->head;
		while (cur->next != NULL){
			cur = cur->next;
		}
		cur->next = newnode;
	}
}
//������루��n������,n>=1, n=0ʱ�൱��ͷ�壬�����ǣ�
void random_insert(Node* link, datatype value,datatype n){
	assert(link != NULL);
	//nС��0��ֱ���˳�
	if (n < 1){
		return;
	}
	//n���ڵ���0
	else if (n>0){
		linklist* cur = link->head;
		int m=1;
		while (cur->next != NULL){ //��������������һ����㣬����m��1��ʼȡ
			cur = cur->next;
			m++;
			if (m == n){
				linklist* newnode = (linklist*)malloc(sizeof(linklist));
				newnode->array = value;   //�൱��β�壬ֻ���½���next
				newnode->next = cur->next;//�����һ�����ĵ�ַ
				cur ->next= newnode;
				return;
			}
		}
	}
}
//ͷɾ
void head_eraser(Node* link){
	assert(link != NULL);
	assert(link->head != NULL);  //�ж��Ƿ��н��
	linklist* cur = link->head->next;
	free(link->head);
	link->head = cur;
}
//βɾ
void tail_eraser(Node* link){
	assert(link != NULL);
	assert(link->head != NULL);
	linklist* cur = link->head;
	if (link->head->next == NULL){
		free(link->head);
		link->head = NULL;
	}
	else{
		while (cur->next->next != NULL){
			cur = cur->next;
		}
		free(cur->next);
		cur->next = NULL;
	}
}
//ɾ��ĳ��ֵ
void random_eraser(Node* link, datatype value){
	assert(link != NULL);
	assert(link->head != NULL);
	linklist* cur = link->head;
	if (link->head->array == value){
		linklist* p = link->head->next;
		free(link->head);
		link->head = p;
	}
	else{
		while (cur->next != NULL){
			if (cur->next->array == value){
				linklist* p = cur->next->next;
				free(cur->next);
				cur->next = p;
				return;
			}
			else{
				cur = cur->next;
			}
		}
	}
	return;
}
//��ӡ���������ֵ
void print(Node* link){
	assert(link != NULL);
	linklist* cur = link->head;
	while (cur != NULL){
		printf("%d  ", cur->array);
		cur = cur->next;
	}
}
//����
void test(){
	Node p;
	//ͷ����ʼ��
	init(&p);
	//ͷ��
	head_insert(&p, 2);
	//head_insert(&p, 4);
	//head_insert(&p, 7);
	//β��
	tail_insert(&p, 3);
	tail_insert(&p, 9);
	tail_insert(&p, 6);
	//�������
	random_insert(&p, 8, 2);
	random_insert(&p, 48, 4);
	random_insert(&p, 78, 7);
	random_eraser(&p, 9);
	head_eraser(&p);
	tail_eraser(&p);

	print(&p);

}