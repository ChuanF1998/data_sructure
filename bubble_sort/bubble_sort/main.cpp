/*
Ã°ÅÝÅÅÐò
*/

#include <vector>

//ÉýÐò
template<class T>
bool max(const T& x, const T& y)
{
	return x > y;
}

//½µÐò
template<class T>
bool min(const T& x, const T& y)
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
	bubble_sort(arr, max<int>);
	bubble_sort(arr, min<int>);
	return 0;
}