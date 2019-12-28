#pragma once
#include<iostream>
#include<stack>
#include <queue>
using namespace std;

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

	//前序递归创建
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

	//返回叶子节点个数
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


	//前序和中序构造二叉树
	tree_node<T>* pre_and_inorder(const vector<T>& prev, int prev_begin, int prev_end, const vector<T>& inorder, int inorder_begin, int inorder_end)
	{
		if (prev.size() == 0 || inorder.size() == 0) {
			return nullptr;
		}
		if (prev_begin > prev_end || inorder_begin > inorder_end) {
			return nullptr;
		}
		tree_node<T>* root = new tree_node<T>;
		root->data = prev[prev_begin];
		for (int i = inorder_begin; i <= inorder_end; ++i) {
			if (inorder[i] == prev[prev_begin]) {
				root->left = pre_and_inorder(prev, prev_begin + 1, prev_begin + i - inorder_begin, inorder, inorder_begin, i);
				root->right = pre_and_inorder(prev, prev_begin + 1 + i - inorder_begin, prev_end, inorder, i + 1, inorder_end);
			}
		}
		return root;
	}

	//后序和中序构造二叉树
	tree_node<T>* post_and_inorder(const vector<T>& post, int post_begin, int post_end, const vector<T>& inorder, int inorder_begin, int inorder_end)
	{
		if (post.size() == 0 || inorder.size() == 0) {
			return nullptr;
		}
		if (post_end < post_begin) {
			return nullptr;
		}
		tree_node<T>* root = new tree_node<T>;
		root->data = post[post_end];
		for (int i = inorder_begin; i <= inorder_end; ++i) {
			if (inorder[i] == post[post_end]) {
				root->left = post_and_inorder(post, post_begin, post_begin + i - 1 - inorder_begin, inorder, inorder_begin, i - 1);
				root->right = post_and_inorder(post, post_begin + i - inorder_begin, post_end - 1, inorder, i + 1, inorder_end);
			}
		}
		return  root;
	}

	//销毁
	void destroy(tree_node<T>*& r)
	{
		if (r){
			destroy(r->left);
			destroy(r->right);
			delete r;
		}
	}

public:
	//构造函数
	Tree()
		:_root(nullptr)
	{}

	//前序和中序构造二叉树
	void PrevInorder_BuiltTree(const vector<T>& prev, const vector<T>& inorder)
	{
		int prev_size = prev.size();
		int inorder_size = inorder.size();
		if (_root == nullptr)
			_root = pre_and_inorder(prev, 0, prev_size - 1, inorder, 0, inorder_size - 1);
	}

	//后序和中序构造二叉树
	void PostInorder_BuiltTree(const vector<T>& post, const vector<T>& inorder)
	{
		int post_size = post.size();
		int inorder_size = inorder.size();
		if (_root == nullptr)
			_root = post_and_inorder(post, 0, post_size - 1, inorder, 0, inorder_size - 1);
	}


	//前序递归创建
	void pre_create()
	{
		if (_root == nullptr) //根节点为空时才调用create()进行创建
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
	void postOrder()
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
			while (!(t.empty() && r == nullptr)){
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
				r = r->left;
				s1.pop();
			}
			while (!s2.empty()){
				cout << s2.top()->data << " ";
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
	size_t Get_Treenode_num()const
	{
		size_t count = node(_root);
		return count;
	}

	//返回二叉树的叶子节点个数
	size_t Get_Leafnode_num()const
	{
		return Get_leaf(_root);
	}


	//析构函数
	~Tree()
	{
		if (_root){
			destroy(_root);
			_root = nullptr;
		}
	}

};
