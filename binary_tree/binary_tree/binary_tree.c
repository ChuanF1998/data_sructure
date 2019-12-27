#include<iostream>
using namespace std;
#include<stack>
#include <queue>

//定义节点
template<class T>
class tree_node
{
public:
	T data;
	tree_node* left;
	tree_node* right;
};

template<class T>
class Tree
{
private:
	tree_node<T>* _root;

	//将递归创建设置为私有
	void create(tree_node<T>*& r)
	{
		T k;
		cin >> k;
		if (k == '#'){
			r = nullptr;
		}
		else{
			tree_node<T>* temp = new tree_node<T>;
			temp->data = k;
			r = temp;
			create(*(&r->left));
			create(*(&r->right));
		}
	}

	//前序递归遍历的函数
	void _preOrder(tree_node<T> *r)const
	{
		if (r){
			cout << r->data << " ";
			_preOrder(r->left);
			_preOrder(r->right);
		}
	}

	//中序递归遍历
	void _inOrder(tree_node<T> *r)const
	{
		if (r){
			_inOrder(r->left);
			cout << r->data << " ";
			_inOrder(r->right);
		}
	}

	//后序递归遍历
	void _postOrder(tree_node<T> *r)const
	{
		if (r){
			_postOrder(r->left);
			_postOrder(r->right);
			cout << r->data << " ";
		}
	}

	//返回二叉树的节点个数
	size_t node(tree_node<T>* r)const
	{
		size_t count = 0;
		if (r != nullptr) {
			count += 1 + node(r->left) + node(r->right);
		}
		return count;
	}

	//返回二叉树的深度
	size_t Getdepth(tree_node<T>* r)const
	{
		if (r == nullptr) {
			return 0;
		}
		size_t left_deep = 1 + Getdepth(r->left);
		size_t right_deep = 1 + Getdepth(r->right);
		if (left_deep > right_deep) {
			return left_deep;
		}
		else {
			return right_deep;
		}
	}

public:
	//构造函数
	Tree()
		:_root(nullptr)
	{}

	//前序递归创建
	void pre_create()
	{
		if (_root==nullptr) //根节点为空时才调用create()进行创建
		create(_root);
	}


	//前序递归遍历
	void preOrder()
	{
		_preOrder(_root);
		cout << endl;
	}

	//中序递归遍历
	void inOrder()
	{
		_inOrder(_root);
		cout << endl;
	}

	//后序递归遍历
	void postOrde()
	{
		_postOrder(_root);
		cout << endl;
	}

	//前序非递归,需要用到栈
	void preOrder_n()const
	{
		if (_root != nullptr){
			stack<tree_node<T>*> t;
			tree_node<T>* r = _root;
			while (!(t.empty()&&r==nullptr)){
				while (r != nullptr){
					cout << r->data << " ";
					t.push(r);
					r = r->left;
				}
				r = t.top();
				r = r->right;
				t.pop();
			}
		}
		cout << endl;
	}

	//中序非递归
	void inOrder_n()
	{
		if (_root != nullptr){
			stack<tree_node<T>*> s;
			tree_node<T>* r = _root;
			while (!(s.empty() && r == nullptr)){
				while (r != nullptr){
					s.push(r);
					r = r->left;
				}
				r = s.top();
				cout << r->data << " ";
				s.pop();
				r = r->right;
			}
			}
		cout << endl;
	}

	//后序非递归
	void postOrder_n()
	{
		if (_root != nullptr){
			stack<tree_node<T>*> s1;
			stack<tree_node<T>*> s2;
			tree_node<T>* r = _root;
			while (!(r == nullptr&&s1.empty())) {
				while (r != nullptr){
					s1.push(r);
					s2.push(r);
					r = r->right;
				}
				r = s1.top();
				r = r -> left;
				s1.pop();
			}
			while (!s2.empty()){
				cout << s2.top()->data<<" ";
				s2.pop();
			}
		}
		cout << endl;
	}

	//层序遍历
	void levelOrder()const
	{
		if (_root != nullptr) {
			queue<tree_node<T>*> q;
			q.push(_root);
			while (!q.empty()) {
				tree_node<T>* temp = q.front();
				cout << temp->data << " ";
				if (temp->left != nullptr) {
					q.push(temp->left);
				}
				if (temp->right != nullptr) {
					q.push(temp->right);
				}
				q.pop();
			}
		}
		cout << endl;
	}

	//返回二叉树的深度
	size_t Get_depth()const
	{
		size_t depth = Getdepth(_root);
		return depth;
	}



	//返回二叉树的节点个数
	size_t Get_Treenode()const
	{
		size_t count = node(_root);
		return count;
	}

	//返回二叉树的叶子节点个数
	size_t Get_Leafnode()const
	{
		return Get_leaf(_root);
	}

	size_t Get_leaf(tree_node<T>* r)const
	{
		
		size_t count = 0;
		if (r == nullptr) {
			return 0;
		}
		if (r->left == nullptr && r->right == nullptr) {
			count += 1;
		}
		count += 0 + Get_leaf(r->left) + Get_leaf(r->right);
		return count;
	}

	//销毁
	void destroy(tree_node<T>* r)
	{
		if (r){
			destroy(r->left);
			destroy(r->right);
			delete r;
			_root = nullptr;
		}
	}

	//析构函数
	~Tree()
	{
		//tree_node<T>* r = _root;
		if (_root){
			destroy(_root);
		}
	}

};