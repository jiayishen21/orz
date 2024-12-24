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
    int goodNodes(TreeNode* root) {
		// hashmap from TreeNode* => max is trivial
		// i'll do smtn else
		return goodNodesHelper(root, root->val);
    }

	int goodNodesHelper(TreeNode* root, int maxSoFar) {
		if(root == nullptr) return 0;
		maxSoFar = max(maxSoFar, root->val);

		int good = maxSoFar <= root->val ? 1 : 0;
		good += goodNodesHelper(root->left, maxSoFar);
		return good + goodNodesHelper(root->right, maxSoFar);
	}
};

