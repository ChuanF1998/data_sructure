/*
ֱ�Ӳ�������
*/

/*
ֱ�Ӳ�������������ܽ᣺
1. Ԫ�ؼ���Խ�ӽ�����ֱ�Ӳ��������㷨��ʱ��Ч��Խ��
2. ʱ�临�Ӷȣ�O(N^2)
3. �ռ临�Ӷȣ�O(1)������һ���ȶ��������㷨
4. �ȶ��ԣ��ȶ�
*/

#include <vector>


//������С�ڣ�
template<class T>
bool min(const T& x, const T& y)
{
	return x < y;
}

//�����ô��ڣ�
template<class T>
bool max(const T& x, const T& y)
{
	return x > y;
}

template<class T>
bool insertion_sorting(std::vector<T>& arr, bool(*t)(const T&, const T&))
{
	if (arr.size() == 0)
	{
		return false;
	}
	for (int i = 1; i < (int)arr.size(); ++i) {
		for (int j = i; j > 0; --j) {
			if (t(arr[j], arr[j - 1])) {
				T temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
		}
	}
	return true;
}


int main()
{
	std::vector<int> arr{ 3, 5, 8, 2, 54, 23, 57, 87, 1 };
	std::vector<char> str{ 't', 'g', 'a', 'l', 'b' };
	std::vector<double> arr1{ 2.1, 4.5, 1.2, 5.7, 78.7, 0.2 };
	insertion_sorting(arr, max<int>);
	insertion_sorting(arr, min<int>);
	insertion_sorting(str, max<char>);
	insertion_sorting(str, min<char>);
	insertion_sorting(arr1, max<double>);
	insertion_sorting(arr1, min<double>);
	return 0;
}