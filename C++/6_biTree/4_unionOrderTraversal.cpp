#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
};

void insert(TreeNode** node, int val) {
	TreeNode* temp = NULL;
	if (!(*node)) {
		temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->val = val;
		temp->left = NULL;
		temp->right = NULL;
		*node = temp;
		return;
	}

	if (val < (*node)->val) {
		insert(&(*node)->left, val);
	}

	if (val > (*node)->val) {
		insert(&(*node)->right, val);
	}
}

class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		stack<TreeNode*> st;
		if (root != NULL) st.push(root);
		while (!st.empty()) {
			TreeNode* node = st.top();
			if (node != NULL) {
				st.pop();//将该节点弹出，避免重复操作，下面再将右中左节点添加到栈中
				if (node->right) st.push(node->right);//添加右节点（空节点不入栈）

				st.push(node);//添加中节点
				st.push(NULL);//中节点访问过，但是还没有处理，加入空节点作为标记

				if (node->left) st.push(node->left);//添加左节点（空节点不入栈）
			}
			else {
				//只有遇到空节点的时候，才将下一个节点放进结果集
				st.pop();//将空节点弹出
				node = st.top();//重新取出栈中元素
				st.pop();
				result.push_back(node->val);//加入到结果集
			}
		}
		return result;
	}

	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> result;
		stack<TreeNode*> st;
		if (root != NULL) st.push(root);
		while (!st.empty()) {
			TreeNode* node = st.top();
			if (node != NULL) {
				st.pop();
				if (node->right) st.push(node->right);//右
				if (node->left) st.push(node->left);//左
				st.push(node);//中
				st.push(NULL);
			}
			else {
				st.pop();
				node = st.top();
				st.pop();
				result.push_back(node->val);
			}
		}
		return result;
	}

	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> result;
		stack<TreeNode*> st;
		if (root != NULL) st.push(root);
		while (!st.empty()) {
			TreeNode* node = st.top();
			if (node != NULL) {
				st.pop();
				st.push(node);//中
				st.push(NULL);

				if (node->right) st.push(node->right);//右
				if (node->left) st.push(node->left);//左
				
			}
			else {
				st.pop();
				node = st.top();
				st.pop();
				result.push_back(node->val);
			}
		}
		return result;
	}
};

int main() {
	Solution s;
	TreeNode* node = NULL;
	vector<int> v;
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	for (int i = 0; i < sizeof(a) / 4; i++) {
		insert(&node, a[i]);
	}
	//v = s.inorderTraversal(node);//中序遍历
	//v = s.preorderTraversal(node);//前序遍历
	v = s.postorderTraversal(node);//后序遍历

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
}
