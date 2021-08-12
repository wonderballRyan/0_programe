#include <iostream>
#include <vector>

using namespace std;


typedef int TElemType;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	//TreeNode(int x) :val(x), left(NULL), right(NULL){}
};

void insert(TreeNode** node, int val)
{
	TreeNode* temp = NULL;

	if (!(*node))
	{
		temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->left = NULL;
		temp->right = NULL;
		temp->val = val;
		*node = temp;
		return;
	}
	if (val < (*node)->val)
	{
		insert(&(*node)->left, val);
	}
	else if (val > (*node)->val)
	{
		insert(&(*node)->right, val);
	}
}

class Solution {
public:
	void preorderTraversal(TreeNode* cur, vector<int>& vec) {
		if (cur == NULL) return;
		vec.push_back(cur->val);//中
		preorderTraversal(cur->left, vec);//左
		preorderTraversal(cur->right, vec);//右
	}

	void inorderTraversal(TreeNode* cur, vector<int>& vec) {
		if (cur == NULL) return;
		inorderTraversal(cur->left, vec);//左
		vec.push_back(cur->val);//中
		inorderTraversal(cur->right, vec);//右
	}

	void postorderTraversal(TreeNode* cur, vector<int>& vec) {
		if (cur == NULL) return;
		postorderTraversal(cur->left, vec);//左
		postorderTraversal(cur->right, vec);//右
		vec.push_back(cur->val);//中
	}

	vector<int> traversal(TreeNode* root) {
		vector<int> result;
		//preorderTraversal(root, result);//前序遍历
		//inorderTraversal(root, result);//中序遍历
		postorderTraversal(root, result);//后序遍历
		return result;
	}
};

int main() {
	Solution s;
	vector<int> v;
	TreeNode* node = NULL;

	int array[10] = { 1,2,3,4,5,6,7,8,9,10 };

	for (int i = 0; i < sizeof(array) / 4; i++)
	{
		insert(&node, array[i]);
	}
	v = s.traversal(node);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
}
