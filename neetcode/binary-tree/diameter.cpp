/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
	unordered_map<TreeNode*, int> m;

public:
    int diameterOfBinaryTree(TreeNode* root) {
		// build up map of tree to maxDepth
		m[nullptr] = 0;
		maxDepth(root);

		return diameterHelper(root);
    }

	int diameterHelper(TreeNode* root) {
		if(root == nullptr) return 0;

		int a = m[root->left] + m[root->right];
		int b = max(diameterHelper(root->left), diameterHelper(root->right));

		return max(a, b);
	}

	int maxDepth(TreeNode* root, int depth = 0) {
		if(root == nullptr) return depth;

		int curDepth = 1 + max(maxDepth(root->left), maxDepth(root->right));
		m[root] = curDepth;
		return curDepth;
	}
};

