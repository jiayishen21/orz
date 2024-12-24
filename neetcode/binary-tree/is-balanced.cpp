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
public:
    bool isBalanced(TreeNode* root) {
		bool balanced = true;
		getHeightAndCheckBalance(root, balanced);
		return balanced;
    }

	int getHeightAndCheckBalance(TreeNode* root, bool &balanced) {
		if(root == nullptr) return 0;
		if(!balanced) return 0;

		int left = getHeightAndCheckBalance(root->left, balanced);
		int right = getHeightAndCheckBalance(root->right, balanced);
		if(!balanced) return 0;

		balanced = abs(left-right) <= 1;
		return 1 + max(left, right);
	}

};
