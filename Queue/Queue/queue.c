#include"queue.h"
#include<stdio.h>
#include<malloc.h>
#include<assert.h>


//��ʼ������ 
void QueueInit(Queue* q){
	if (q == NULL){
		return;
	}
	q->_front = (QNode*)malloc(sizeof(QNode));
	if (q->_front == NULL||q->_rear==NULL){  //����ռ�ʧ�ܣ�ֱ���˳�
		return;
	}
	q->_rear = q->_front;       //ͷ�����β������ʱ����Ϊ��
	q->_front->_pNext = NULL;
}

// ��β����� (�൱������β�壩
void QueuePush(Queue* q, QDataType data){
	assert(q != NULL);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL){  //�����ڴ�ʧ�ܾ��˳�
		printf("�����ڴ�ʧ��\n");
		return;
	}
	newnode->_data = data;   
	newnode->_pNext = NULL;
	q->_rear->_pNext = newnode;
	q->_rear = newnode;
}

// ��ͷ������ ���൱������ͷɾ��
void QueuePop(Queue* q){
	assert(q != NULL);
	if (q->_front==q->_rear){
		printf("����Ϊ�գ�������ʧ��\n");
		return;
	}
	QNode* cur = q->_front->_pNext->_pNext;
	free(q->_front->_pNext);
	q->_front->_pNext = cur;
	if (cur == q->_rear->_pNext){
		q->_front = q->_rear;
	}
}

// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q){
	assert(q != NULL);
	if (q->_front == q->_rear){
		printf("ջ�գ���ȡʧ��");
		return 0;
	}
	return q->_front->_pNext->_data;
}

// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q){
	assert(q != NULL);
	if (q->_front == q->_rear){
		printf("ջ�գ���ȡʧ��");
		return 0;
	}
	return q->_rear->_data;
}

// ��ȡ��������ЧԪ�ظ��� 
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

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q){
	assert(q != NULL);
	if (q->_front == q->_rear){
		return 1;
	}
	else{
		return 0;
	}
}

// ���ٶ��� 
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
	// ��ʼ������ 
	QueueInit(&q);

	// ��β����� 
	QueuePush(&q, 4);
	QueuePush(&q, 9);
	QueuePush(&q, 5);
	QueuePush(&q, 7);
	//QueueDestroy(&q);

	// ��ͷ������ 
	QueuePop(&q);

	// ��ȡ����ͷ��Ԫ�� 
	printf("%d\n",QueueFront(&q));

	// ��ȡ���ж�βԪ�� 
	printf("%d\n",QueueBack(&q));

	// ��ȡ��������ЧԪ�ظ��� 
	printf("%d\n",QueueSize(&q));

	// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
	printf("%d\n",QueueEmpty(&q));

	// ���ٶ��� 
	QueueDestroy(&q);
}