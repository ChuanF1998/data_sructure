

#include"sequense_list.h"

int main()
{
	Seqlist<char> s;
	cout << s.capacity() << endl;
	cout << s.size() << endl;
	s.push_back('a');
	s.push_back('b');
	s.push_back('c');
	s.push_back('4');
	s.print();
	Seqlist<char> s1 = s;
	Seqlist<char> s3 = s1;
	Seqlist<char> s2(s);
	s2.print();
	s1.print();
	//s.push_back('\0');
	//s.insert(100, 9);
	//s.insert(-2, 8);
	s.insert(3, '5');
	s.insert(4, 'k');
	s.insert(0, 'f');
	cout << s[1] << endl;
	s[1] = '0';
	cout << s[1] << endl;
	cout << s.capacity() << endl;
	cout << s.size() << endl;
	s.print();
	s.pop_back();
	s.erase(3);
	cout << s.capacity() << endl;
	cout << s.size() << endl;
	s.print();
	return 0;
}