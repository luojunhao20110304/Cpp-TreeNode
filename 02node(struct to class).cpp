// node.h
#pragma once
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
//#define MAX_SIZE 2147483647
const int MAX_SIZE = 2147483647;


/*评价参考：
此代码定义了一个Node类，但是在类的成员函数中使用了malloc来分配内存。
在C++中，我们通常使用new和delete来进行内存分配和释放，而不是malloc和free。
另外，你还使用了C风格的数组和指针，这在C++中不是最佳实践。
*/
template <class Type = int>

class Node {
	public:
		Type data;
		int depth;
		int index;
		Node<Type> *left;
		Node<Type> *right;

		Node(): data(0), index(0), depth(0), left(nullptr), right(nullptr) {}
		Node(auto val): data(val), index(0), depth(0), left(nullptr), right(nullptr) {}
		Node(int i, int d): data(0), depth(d), index(i), left(nullptr), right(nullptr) {}
		Node(auto val, int d, int i): data(val), depth(d), index(i), left(nullptr), right(nullptr) {}

		Node *newNode(int val) {
			Node *n;
			n = (Node *)malloc(sizeof(Node));
			n->data = val;
			n->depth = 0;
			n->left = nullptr;
			n->right = nullptr;
			return n;
		}

		void setTree(Node *root, int index = 1) {
			root->index = index;
			root->depth = (int)log2(index);
			if (root->left != nullptr)
				setTree(root->left, 2 * index);
			if (root->right != nullptr)
				setTree(root->right, 2 * index + 1);
		}

		Node find(Node root, int index_MAX, bool arrange = true) {  //index_MAX=pow(2,depth)-1;
			if (arrange == true)
				setTree(root);
			int dep = log2(index_MAX) + 1;
			int objective[dep];
			int index = index_MAX;
			for (int i = 0; i < dep; i++)
				objective[i] = index % 2 == 0 ? 0 : 1;
			Node<> *p = root;
			for (int i = 0; i < dep; i++) {
				if (objective[i] == 0)
					p = p->left;
				if (objective[i] == 1)
					p = p->right;
			}
		}

//↓ ↓ ↓调用方式 Node *root = Node::fb_tree(4);
		static Node *fb_tree(int depth, auto val = NULL) {
			Node *root = new Node(val, 1, 1);
			int n = pow(2, depth);
			vector<Node> temp(n);
			temp[1] = *root;
			for (int i = 2; i <= pow(2, depth) - 1; i++) {
				temp[i] = Node(val, int(log2(i)) + 1, i);
				if (i % 2 == 0)
					temp[i / 2].left = &temp[i];
				else
					temp[i / 2].right = &temp[i];
			}
//  不再需要手动释放内存(vector会在其作用域结束时自动释放内存)
//  delete[] temp;
			return root;


//		Node *root = new Node(1, 1);
//		int n = pow(2, depth);
//		Node *temp = new Node[n];
//		temp[1] = *root;
//		for (int i = 2; i <= pow(2, depth) - 1; i++) {
//			temp[i] = Node(i, int(log2(i)) + 1);
//			if (i % 2 == 0)
//				temp[i / 2].left = &temp[i];
//			else
//				temp[i / 2].right = &temp[i];
//		}
//		delete[] temp;
//		return root;
		}

		void insert(Node *father, Node *p) {
			char dir = (p->index % 2 == 0 ? 'l' : 'r');
			if (dir == 'l') {
				p->left = father->left;
				p->right = father->right;
				father->left = p;
			}
			if (dir == 'r') {
				p->left = father->left;
				p->right = father->right;
				father->right = p;
			}
			if (p->left != nullptr) {
				p->left->depth += 1;
				p->left->index *= 2;
			}
			if (p->right != nullptr) {
				p->right->depth += 1;
				p->right->index *= 2 + 1;
			}
		}

		void del(Node *father, Node *p) {
			father->left = p->left;
			father->right = p->right;
//		try {
//			delete p;
//		} catch (...) {
//		}作用域结束时自动释放内存
		}

//	void change(Node *root, Node *p) {
//		Node target = find(*p);
//
//	}

//	vector<vector<int>> reout(Node *root) {
//		//层序便利存入二维数组并返回
//		//补全
//	}

		void print(Node *root) {
			//层序便利输出矩阵
			//补全
		}

} ;

/*层序遍历*/
template<typename U>

int *levelOrder(Node<U> *root, int *size) {
	int front, rear;
	int index, *arr;
	Node<U> *node;
	Node<U> **queue;

	queue = new Node<U> *[MAX_SIZE];
	front = 0, rear = 0;
	queue[rear++] = root;

	arr = new int[MAX_SIZE];
	index = 0;
	while (front < rear) {
		node = queue[front++];
		arr[index++] = node->data;
		if (node->left != nullptr) {
			queue[rear++] = node->left;
		}
		if (node->right != nullptr) {
			queue[rear++] = node->right;
		}
	}
	*size = index;
	arr = (int *)realloc(arr, sizeof(int) * (*size)); // 这里使用realloc不是推荐的做法
	delete[] queue; // 使用delete释放new分配的内存
	return arr;
}


int main() {
	cout << sizeof(Node<>) << ' ' << sizeof(Node<> *) << endl;//Node<>等同于Node<int>,因为前面默认值设置的为int
//	cout << sizeof(int) << ' ' << sizeof(int *) << endl;
//	cout << sizeof(long long) << ' ' << sizeof(long long *) << endl;
//	cout << sizeof(short) << ' ' << sizeof(short *) << endl;
//	cout << sizeof(float) << ' ' << sizeof(float *) << endl;
//	cout << sizeof(double) << ' ' << sizeof(double *) << endl;
//	cout << sizeof(char) << ' ' << sizeof(char *) << endl;
//	cout << sizeof(string) << ' ' << sizeof(string *) << endl;
	/*注意：auto并无实际大小 */

	return 0;
}


/*
以下是一些常见的模板类型参数命名约定：

T：代表Type，通用的类型参数名称
U、V、W：用于多个类型参数的情况
ValueType、KeyType、ElementType：描述容器元素的类型参数名称
IteratorType、ConstIteratorType：描述迭代器的类型参数名称
ContainerType、ArrayType：描述容器或数组类型的类型参数名称
*/

