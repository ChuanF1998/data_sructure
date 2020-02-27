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
	//���캯��
	Linklist(const T& value)  //�в�
		:_head(new Node<T>)
	{
		_head->data = value;
		_head->next = nullptr;
	}
	Linklist()   //�޲�
		:_head(nullptr)
	{}

	//��������
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

	//��ֵ���������
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

	//ͷ��
	void push_front(const T& value)
	{
		Node<T>* node = new Node<T>;
		node->data = value;
		node->next = _head;
		_head = node;
	}

	//ͷɾ
	void pop_front()
	{
		assert(_head != nullptr);
		Node<T>* p = _head;
		_head = _head->next;
		delete p;
		
	}

	//β��
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

	//βɾ
	void pop_back()
	{
		assert(_head != nullptr);
		//һ���ڵ�
		if (_head->next == nullptr){
			delete _head;
			_head = nullptr;
		}
		//����ڵ�
		else{
			Node<T>* p = _head;
			while (p->next->next != nullptr){
				p = p->next;
			}
			delete p->next;
			p->next = nullptr;
		}
	}

	//ɾ����n���ڵ�
	int erase(const size_t& pos)
	{
		if (pos < 1){
			return 0;
		}
		assert(_head != nullptr);
		size_t n = 1;
		//Node<T>* p = _head;
		//��һ���ڵ㵥������
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

	////���ҵ�n���ڵ��ֵ
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

	//���ؽڵ����
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

	//���ص�һ���ڵ��ֵ
	T& first_node()const
	{
		assert(_head != nullptr);
		return _head->data;
	}

	//�������һ���ڵ��ֵ
	T& last_node()const
	{
		assert(_head != nullptr);
		//һ���ڵ�
		if (_head->next == nullptr){
			return _head->data;
		}
		//����ڵ�
		else{
			Node<T>* p = _head;
			while (p->next->next != nullptr){
				p = p->next;
			}
			return p->next->data;
		}
	}

	//��������
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

	//��������
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

	//��������
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