#pragma once
#include<stdio.h>

typedef int datatype;//��int�ض���Ϊdatatype

//����һ���ṹ��
typedef struct linklist{
	datatype array;
	struct linklist* next;
}linklist;

//����һ��ͷ���
typedef struct Node{
	linklist* head;
}Node;
//ͷ����ʼ��
void init(Node* link);
//ͷ��
void head_insert(Node* link, datatype value);
//β��
void tail_insert(Node* link, datatype value);
//�������
void rondom_insert(Node* link, datatype value);
//ͷɾ
void head_eraser(Node* link);
//βɾ
void tail_eraser(Node* link);
//����ĳ�����
void random_search(Node* link,datatype value);
//��ӡ���������ֵ
void print(Node* link);
//����
void test();
