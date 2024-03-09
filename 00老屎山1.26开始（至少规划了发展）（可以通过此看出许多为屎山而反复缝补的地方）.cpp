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

	static Node *fb_tree(int depth) {//调用方式 Node *root = Node::fb_tree(4);
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

} Node;

/*层序遍历*/
int *levelOrder(Node *root, int *size) {
	/*辅助队列*/
	int front, rear;
	int index, *arr;
	Node *node;
	Node **queue;

	/*辅助队列*/
	queue = (Node **)malloc(sizeof(Node *)*MAX_SIZE);
	front = 0, rear = 0;
	queue[rear++] = root;
	//初始化一个列表用于保存遍历序列
	/*辅助数组*/
	arr = (int *)malloc(sizeof(Node *)*MAX_SIZE);
	//数组指针
	index = 0;
	while (front < rear) {
		//对列出队
		node = queue[front++];
		//保存节点值
		arr[index++] = node->data;
		if (node->left != NULL) {
			//左子节点入队
			queue[rear++] = node->left;
		}
		if (node->right != NULL) {
			//右子节点入队
			queue[rear++] = node->right;
		}
	}//我觉得更新数组长度的值
	*size = index;;
	arr = (int *)realloc(arr, sizeof(int) * (*size));
	//释放辅助数组空间。
	free(queue);
	return arr;
}

int main() {


	return 0;
}






























//6.92 jpd:/ o@D.HI 11/13 给我的世界更加真实的物理效果-瓦尔基里 # 我的世界 # minecraft # 我的世界模组# 我的世界物理引擎 # mc  https://v.douyin.com/iLghPWL1/ 复制此链接，打开Dou音搜索，直接观看视频！
//0.53 03/30 sre:/ a@N.JV “忘记就等于背叛,历史必须铭记”  https://v.douyin.com/iLghqR8v/ 复制此链接，打开Dou音搜索，直接观看视频！
//6.97 HVL:/ E@u.sr 08/02 我一个男人，胸部却发育的比女人还好 # 小说 # 小说推荐 # 二次元 # 文荒推荐 # 拯救书荒  https://v.douyin.com/iL3u62ed/ 复制此链接，打开Dou音搜索，直接观看视频！
