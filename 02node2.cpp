// node.h
#pragma once
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
//#define MAX_SIZE 2147483647
const int MAX_SIZE = 2147483647;


/*���۲ο���
�˴��붨����һ��Node�࣬��������ĳ�Ա������ʹ����malloc�������ڴ档
��C++�У�����ͨ��ʹ��new��delete�������ڴ������ͷţ�������malloc��free��
���⣬�㻹ʹ����C���������ָ�룬����C++�в������ʵ����
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

//		static Node find(Node root, bool arrange = true) {  //index_MAX=pow(2,depth)-1;
//			int end_index =
//			if (arrange == true)
//				setTree(root);
//			int dep = log2(end_index) + 1;
//			int objective[dep];
//			int ind = new int;
//			ind = end_index;
//			for (int i = 0; i < dep; i++)
//				objective[i] = ind % 2 == 0 ? 0 : 1;
//			delete ind;
//			Node<> *p = root;
//			for (int i = 0; i < dep; i++) {
//				if (objective[i] == 0)
//					p = p->left;
//				if (objective[i] == 1)
//					p = p->right;
//			}
//			return p;
//		}

		static Node find(Node root, int end_index, bool arrange = true) { //index_MAX=pow(2,depth)-1;
			if (arrange == true)
				setTree(root);
			int dep = log2(end_index) + 1;
			int objective[dep];
			int ind = new int;
			ind = end_index;
			for (int i = 0; i < dep; i++)
				objective[i] = ind % 2 == 0 ? 0 : 1;
			delete ind;
			Node<> *p = root;
			for (int i = 0; i < dep; i++) {
				if (objective[i] == 0)
					p = p->left;
				if (objective[i] == 1)
					p = p->right;
			}
			return p;
		}

//		static Node find(Node root,int first_index,int end_index, bool arrange = true) {  //index_MAX=pow(2,depth)-1;
//			if (arrange == true)
//				setTree(root);
//			int dep = log2(index) + 1;
//			int objective[dep];
//			int ind = new int;
//			ind = index;
//			for (int i = 0; i < dep; i++)
//				objective[i] = ind % 2 == 0 ? 0 : 1;
//			delete ind;
//			Node<> *p = root;
//			for (int i = 0; i < dep; i++) {
//				if (objective[i] == 0)
//					p = p->left;
//				if (objective[i] == 1)
//					p = p->right;
//			}
//			return p;
//		}

		static Node find_father(Node *root, Node *p, bool arrange = true) {
			if (arrange == true)
				setTree(root);
			Node father = find(root, p->index / 2, false);
			return father;
		}

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
//  ������Ҫ�ֶ��ͷ��ڴ�(vector���������������ʱ�Զ��ͷ��ڴ�)
//  delete[] temp;
			return root;
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
//		}���������ʱ�Զ��ͷ��ڴ�
		}

		void change(Node *root, int index, Node *p, bool arrange = true) {
			if (arrange == true)
				setTree(root);
			Node father = find(*root, index / 2, false);
			Node target = new Node;
			if (index % 2 == 0) {
				target = father->left;
				father->left = p;
			} else if (index % 2 == 1) {
				target = father->right;
				father->right = p;
			}
			*p->left = target->left;
			*p->right = target->right;
			delete father, *target, target;
		}

		/**********���ѹ���**********/

		static Node BFS(Node *root, Node *p) {

		}

		static Node BFS(Node *root, int end_index, Node *p) {

		}

		static Node BFS(Node *root, int first_index, int end_index, Node *p) {

		}

		static Node DFS(Node *root, Node *p) {

		}

		static Node DFS(Node *root, int end_index, Node *p) {

		}

		static Node DFS(Node *root, int first_index, int end_index, Node *p) {

		}

} ;

/*�������*/
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
	arr = (int *)realloc(arr, sizeof(int) * (*size));
	delete[] queue;
	return arr;
}


int main() {
	cout << sizeof(Node<>) << ' ' << sizeof(Node<> *) << endl;//Node<>��ͬ��Node<int>,��Ϊǰ��Ĭ��ֵ���õ�Ϊint
//	cout << sizeof(int) << ' ' << sizeof(int *) << endl;
//	cout << sizeof(long long) << ' ' << sizeof(long long *) << endl;
//	cout << sizeof(short) << ' ' << sizeof(short *) << endl;
//	cout << sizeof(float) << ' ' << sizeof(float *) << endl;
//	cout << sizeof(double) << ' ' << sizeof(double *) << endl;
//	cout << sizeof(char) << ' ' << sizeof(char *) << endl;
//	cout << sizeof(string) << ' ' << sizeof(string *) << endl;

	return 0;
}


