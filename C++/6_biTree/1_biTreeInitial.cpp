#include <iostream>
#include <algorithm>
using namespace std;

/*class TreeNode
{
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val)
	{
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}
};
*/

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
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

void deltree(TreeNode* node)
{
	if (node)
	{
		deltree(node->left);
		deltree(node->right);
		free(node);
	}
}

void print_preorder(TreeNode* node)
{
	if (!(node)) return;

	cout << node->val << " ";
	print_preorder(node->left);
	print_preorder(node->right);

	return;
}

int main()
{
	TreeNode* node = NULL;

	int array[10] = { 1,2,3,4,5,6,7,8,9,10 };

	for (int i = 0; i < sizeof(array) / 4; i++)
	{
		insert(&node, array[i]);
	}

	print_preorder(node);

	deltree(node);
	return 0;
}
