#include <iostream>
#include <stack>
#include <vector>
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
		temp->left = NULL;
		temp->right = NULL;
		temp->val = val;
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
	vector<int> preorderTraversal(TreeNode* root) {
		stack<TreeNode*> st;
		vector<int> result;
		if (root == NULL) return result;
		st.push(root);
		while (!st.empty()) {
			TreeNode* node = st.top();
			st.pop();
			result.push_back(node->val);
			if (node->right) st.push(node->right);
			if (node->left) st.push(node->right);
		}
		return result;
	}

	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		stack<TreeNode*> st;
		TreeNode* cur = root;
		while (cur != NULL || !st.empty()) {
			if (cur != NULL) {
				st.push(cur);//将访问的节点放进栈
				cur = cur->left;//左
			}
			else {
				cur = st.top();//从栈里弹出的数据，就是要处理的数据
				st.pop();
				result.push_back(cur->val);//中
				cur = cur->right;//右
			}
		}
		return result;
	}

	vector<int> postorderTraversal(TreeNode* root) {
		stack<TreeNode*> st;
		vector<int> result;
		if (root == NULL) return result;
		st.push(root);
		while (!st.empty()) {
			TreeNode* node = st.top();
			st.pop();
			result.push_back(node->val);
			if (node->left) st.push(node->left);
			if (node->right) st.push(node->right);
		}
		reverse(result.begin(), result.end());
		return result;
	}
};

int main()
{
	Solution s;
	TreeNode* node = NULL;
	vector<int> v;
	int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	for (int i = 0; i < sizeof(array) / 4; i++) {
		insert(&node, array[i]);
	}
	//v = s.preorderTraversal(node);
	//v = s.inorderTraversal(node);
	v = s.postorderTraversal(node);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
}
