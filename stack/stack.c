#include"stack.h"
#include<stdio.h>
#include<assert.h>
#include<malloc.h>

//��ʼ��ջ
void StackInit(Stack* ps){
	assert(ps != NULL);
	ps->_capacity = 5;   //��������Ϊ5��ջ
	ps->_a = (STDataType*)malloc(sizeof(STDataType)*ps->_capacity);
	ps->_top = -1;  //ջΪ��ʱ��ջ��Ϊ-1
}
//����ջ
void StackDestory(Stack* ps){
	assert(ps != NULL);
	free(ps->_a);
}
//���ջ�Ƿ�Ϊ�գ���->��0���ǿ�->0
int StackEmpty(Stack* ps){
	assert(ps != NULL);
	if (ps->_top == -1){ //ջ��Ϊ1���������Ϊ0
		return 1;
	}
	else{
		return 0;
	}
}
//��ջ
void StackPush(Stack* ps, STDataType x){
	if (ps == NULL){//ջΪ�ջ�ջ����ֱ�ӷ���
		return;
	}
	else if (ps->_top + 1 == ps->_capacity){
		printf("ջ������ջʧ��\n");
		return;
	}
	else{
		ps->_top++;
		ps->_a[ps->_top] = x;
	}
}
//��ջ
void StackPop(Stack* ps){
	if ((ps == NULL)||(ps->_top==-1)){  //ջ�����ڻ�ջΪ�գ�ֱ�ӷ���
		return;
	}
	else{
		ps->_top--;
	}
}
//��ȡջ��Ԫ��
STDataType StackTop(Stack* ps){
	if (ps == NULL){
		return;
	}
	else if(ps->_top==-1){
		printf("ջΪ��\n");
		return;
	}
	return ps->_a[ps->_top];
}

//��ȡջ��Ԫ����Ч����
int StackSize(Stack* ps){
	if (ps == NULL){
		return -1;
	}
	return ps->_top + 1;
}

void TestStack(){
	Stack s;
	StackInit(&s);
	StackPush(&s, 4);
	StackPush(&s, 7);
	StackPush(&s, 8);
	StackPush(&s, 9);
	printf("%d\n", StackTop(&s));
	printf("%d\n", StackSize(&s));
	StackPop(&s);
	printf("%d\n", StackTop(&s));
	printf("%d\n", StackSize(&s));
}