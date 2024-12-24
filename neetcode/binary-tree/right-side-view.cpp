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
    vector<int> rightSideView(TreeNode* root) {
		vector<int> res;
		rightSideHelper(root, res, 1);
		return res;
    }

	void rightSideHelper(TreeNode* cur, vector<int> &res, int depth) {
		if(cur == nullptr) return;

		if(depth > res.size()) res.push_back(cur->val);
		// important to call this on cur->right first
		rightSideHelper(cur->right, res, depth+1);
		rightSideHelper(cur->left, res, depth+1);
	}
};

