#include"binary_tree.h"
#define _CRT_SECURE_NO_WARNINGS
#include<assert.h>
#include<stdio.h>
#include<malloc.h>

void createTree(node** p){
	//assert(p != NULL);
	datatype str;
	scanf("%c", &str);
	if (str == '#'){
		*p = NULL;
	}
	else{
		*p = (node*)malloc(sizeof(node));
		(*p)->value = str;   
		createTree(&(*p)->left);
		createTree(&(*p)->right);
	}
}

//前序遍历
void preTree(node* p){
	if (p == NULL){
		return;
	}
	printf("%c  ", p->value);
	preTree(p->left);
	preTree(p->right);
}
//中序遍历
void orderTree(node* p){
	if (p == NULL){
		return;
	}
	preTree(p->left);
	printf("%c  ", p->value);
	preTree(p->right);
}
//后序遍历
void postTree(node* p){
	if (p == NULL){
		return;
	}
	postTree(p->left);
	postTree(p->right);
	printf("%c  ", p->value);
}
void test(){
	node *p;
	createTree(&p);
	preTree(p);
	printf("\n");
	orderTree(p);
	printf("\n");
	postTree(p);
	printf("\n");
}