#pragma once

#include<cassert>
#include<iostream>
using namespace std;

template<class T>
class Node
{
public:
	T data;
	Node* next;

	//Node()
	//	:data(data)
	//	, next(nullptr)
	//{}
};

template<class T>
class Linklist
{
private:
	Node<T> *_head;
public:
	//构造函数
	Linklist(const T& value)  //有参
		:_head(new Node<T>)
	{
		_head->data = value;
		_head->next = nullptr;
	}
	Linklist()   //无参
		:_head(nullptr)
	{}

	//拷贝构造
	Linklist(const Linklist<T>& L)
		:_head(nullptr)
	{
		if (&L != nullptr){
			if (this != &L){
				Node<T>* p = L._head;
				Node<T>* temp = new Node<T>;
				temp->data = p->data;
				temp->next = nullptr;
				_head = temp;
				Node<T>* e = _head;
				while (p->next != nullptr){
					Node<T>* temp = new Node<T>;
					temp->data = p->next->data;
					temp->next = nullptr;
					e->next = temp;
					e = e->next;
					p = p->next;
				}
			}
		}
	}

	//赋值运算符重载
	Linklist<T>& operator=(const Linklist<T>& L)
	{
		if (&L != nullptr){
			if (this != &L){
				while (_head){
					Node<T>* q = _head;
					_head = _head->next;
					delete q;
				}
				Node<T>* p = L._head;
				Node<T>* temp = new Node<T>;
				temp->data = p->data;
				temp->next = nullptr;
				_head = temp;
				Node<T>* e = _head;
				while (p->next != nullptr){
					Node<T>* temp = new Node<T>;
					temp->data = p->next->data;
					temp->next = nullptr;
					e->next = temp;
					e = e->next;
					p = p->next;
				}
			}
		}
			return *this;
	}

	//头插
	void push_front(const T& value)
	{
		Node<T>* node = new Node<T>;
		node->data = value;
		node->next = _head;
		_head = node;
	}

	//头删
	void pop_front()
	{
		assert(_head != nullptr);
		Node<T>* p = _head;
		_head = _head->next;
		delete p;
		
	}

	//尾插
	void push_back(const T& value)
	{
		Node<T>* node = new Node<T>;
		node->data = value;
		node->next = nullptr;
		if (_head == nullptr){
			_head = node;
		}
		else{
			Node<T>* p = _head;
			while (p->next != nullptr){
				p = p->next;
			}
			p->next = node;
		}
	}

	//尾删
	void pop_back()
	{
		assert(_head != nullptr);
		//一个节点
		if (_head->next == nullptr){
			delete _head;
			_head = nullptr;
		}
		//多个节点
		else{
			Node<T>* p = _head;
			while (p->next->next != nullptr){
				p = p->next;
			}
			delete p->next;
			p->next = nullptr;
		}
	}

	//删除第n个节点
	int erase(const size_t& pos)
	{
		if (pos < 1){
			return 0;
		}
		assert(_head != nullptr);
		size_t n = 1;
		//Node<T>* p = _head;
		//第一个节点单独处理
		if (pos==1){
			pop_front();
				return 1;
		}
		Node<T>* p = _head;
		while (p->next != nullptr){
			++n;
			if (pos == n){
				Node<T>* p1 = p->next;
				p->next = p->next->next;
				delete p1;
				return 1;
			}
			p = p->next;
		}
		return 0;
	}

	////查找第n个节点的值
	//T& search(const size_t pos)const
	//{
	//	assert(_head != nullptr);
	//	size_t n = 0;
	//	Node<T>* p = _head;
	//	while (p != nullptr){
	//		++n;
	//		if (n == pos){
	//			return p->data;
	//		}
	//		p = p->next;
	//	}
	//	return k;
	//}

	//返回节点个数
	size_t Node_num()const
	{
		size_t num = 0;
		Node<T>* p = _head;
		while (p != nullptr){
			num++;
			p = p->next;
		}
		return num;
	}

	//返回第一个节点的值
	T& first_node()const
	{
		assert(_head != nullptr);
		return _head->data;
	}

	//返回最后一个节点的值
	T& last_node()const
	{
		assert(_head != nullptr);
		//一个节点
		if (_head->next == nullptr){
			return _head->data;
		}
		//多个节点
		else{
			Node<T>* p = _head;
			while (p->next->next != nullptr){
				p = p->next;
			}
			return p->next->data;
		}
	}

	//遍历链表
	void print()
	{
		assert(_head != nullptr);
		Node<T>* p = _head;
		while (p != nullptr){
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}

	//链表逆置
	void reverse()
	{
		assert(_head != nullptr);
		if (_head->next == nullptr){
			return;
		}
		Node<T>* p1 = _head;
		Node<T>* p2 = nullptr;
		while (p1 != nullptr){
			Node<T>* p3 = p1->next;
			p1->next = p2;
			p2 = p1;
			p1 = p3;
		}
		_head = p2;
	}

	//析构函数
	~Linklist()
	{
		if (_head){
			while (_head){
				Node<T>* q = _head;
				_head = _head->next;
				delete q;
			}
		}
	}
};