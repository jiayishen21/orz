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
    int kthSmallest(TreeNode* root, int k) {
		int res;
		helper(root, k, res);
		return res;
    }

	void helper(TreeNode* root, int &k, int &res) {
		if(root == nullptr) return;

		helper(root->left, k, res);
		if(k == 0) return;
		if(k == 1) {
			res = root->val;
			// indicate we're done
			k = 0;
			return;
		}
		k--;
		helper(root->right, k, res);
	}
};

