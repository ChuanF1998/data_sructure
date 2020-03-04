//��������

#include <vector>

//С�ڣ�����
template<class T>
bool less(const T& a, const T& b)
{
	return a < b;
}

//���ڣ�����
template<class T>
bool greater(const T& a, const T& b)
{
	return a > b;
}

template<class T>
void Quick_sort(std::vector<T>& arr, int low, int high, bool (*func)(const T&, const T&))
{
	if (low > high) {
		return;
	}
	int flag = FindFlag(arr, low, high, func); //�ұ�׼λ
	Quick_sort(arr, low, flag - 1, func);
	Quick_sort(arr, flag + 1, high, func);
	return;
}


template<class T>
int FindFlag(std::vector<T>& arr, int low, int high, bool(*func)(const T&, const T&))
{
	int flag = low;
	while (low < high) {
		//�����Ҫ��������ô��С�ں���
		//�����Ҫ�Ž�����ô�ô��ں���
		while (flag < high && func(arr[flag], arr[high])) {
			high--;
		}
		std::swap(arr[flag], arr[high]);
		flag = high;
		while (flag > low && func(arr[low], arr[flag])) {
			low++;
		}
		std::swap(arr[flag], arr[low]);
		flag = low;
	}
	return flag;
}




int main()
{
	std::vector<int> arr{ 4, 6, 2, 9, 0, -3, 40 };
	Quick_sort(arr, 0, (int)arr.size() - 1, less<int>);
	Quick_sort(arr, 0, (int)arr.size() - 1, greater<int>);
	return 0;
}