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
	unordered_map<TreeNode*, int> treeSize;

public:
	void calcTreeSizeMemo(TreeNode* root) {
		if(root == nullptr) return;
		calcTreeSizeMemo(root->left);
		calcTreeSizeMemo(root->right);
		treeSize[root] = treeSize[root->left] + treeSize[root->right] + 1;
	}

	int calcTreeSize(TreeNode* root) {
		if(root == nullptr) return 0;
		return calcTreeSize(root->left) + calcTreeSize(root->right) + 1;
	}

	TreeNode* findNode(TreeNode* root, int val) {
		if(root == nullptr) return root;
		if(root->val == val) return root;
		TreeNode* leftRes = findNode(root->left, val);
		if(leftRes != nullptr) return leftRes;
		return findNode(root->right, val);
	}

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
		if(subRoot == nullptr) return true;

		int subRootSize = calcTreeSize(subRoot);
		treeSize[nullptr] = 0;
		calcTreeSizeMemo(root);

		for(const auto& pair : treeSize) {
			// pair.first != nullptr since pair.second == subRootSize > 0
			if(pair.second == subRootSize && pair.first->val == subRoot->val) {
				if(isSame(pair.first, subRoot)) return true;
			}
		}
		return false;
    }

	bool isSame(TreeNode* root, TreeNode* subRoot) {
		stack<TreeNode*> s1;
		stack<TreeNode*> s2;
		s1.push(root);
		s2.push(subRoot);

		while(!s1.empty()) {
			if(s1.top() == nullptr && s2.top() == nullptr) {
				s1.pop();
				s2.pop();
				continue;
			}
			if(s1.top() == nullptr) return false;
			if(s2.top() == nullptr) return false;
			if(s1.top()->val != s2.top()->val) return false;

			TreeNode* temp1 = s1.top();
			TreeNode* temp2 = s2.top();
			s1.pop();
			s2.pop();
			s1.push(temp1->left);
			s1.push(temp1->right);
			s2.push(temp2->left);
			s2.push(temp2->right);
		}
		return true;
	}
};

