/*
堆排序
*/
/*
1. 堆排序使用堆来选数，效率就高了很多。
2. 时间复杂度：O(N*logN)
3. 空间复杂度：O(1)
4. 稳定性：不稳定
*/

#include <vector>

template<class T>
void swap(T& x, T& y)
{
	T temp = x;
	x = y;
	y = temp;
}

//排降序，建小堆，用大于
template<class T>
bool greater(const T& x, const T& y)
{
	return x > y;
}
//排升序，建大堆，用小于
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
	//找出倒数第一个不是叶子节点的下标
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