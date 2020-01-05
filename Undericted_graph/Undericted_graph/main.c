//�ڽӱ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define maxnode 50

//�߱�ڵ�
typedef struct arc
{
	int adjvex;  // �ڽӵ���
	struct arc* next; //��һ���ڽӵ�
}ArcType;

//�����ڵ�
typedef struct
{
	char data[50];  //������Ϣ
	ArcType* firstarc;  //ָ���һ�������ڸö���ߵ�ָ��
}VertexType;

typedef struct
{
	VertexType vertexs[maxnode];
	int vexnum; // ������
	int arcnum; //����
}AdjList;

//�ҳ�Ȩֵ��Ӧ���±�
int locatevex(AdjList* s, char arr[])
{
	for (int i = 0; i < s->vexnum; ++i) {
		if (strcmp(s->vertexs[i].data, arr) == 0) {
			return i;
		}
	}
	return -1;
}

//����
int Built_graph(AdjList* s)
{
	int n;
	int e;
	printf("����֪ʶ��ĸ��� n �ͱ��� e��\n");
	scanf("%d", &n);
	scanf("%d", &e);
	s->vexnum = n;
	s->arcnum = e;
	printf("����֪ʶ�㣺\n");
	for (int i = 0; i < n; ++i) {
		scanf("%s", &s->vertexs[i].data);
		s->vertexs[i].firstarc = NULL;
	}
	printf("����ͼ�и��ߣ�\n"); //��<Ȩֵ1��Ȩֵ2>
	char m1[50]; //Ȩֵ1
	char m2[50]; //Ȩֵ2
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
//����
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
	printf("���������\n");
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