#include"linked_list.h"

void test(){
	Linklist<int> s(1);
	s.push_back(1);
	s.push_back(2);
	s.push_back(2);
	s.push_back(3);
	s.push_back(4);
	s.push_back(5);
	s.print();

	Linklist<int> s1(7);
	s1.push_back(8);
	s1.push_back(9);
	s1.push_back(0);
	s1.print();
	s1 = s;
	s1.print();
	Linklist<int> s2=s1;
	s2.print();
	Linklist<int> s3 = s2;
	s2.print();
	s3 = s1;
	s3.print();
	s2 = s2;
	s2.print();
	s.reverse();
	s.print();
	cout << s.first_node() << endl;
	cout << s.last_node() << endl;
	cout << s.Node_num() << endl;
	s.erase(3);
	s.print();
	//cout << s.search(2) << endl;
	s.pop_back();
	s.pop_back();
	s.print();
}

int main()
{

	test();
	return 0;
}