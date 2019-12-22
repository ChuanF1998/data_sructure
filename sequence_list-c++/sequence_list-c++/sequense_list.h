#pragma once

#include<iostream>
#include<cassert>
using namespace std;

template<class T>
class Seqlist
{
private:
	T* _array;
	size_t _capacity;//����
	size_t _size;//��Ч����
public:
	typedef T* iterator;
public:
	//���캯��
	Seqlist(size_t capacity = 5)
		:_array(new T[capacity])
		, _capacity(capacity)
		, _size(0)
	{}

	//�������캯��
	Seqlist(const Seqlist<T>& s)
		:_array(nullptr)
		, _capacity(0)
		, _size(0)
	{
			T* a = new T[s._capacity];
			for (size_t i = 0; i < s.size(); i++){
				a[i] = s._array[i];
			}
			_array = a;
			_capacity = s.capacity();
			_size = s.size();
	}

	//��ֵ���������
	Seqlist<T>& operator = (const Seqlist<T>& s)
	{
		if (s != nullptr){
			if (this != s){
				if (this != s){
					T* a = new T[s._capacity];
					for (size_t i = 0; i < s.size(); i++){
						_array[i] = s._array[i];
					}
					delete[] _array;
					_array = a;
					_capacity = s.capacity();
					_size = s.size();
				}
			}
		}
		return *this;
	}

	//����
	void reverse(){
			size_t newcapacity = _capacity * 2;
			T* newarray = new T[newcapacity];
			for (size_t i = 0; i < _size; i++){
				newarray[i] = _array[i];
			}
			delete[] _array;
			_array = newarray;
			_capacity = newcapacity;
	}

	//iterator begin()
	//{
	//	 return _array;
	//}
	//iterator end()
	// {
	//	 return _array+sizeof(T)*_size;
	// }


	//����Ԫ�ظ���
	size_t size()const
	{
		return _size;
	}

	//��������
	size_t capacity()const
	{
		return _capacity;
	}

	//β��
	void push_back(const T& value)
	{
		//�Ƿ���Ҫ����
		if (_size == _capacity){
			reverse();
		}
		_array[_size] = value;
		_size++;
	}

	//βɾ
	void pop_back()
	{
		assert(_size > 0);
		_size--;
	}

	//�������
	void insert(size_t pos,const T& value)
	{
		assert(pos <= _capacity);
		assert(pos <= _size);//�жϲ���λ���Ƿ�Խ��
		//�Ƿ���Ҫ����
		if (_size == _capacity){
			reverse();   
		}
		size_t s = size();
		while (s > pos){
			_array[s] = _array[s-1];
			s--;
		}
		_array[pos] = value;
		_size++;
	}

	//���ɾ��
	void erase(size_t pos)
	{
		assert(pos < _size);
		size_t s = size();
		while (pos+1< s){
			_array[pos] = _array[pos+1];
			pos++;
		}
		_size--;
	}

	//���±����
	T& search(size_t pos)
	{
		assert(pos < _size);
		return _array[pos];
	}

	//���±��޸�
	void alter(const size_t pos, const T& value)
	{
		assert(pos < _size);
		_array[pos] = value;
	}

	T& operator[](size_t pos)
	{
		return _array[pos];
	}
	//��ӡ
	void print()const
	{
		for (size_t i = 0; i < _size;i++){
			cout << _array[i]<<" ";
		}
		cout << endl;
	}

	//��������
	~Seqlist()
	{
		if (_array){
			delete[] _array;
			_capacity = 0;
			_size = 0;
		}
	}
};