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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		vector<TreeNode*> pPath;
		vector<TreeNode*> qPath;
		
		TreeNode* cur = root;
		while(cur->val != p->val) {
			pPath.push_back(cur);
			if(cur->val < p->val) {
				cur = cur->right;
			}
			else {
				cur = cur->left;
			}
		}
		pPath.push_back(cur);

		cur = root;
		while(cur->val != q->val) {
			qPath.push_back(cur);
			if(cur->val < q->val) {
				cur = cur->right;
			}
			else {
				cur = cur->left;
			}
		}
		qPath.push_back(cur);

		int n = min(pPath.size(), qPath.size());
		TreeNode* res = root;
		for(int i = 1; i < n; i++) {
			if(pPath[i] == qPath[i]) res = pPath[i];
		}
		return res;
    }
};

