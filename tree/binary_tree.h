#pragma once


typedef char datatype;
typedef struct node{
	datatype value;
	struct node* left;
	struct node* right;
}node;

//����������
void createTree(node* *p);
//ǰ�����
void preTree(node* p);
//�������
void orderTree(node* p);
//�������
void postTree(node* p);
void test();
