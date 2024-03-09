// node.h
#pragma once
#include <vector>
#include <cmath>

using namespace std;
#define MAX_SIZE 2147483647

template <typename T>//T<->Type

/*typedef*/ struct Node {
	auto data;
	int depth;
	int index;
	Node *left;
	Node *right;

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

//	Node find(Node root,, int index_MAX, bool arrange = true) {  //index_MAX=pow(2,depth)-1;
//		if (arrange == true)
//			setTree(root);
//		Node *p = root;
//		to_number(root);
//		)
//		int objective[dep];
//		for (int i = 0; i < dep; i++)
//	objective[i] =
//}

//�� �� �����÷�ʽ Node *root = Node::fb_tree(4);
	static Node *fb_tree(int depth, int val = 0) {
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
//		}���������ʱ�Զ��ͷ��ڴ�
	}

//	void change(Node *root, Node *p) {
//		Node target = find(*p);
//
//	}

//	vector<vector<int>> reout(Node *root) {
//		//������������ά���鲢����
//		//��ȫ
//	}

	void print(Node *root) {
		//��������������
		//��ȫ
	}

} /*TreeNode*/;

/*�������*/
int *levelOrder(Node *root, int *size) {
	/*��������*/
	int front, rear;
	int index, *arr;
	Node *node;
	Node **queue;

	/*��������*/
	queue = (Node **)malloc(sizeof(Node *)*MAX_SIZE);
	front = 0, rear = 0;
	queue[rear++] = root;
	//��ʼ��һ���б����ڱ����������
	/*��������*/
	arr = (int *)malloc(sizeof(Node *)*MAX_SIZE);
	//����ָ��
	index = 0;
	while (front < rear) {
		//���г���
		node = queue[front++];
		//����ڵ�ֵ
		arr[index++] = node->data;
		if (node->left != nullptr) {
			//���ӽڵ����
			queue[rear++] = node->left;
		}
		if (node->right != nullptr) {
			//���ӽڵ����
			queue[rear++] = node->right;
		}
	}//�������鳤�ȵ�ֵ
	*size = index;;
	arr = (int *)realloc(arr, sizeof(int) * (*size));
	//�ͷŸ�������ռ䡣
	free(queue);
	return arr;
}

int main() {
	cout << sizeof(Node) << ' ' << sizeof(Node *) << endl;
//	cout << sizeof(int) << ' ' << sizeof(int *) << endl;
//	cout << sizeof(long long) << ' ' << sizeof(long long *) << endl;
//	cout << sizeof(short) << ' ' << sizeof(short *) << endl;
//	cout << sizeof(float) << ' ' << sizeof(float *) << endl;
//	cout << sizeof(double) << ' ' << sizeof(double *) << endl;
//	cout << sizeof(char) << ' ' << sizeof(char *) << endl;
//	cout << sizeof(string) << ' ' << sizeof(string *) << endl;

	return 0;
}




