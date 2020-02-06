/*
������
*/
/*
1. ������ʹ�ö���ѡ����Ч�ʾ͸��˺ܶࡣ
2. ʱ�临�Ӷȣ�O(N*logN)
3. �ռ临�Ӷȣ�O(1)
4. �ȶ��ԣ����ȶ�
*/

#include <vector>

template<class T>
void swap(T& x, T& y)
{
	T temp = x;
	x = y;
	y = temp;
}

//�Ž��򣬽�С�ѣ��ô���
template<class T>
bool greater(const T& x, const T& y)
{
	return x > y;
}
//�����򣬽���ѣ���С��
template<class T>
bool less(const T& x, const T& y)
{
	return x < y;
}

template<class T>
void heap_adjust(std::vector<int>& arr, int parent, int size, bool(*func)(const T&, const T&))
{
	int child = parent * 2 + 1;
	while (child < size) {
		if (child + 1 < size && func(arr[child], arr[child + 1])) {
			child = child + 1;
		}
		if (func(arr[parent], arr[child])) {
			swap(arr[parent], arr[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			return;
		}
	}
}

template<class T>
void heap_sort(std::vector<T>& arr, bool(*func)(const T&, const T&))
{
	//�ҳ�������һ������Ҷ�ӽڵ���±�
	int k = ((int)arr.size() - 2) >> 1;
	for (int i = k; i >= 0; --i) {
		heap_adjust(arr, i, (int)arr.size(), func);
	}
	int end = (int)arr.size() - 1;
	while (end) {
		swap(arr[0], arr[end]);
		heap_adjust(arr, 0, end, func);
		end--;
	}
}

int main()
{
	std::vector<int> arr1 = { 2, 5, 8, 4, 3, 1, 9, 0 };
	heap_sort(arr1, less<int>);
	heap_sort(arr1, greater<int>);
	return 0;
}