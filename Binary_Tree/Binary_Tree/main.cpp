#include "Binary_Tree.hpp"


int main()
{
	string str1 = "ABDECFG";
	string str2 = "DBEAFCG";
	string str3 = "DEBFGCA";
	vector<char> prev(str1.begin(), str1.end());
	vector<char> inorder(str2.begin(), str2.end());
	vector<char> post(str3.begin(), str3.end());
	Tree<char> t;
	t.PrevInorder_BuiltTree(prev, inorder);
	t.preOrder();
	t.preOrder_n();
	t.inOrder();
	t.inOrder_n();
	t.postOrder();
	t.postOrder_n();
	t.levelOrder();
	int depth = t.Get_depth();
	int node_num = t.Get_Treenode_num();
	int leaf_num = t.Get_Leafnode_num();
	return 0;
}