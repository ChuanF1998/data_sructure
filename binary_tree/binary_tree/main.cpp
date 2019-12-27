#include"binary_tree.c"


void fun(int* (&f)){
	f = new int(5);
	//*f = 5;
}

void dun(int** l)
{
	*l = new int(7);
}
int main()
{
	Tree<char> t;
	t.pre_create();
	t.preOrder();
	t.inOrder();
	t.postOrde();
	t.preOrder_n();
	t.inOrder_n();
	t.postOrder_n();
	t.levelOrder();
	int node = t.Get_Treenode();
	int depth = t.Get_depth();
	int leaf = t.Get_Leafnode();
	

	return 0;
}