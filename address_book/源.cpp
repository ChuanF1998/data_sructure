#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
//定义一个通讯录内容
typedef struct communicate{
	char name[20];
	char sex[10];
	char num[15];
}com;
//定义一个通讯录
typedef struct note{
	com* array;    //通讯录中存的个体
	int capacity;  //容量
	int size;     //有效个数
}note;
//通讯录初始化
void note_Init(note* seq){
	assert(seq != NULL);  //传进来的通讯录不为空
	seq->capacity = 5;   //先设置一个容量为5的（可以随意设置）
	seq->array = (com*)malloc(sizeof(com)*seq->capacity); //申请内存空间
	seq->size = 0;  //有效个数为0
}
//销毁
void note_destory(note* seq){
	assert(seq != NULL);
	free(seq->array);
}
//判断+扩容
void note_check(note* seq){
	if (seq->size < seq->capacity){  //有效个数小于容量，不扩容
		return;
	}
	else if (seq->size == seq->capacity){  
		int newcapacity = seq->capacity + 2;  
		com* newarray = (com*)realloc(seq->array,sizeof(com)*newcapacity);
		seq->array = newarray;
		seq->capacity = newcapacity;
	}
}

//添加号码
void note_insert(note* seq){
	note_check(seq);      //先判断容量
	printf("请输入姓名：");
	scanf("%s", seq->array[seq->size].name);
	printf("\n");
	printf("请输入性别：");
	scanf("%s", seq->array[seq->size].sex);
	printf("\n");
	printf("请输入学号：");
	scanf("%s", seq->array[seq->size].num);
	printf("\n");
	seq->size++;
	printf("添加成功！\n");
}

//查找(按姓名)
void name_search(note* seq){
	assert(seq->size > 0);  
	char sname[20];
	printf("请输入姓名:\n");
	scanf("%s", sname);
	for (int i = 0; i < seq->size; i++){
		if (strcmp(sname,seq->array[i].name)==0){
			printf("找到了该联系人：\n");
			printf("%s  %s  %s \n", seq->array[i].name,
				seq->array[i].sex, seq->array[i].num);
			return;
		}

	}
		printf("未找到有效数据\n");
		
}
//删除
void note_eraser(note* seq){
	assert(seq ->size> 0);
	printf("请输入想删除的人：\n");
	char sname[20];
	scanf("%s",sname);
	
	for (int i = 0; i < seq->size; i++){
		if (strcmp(sname, seq->array[i].name) == 0){
			for (int j = i; j < seq->size-1; j++){
				seq->array[j] = seq->array[j+1];
			}
			seq->size--;
		}
		else{
			printf("未找到有效数据，删除失败！\n");
		}
	}
}

//打印
void note_print(note* seq){
	assert(seq->size > 0);
	for (int i = 0; i < seq->size; i++){
		printf("%s\t%s\t%s\t ", seq->array[i].name, 
			seq->array[i].sex, seq->array[i].num);
		printf("\n");
	}
}
void menu(){
	printf("*********************\n");
	printf("   1.添加联系人\n");
	printf("   2.删除联系人\n");
	printf("   3.按姓名查找联系人\n");
	printf("   4.按号码查找联系人\n");
	printf("   5.打印联系人\n");
	printf("   6.退出程序\n");
}

int main(){
	menu();
	note p;
	note_Init(&p);
	while (true)
	{
		int i;
		scanf("%d", &i);
		if (i == 1){
			note_insert(&p);
		}
		else if (i==2){
			note_print(&p);
		}
		else if (i == 3){
			name_search(&p);
		}
		else if(i==4){
			note_eraser(&p);
		}
		else if (i == 6){
			break;
		}
		else{
			printf("输入选项有误\n");
		}

	}
	system("pause");
	return 0;
}