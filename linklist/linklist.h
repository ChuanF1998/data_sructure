#pragma once
#include<stdio.h>

typedef int datatype;//将int重定义为datatype

//定义一个结构体
typedef struct linklist{
	datatype array;
	struct linklist* next;
}linklist;

//定义一个头结点
typedef struct Node{
	linklist* head;
}Node;
//头结点初始化
void init(Node* link);
//头插
void head_insert(Node* link, datatype value);
//尾插
void tail_insert(Node* link, datatype value);
//随机插入
void rondom_insert(Node* link, datatype value);
//头删
void head_eraser(Node* link);
//尾删
void tail_eraser(Node* link);
//查找某个结点
void random_search(Node* link,datatype value);
//打印所有链表的值
void print(Node* link);
//测试
void test();
