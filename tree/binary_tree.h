#pragma once


typedef char datatype;
typedef struct node{
	datatype value;
	struct node* left;
	struct node* right;
}node;

//创建二叉树
void createTree(node* *p);
//前序遍历
void preTree(node* p);
//中序遍历
void orderTree(node* p);
//后序遍历
void postTree(node* p);
void test();
