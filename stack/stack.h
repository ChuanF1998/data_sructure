#pragma once
typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top; // ջ��
	int _capacity; // ����
}Stack;
//��ʼ��ջ
void StackInit(Stack* ps);
//����ջ
void StackDestory(Stack* ps);
//��ջ
void StackPush(Stack* ps, STDataType x);
//��ջ
void StackPop(Stack* ps);
//��ȡջ��Ԫ��
STDataType StackTop(Stack* ps);
//���ջ�Ƿ�Ϊ�գ���->��0���ǿ�->0
int StackEmpty(Stack* ps);
//��ȡջ��Ԫ����Ч����
int StackSize(Stack* ps);
void TestStack();