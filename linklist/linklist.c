#include"linklist.h"
#include<malloc.h>
#include<assert.h>

//头结点初始化
void init(Node* link){
	assert(link != NULL);
	link->head = NULL;
}
//头插
void head_insert(Node* link, datatype value){
	assert(link != NULL);
	linklist* newnode = (linklist*)malloc(sizeof(linklist));
	newnode->array = value;
	newnode->next = link->head;  //新结点的next域存第一个结点的首地址
	link->head = newnode;
}
//尾插
void tail_insert(Node* link, datatype value){
	assert(link != NULL);
	linklist* newnode = (linklist*)malloc(sizeof(linklist));
	newnode->array = value;
	newnode->next = NULL;
	if (link->head == NULL){  //尾插要考虑有无结点的情况
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
//随机插入（第n个结点后,n>=1, n=0时相当于头插，不考虑）
void random_insert(Node* link, datatype value,datatype n){
	assert(link != NULL);
	//n小于0，直接退出
	if (n < 1){
		return;
	}
	//n大于等于0
	else if (n>0){
		linklist* cur = link->head;
		int m=1;
		while (cur->next != NULL){ //隐含链表至少有一个结点，所以m从1开始取
			cur = cur->next;
			m++;
			if (m == n){
				linklist* newnode = (linklist*)malloc(sizeof(linklist));
				newnode->array = value;   //相当于尾插，只是新结点的next
				newnode->next = cur->next;//域存下一个结点的地址
				cur ->next= newnode;
				return;
			}
		}
	}
}
//头删
void head_eraser(Node* link){
	assert(link != NULL);
	assert(link->head != NULL);  //判断是否有结点
	linklist* cur = link->head->next;
	free(link->head);
	link->head = cur;
}
//尾删
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
//删除某个值
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
//打印所有链表的值
void print(Node* link){
	assert(link != NULL);
	linklist* cur = link->head;
	while (cur != NULL){
		printf("%d  ", cur->array);
		cur = cur->next;
	}
}
//测试
void test(){
	Node p;
	//头结点初始化
	init(&p);
	//头插
	head_insert(&p, 2);
	//head_insert(&p, 4);
	//head_insert(&p, 7);
	//尾插
	tail_insert(&p, 3);
	tail_insert(&p, 9);
	tail_insert(&p, 6);
	//随机插入
	random_insert(&p, 8, 2);
	random_insert(&p, 48, 4);
	random_insert(&p, 78, 7);
	random_eraser(&p, 9);
	head_eraser(&p);
	tail_eraser(&p);

	print(&p);

}