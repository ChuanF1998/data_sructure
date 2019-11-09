#pragma once
typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top; // 栈顶
	int _capacity; // 容量
}Stack;
//初始化栈
void StackInit(Stack* ps);
//销毁栈
void StackDestory(Stack* ps);
//入栈
void StackPush(Stack* ps, STDataType x);
//出栈
void StackPop(Stack* ps);
//获取栈顶元素
STDataType StackTop(Stack* ps);
//检测栈是否为空，空->非0，非空->0
int StackEmpty(Stack* ps);
//获取栈顶元素有效个数
int StackSize(Stack* ps);
void TestStack();