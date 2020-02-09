/*
冒泡排序
*/

#include <vector>

//升序，用大于
template<class T>
bool greater(const T& x, const T& y)
{
	return x > y;
}

//降序，用小于
template<class T>
bool less(const T& x, const T& y)
{
	return x < y;
}

template<class T>
bool bubble_sort(std::vector<T>& arr, bool(*t)(const T&,const T&))
{
	if (arr.size() == 0) {
		return false;
	}
	for (int i = 0; i < (int)arr.size(); ++i) {
		for (int j = 1; j < (int)arr.size() - i; ++j) {
			if (t(arr[j - 1], arr[j])) {
				int temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
	return true;
};

int main()
{
	std::vector<int> arr{ 3, 4, 6, 3, 2, 98, 34, 54, 6 };
	bubble_sort(arr, greater<int>);
	bubble_sort(arr, less<int>);
	return 0;
}