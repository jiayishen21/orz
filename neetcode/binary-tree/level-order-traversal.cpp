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
    vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if(root == nullptr) return res;

		list<TreeNode*> levelNodes;
		levelNodes.push_back(root);
		res.push_back(vector<int>{});
		int nodesOnThisLevel = 1;
		int nodesOnNextLevel = 0;
		int level = 0;

		while(nodesOnThisLevel != 0 || nodesOnNextLevel != 0) {
			if(nodesOnThisLevel == 0) {
				res.push_back(vector<int>{});
				nodesOnThisLevel = nodesOnNextLevel;
				nodesOnNextLevel = 0;
				level++;
				continue;
			}

			if(levelNodes.front() == nullptr) {
				levelNodes.pop_front();
			}
			else {
				res[level].push_back(levelNodes.front()->val);
				levelNodes.push_back(levelNodes.front()->left);
				levelNodes.push_back(levelNodes.front()->right);
				levelNodes.pop_front();
				nodesOnNextLevel += 2;
			}
			nodesOnThisLevel--;
		}

		if(res[level].empty()) {
			res.pop_back();
		}

		return res;
    }
};

