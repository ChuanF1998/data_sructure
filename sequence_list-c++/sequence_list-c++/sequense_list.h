#pragma once

#include<iostream>
#include<cassert>
using namespace std;

template<class T>
class Seqlist
{
private:
	T* _array;
	size_t _capacity;//容量
	size_t _size;//有效个数
public:
	typedef T* iterator;
public:
	//构造函数
	Seqlist(size_t capacity = 5)
		:_array(new T[capacity])
		, _capacity(capacity)
		, _size(0)
	{}

	//拷贝构造函数
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

	//赋值运算符重载
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

	//扩容
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


	//返回元素个数
	size_t size()const
	{
		return _size;
	}

	//返回容量
	size_t capacity()const
	{
		return _capacity;
	}

	//尾插
	void push_back(const T& value)
	{
		//是否需要扩容
		if (_size == _capacity){
			reverse();
		}
		_array[_size] = value;
		_size++;
	}

	//尾删
	void pop_back()
	{
		assert(_size > 0);
		_size--;
	}

	//随机插入
	void insert(size_t pos,const T& value)
	{
		assert(pos <= _capacity);
		assert(pos <= _size);//判断插入位置是否越界
		//是否需要扩容
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

	//随机删除
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

	//按下标查找
	T& search(size_t pos)
	{
		assert(pos < _size);
		return _array[pos];
	}

	//按下标修改
	void alter(const size_t pos, const T& value)
	{
		assert(pos < _size);
		_array[pos] = value;
	}

	T& operator[](size_t pos)
	{
		return _array[pos];
	}
	//打印
	void print()const
	{
		for (size_t i = 0; i < _size;i++){
			cout << _array[i]<<" ";
		}
		cout << endl;
	}

	//析构函数
	~Seqlist()
	{
		if (_array){
			delete[] _array;
			_capacity = 0;
			_size = 0;
		}
	}
};