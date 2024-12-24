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
    bool isValidBST(TreeNode* root) {
		int maxVal = root->val-1;
		int minVal = root->val+1;
		return validBSTHelper(root, maxVal, minVal);
    }

	bool validBSTHelper(TreeNode* root, int &maxVal, int &minVal) {
		if(root == nullptr) return true;

		// set default values in case left or right is null
		int leftMaxVal = root->val-1;
		int leftMinVal = root->val+1;
		int rightMaxVal = root->val-1;
		int rightMinVal = root->val+1;

		if(!validBSTHelper(root->left, leftMaxVal, leftMinVal)) return false;
		if(!validBSTHelper(root->right, rightMaxVal, rightMinVal)) return false;

		if(leftMaxVal >= root->val || rightMinVal <= root->val) {
			return false;
		}

		maxVal = max(rightMaxVal, root->val);
		minVal = min(leftMinVal, root->val);
		return true;
	}
};

