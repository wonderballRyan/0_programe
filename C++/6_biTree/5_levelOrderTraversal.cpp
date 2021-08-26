#include <iostream>
#include <queue>
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
	//二叉树的层次遍历
	vector<vector<int>> levelOrder(TreeNode* root) {
		queue<TreeNode*> que;
		if (root != NULL) que.push(root);
		vector<vector<int>> result;
		while (!que.empty()) {
			int size = que.size();
			vector<int> vec;
			for (int i = 0; i < size; i++) {
				TreeNode* node = que.front();
				que.pop();
				vec.push_back(node->val);
				if (node->left) que.push(node->left);
				if (node->right) que.push(node->right);
			}
			result.push_back(vec);
		}
		return result;
	}

	//二叉树的层次遍历（由下而上）
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		queue<TreeNode*> que;
		if (root != NULL) que.push(root);
		vector<vector<int>> result;
		while (!que.empty()) {
			int size = que.size();
			vector<int> vec;
			for (int i = 0; i < size; i++) {
				TreeNode* node = que.front();
				que.pop();
				vec.push_back(node->val);
				if (node->left)que.push(node->left);
				if (node->right)que.push(node->right);
			}
			result.push_back(vec);
		}
		reverse(result.begin(), result.end());
		return result;
	}

	//二叉树的右视图
	vector<int> rightSideView(TreeNode* root) {
		queue<TreeNode*> que;
		if (root != NULL) que.push(root);
		vector<int> result;
		while (!que.empty()) {
			int size = que.size();
			for (int i = 0; i < size; i++) {
				TreeNode* node = que.front();
				que.pop();
				if (i == (size - 1)) result.push_back(node->val);
				if (node->left)que.push(node->left);
				if (node->right)que.push(node->right);
			}
		}
		return result;
	}

	//二叉树的层平均值
	vector<double> averageOfLevels(TreeNode* root) {
		queue<TreeNode*> que;
		if (root != NULL)que.push(root);
		vector<double> result;
		while (!que.empty()) {
			int size = que.size();
			double sum = 0;//统计每一层的和
			for (int i = 0; i < size; i++) {
				TreeNode* node = que.front();
				que.pop();
				sum += node->val;
				if (node->left) que.push(node->left);
				if (node->right) que.push(node->right);
			}
			result.push_back(sum / size);
		}
		return result;
	}

	//在每个树行中找最大值
	vector<int> largestValues(TreeNode* root) {
		queue<TreeNode*> que;
		if (root != NULL) que.push(root);
		vector<int> result;
		while (!que.empty()) {
			int size = que.size();
			int maxValue = INT_MIN;//取每一层的最大值
			for (int i = 0; i < size; i++) {
				TreeNode* node = que.front();
				que.pop();
				maxValue = node->val > maxValue ? node->val : maxValue;
				if (node->left) que.push(node->left);
				if (node->right) que.push(node->right);
			}
			result.push_back(maxValue);//把最大值放进数组
		}
		return result;
	}

	//二叉树的最大深度
	int maxDepth(TreeNode* root) {
		if (root == NULL)return 0;
		int depth = 0;
		queue<TreeNode*> que;
		que.push(root);
		while (!que.empty()) {
			int size = que.size();
			depth++;
			for (int i = 0; i < size; i++) {
				TreeNode* node = que.front();
				que.pop();
				if (node->left) que.push(node->left);
				if (node->right) que.push(node->right);
			}
		}
		return depth;
	}

	//二叉树的最小深度
	int minDepth(TreeNode* root) {
		if (root == NULL) return 0;
		int depth = 0;
		queue<TreeNode*> que;
		que.push(root);
		while (!que.empty()) {
			int size = que.size();
			depth++;
			for (int i = 0; i < size; i++) {
				TreeNode* node = que.front();
				que.pop();
				if (node->left) que.push(node->left);
				if (node->right) que.push(node->right);
				if (!node->left && !node->right) {
					return depth;
				}
			}
		}
		return depth;
	}

};

int main() {
	TreeNode* node = NULL;
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	for (int i = 0; i < sizeof(a) / 4; i++) {
		insert(&node, a[i]);
	}

	vector<vector<int>> v1;
	Solution s;
	v1 = s.levelOrder(node);
	cout << sizeof(v1) << endl;
	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; i < v1[i].size(); j++) {
			cout << v1[i][j] << ",";
		}
		cout << endl;
	}

}
