//邻接表法
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define maxnode 50

//边表节点
typedef struct arc
{
	int adjvex;  // 邻接点域
	struct arc* next; //下一个邻接点
}ArcType;

//顶点表节点
typedef struct
{
	char data[50];  //顶点信息
	ArcType* firstarc;  //指向第一条依附在该顶点边的指针
}VertexType;

typedef struct
{
	VertexType vertexs[maxnode];
	int vexnum; // 顶点数
	int arcnum; //边数
}AdjList;

//找出权值对应的下标
int locatevex(AdjList* s, char arr[])
{
	for (int i = 0; i < s->vexnum; ++i) {
		if (strcmp(s->vertexs[i].data, arr) == 0) {
			return i;
		}
	}
	return -1;
}

//创建
int Built_graph(AdjList* s)
{
	int n;
	int e;
	printf("输入知识点的个数 n 和边数 e：\n");
	scanf("%d", &n);
	scanf("%d", &e);
	s->vexnum = n;
	s->arcnum = e;
	printf("输入知识点：\n");
	for (int i = 0; i < n; ++i) {
		scanf("%s", &s->vertexs[i].data);
		s->vertexs[i].firstarc = NULL;
	}
	printf("输入图中各边：\n"); //边<权值1，权值2>
	char m1[50]; //权值1
	char m2[50]; //权值2
	for (int i = 0; i < e; ++i) {
		scanf("%s", &m1);
		scanf("%s", &m2);
		int v1 = locatevex(s, m1);
		int v2 = locatevex(s, m2);
		ArcType* p1 = (ArcType*)malloc(sizeof(ArcType));
		p1->adjvex = v2;
		p1->next = s->vertexs[v1].firstarc;
		s->vertexs[v1].firstarc = p1;
	}
	return n;
}


int visited[maxnode];
//遍历
void func(AdjList* s, int i)
{
	printf("%s\n", s->vertexs[i].data);
	visited[i] = 1;
	ArcType* p = s->vertexs[i].firstarc;
	while (p) {
		if (visited[p->adjvex] == 0) {
			func(s, p->adjvex);
		}
		p = p->next;
	}
}

void print(AdjList* s , int n)
{
	for (int i = 0; i < maxnode; ++i) {
		visited[i] = 0;
	}
	printf("遍历结果：\n");
	for (int i = 0; i < s->vexnum; ++i) {
		if (!visited[i]) {
			func(s, i);
		}
	}
}

int main()
{
	AdjList s;
	int n = Built_graph(&s);
	print(&s, n);
	return 0;
}