class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m = matrix.size();
		int n = matrix[0].size();

		int row = 0;
		for(int b = m/2; b >= 1; b /= 2) {
			while(row+b < m && matrix[row+b][0] <= target) row += b;
		}
		vector<int>& nums = matrix[row];
		int col = 0;
		for(int b = n/2; b >= 1; b /= 2) {
			while(col+b < n && nums[col+b] <= target) col += b;
		}
		return nums[col] == target;
    }
};

