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
    bool isSameTree(TreeNode* p, TreeNode* q) {
		stack<TreeNode*> s1;
		stack<TreeNode*> s2;
		s1.push(p);
		s2.push(q);
		while(!s1.empty() && !s2.empty()) {
			if(s1.top() == nullptr && s2.top() == nullptr) {
				s1.pop();
				s2.pop();
			}
			// return false if only one of them is nullptr
			else if(s1.top() == nullptr || s2.top() == nullptr) {
				return false;
			}
			else if(s1.top()->val == s2.top()->val) {
				TreeNode* temp1 = s1.top();
				TreeNode* temp2 = s2.top();
				s1.pop();
				s1.push(temp1->left);
				s1.push(temp1->right);
				s2.pop();
				s2.push(temp2->left);
				s2.push(temp2->right);
			}
			// return false if they have diff vals
			else {
				return false;
			}
		}

		return true;
    }
};

