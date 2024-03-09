#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 2147483647

typedef struct Node {
	int data;
	int depth;
	int index;
	Node *left;
	Node *right;

	Node(): data(0), index(0), depth(0), left(nullptr), right(nullptr) {}
	Node(int val): data(val), index(0), depth(0), left(nullptr), right(nullptr) {}
	Node(int i, int d): data(0), depth(d), index(i), left(nullptr), right(nullptr) {}
	Node(int val, int d, int i): data(val), depth(d), index(i), left(nullptr), right(nullptr) {}

//Node *newN(int val) {
//	Node *n;
//
////	n = (Node *)malloc(sizeof(Node));
//	n->val = val;
//	n->depth = 0;
//	n->left = NULL;
//	n->right = NULL;
//	return n;
//}

	void to_number(Node *root, int index = 1) {
		root->index =  index;
		if (root->left != NULL)
			to_number(root->left, 2 * index);
		if (root->right != NULL)
			to_number(root->right, 2 * index + 1);
	}

//	Node find(Node root, int ) {
//		int dep =
//		    Node * p = root;
//		to_number(root);
//		)
//		int objective[dep];
//		for (int i = 0; i < dep; i++)
//	objective[i] =
//}

	static Node *fb_tree(int depth) {//���÷�ʽ Node *root = Node::fb_tree(4);
		Node *root = new Node(1, 1);
		int n = pow(2, depth);
		vector<Node> temp(n);
		temp[1] = *root;
		for (int i = 2; i <= pow(2, depth) - 1; i++) {
			temp[i] = Node(i, int(log2(i)) + 1);
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
		if (p->left != NULL) {
			p->left->depth += 1;
			p->left->index *= 2;
		}
		if (p->right != NULL) {
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

} Node;

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
		if (node->left != NULL) {
			//���ӽڵ����
			queue[rear++] = node->left;
		}
		if (node->right != NULL) {
			//���ӽڵ����
			queue[rear++] = node->right;
		}
	}//�Ҿ��ø������鳤�ȵ�ֵ
	*size = index;;
	arr = (int *)realloc(arr, sizeof(int) * (*size));
	//�ͷŸ�������ռ䡣
	free(queue);
	return arr;
}

int main() {


	return 0;
}






























//6.92 jpd:/ o@D.HI 11/13 ���ҵ����������ʵ������Ч��-�߶����� # �ҵ����� # minecraft # �ҵ�����ģ��# �ҵ������������� # mc  https://v.douyin.com/iLghPWL1/ ���ƴ����ӣ���Dou��������ֱ�ӹۿ���Ƶ��
//0.53 03/30 sre:/ a@N.JV �����Ǿ͵��ڱ���,��ʷ�������ǡ�  https://v.douyin.com/iLghqR8v/ ���ƴ����ӣ���Dou��������ֱ�ӹۿ���Ƶ��
//6.97 HVL:/ E@u.sr 08/02 ��һ�����ˣ��ز�ȴ�����ı�Ů�˻��� # С˵ # С˵�Ƽ� # ����Ԫ # �Ļ��Ƽ� # �������  https://v.douyin.com/iL3u62ed/ ���ƴ����ӣ���Dou��������ֱ�ӹۿ���Ƶ��
