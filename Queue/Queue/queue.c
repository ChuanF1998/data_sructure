#include"queue.h"
#include<stdio.h>
#include<malloc.h>
#include<assert.h>


//初始化队列 
void QueueInit(Queue* q){
	if (q == NULL){
		return;
	}
	q->_front = (QNode*)malloc(sizeof(QNode));
	if (q->_front == NULL||q->_rear==NULL){  //申请空间失败，直接退出
		return;
	}
	q->_rear = q->_front;       //头结点与尾结点相等时队列为空
	q->_front->_pNext = NULL;
}

// 队尾入队列 (相当于链表尾插）
void QueuePush(Queue* q, QDataType data){
	assert(q != NULL);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL){  //申请内存失败就退出
		printf("申请内存失败\n");
		return;
	}
	newnode->_data = data;   
	newnode->_pNext = NULL;
	q->_rear->_pNext = newnode;
	q->_rear = newnode;
}

// 队头出队列 （相当于链表头删）
void QueuePop(Queue* q){
	assert(q != NULL);
	if (q->_front==q->_rear){
		printf("队列为空，出队列失败\n");
		return;
	}
	QNode* cur = q->_front->_pNext->_pNext;
	free(q->_front->_pNext);
	q->_front->_pNext = cur;
	if (cur == q->_rear->_pNext){
		q->_front = q->_rear;
	}
}

// 获取队列头部元素 
QDataType QueueFront(Queue* q){
	assert(q != NULL);
	if (q->_front == q->_rear){
		printf("栈空，获取失败");
		return 0;
	}
	return q->_front->_pNext->_data;
}

// 获取队列队尾元素 
QDataType QueueBack(Queue* q){
	assert(q != NULL);
	if (q->_front == q->_rear){
		printf("栈空，获取失败");
		return 0;
	}
	return q->_rear->_data;
}

// 获取队列中有效元素个数 
int QueueSize(Queue* q){
	assert(q != NULL);
	QNode* cur = q->_front->_pNext;
	int count = 0;
	while (cur != NULL){
		count++;
		cur = cur->_pNext;
	}
	return count;
}

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q){
	assert(q != NULL);
	if (q->_front == q->_rear){
		return 1;
	}
	else{
		return 0;
	}
}

// 销毁队列 
void QueueDestroy(Queue* q){
	assert(q != NULL);
		QNode* cur = q->_front->_pNext;
		while (cur != NULL){
			QNode* next = cur->_pNext;
			free(cur);
			cur = next;
			}
		q->_front = q->_rear;
}

void test(){
	Queue q;
	// 初始化队列 
	QueueInit(&q);

	// 队尾入队列 
	QueuePush(&q, 4);
	QueuePush(&q, 9);
	QueuePush(&q, 5);
	QueuePush(&q, 7);
	//QueueDestroy(&q);

	// 队头出队列 
	QueuePop(&q);

	// 获取队列头部元素 
	printf("%d\n",QueueFront(&q));

	// 获取队列队尾元素 
	printf("%d\n",QueueBack(&q));

	// 获取队列中有效元素个数 
	printf("%d\n",QueueSize(&q));

	// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
	printf("%d\n",QueueEmpty(&q));

	// 销毁队列 
	QueueDestroy(&q);
}