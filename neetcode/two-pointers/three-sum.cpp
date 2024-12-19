class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		int n = nums.size();
		sort(nums.begin(), nums.end());

		vector<vector<int>> res;

		// last entry into res
		int x = nums[0]-1;
		int y = x;
		int z = x;

		for(int i = 0; i < n; i++) {
			if(nums[i] > 0) {
				return res;
			}
			if(nums[i] == x) {
				continue;
			}
			cout << nums[i] << endl;

			int target = -nums[i];
			int leftIndex = i + 1;
			int rightIndex = n - 1;
			// two sum pt 2 solution
			while(leftIndex < rightIndex) {
				int left = nums[leftIndex];
				int right = nums[rightIndex];
				int sum = left + right;
				if(x == nums[i] && y == left && z == right) {
					leftIndex++;
					// not decrementing rightIndex here is also fine
					rightIndex--;
					continue;
				}
				if(target == sum) {
					x = nums[i];
					y = left;
					z = right;
					res.push_back(vector<int>{x,y,z});
					leftIndex++;
					rightIndex--;
					continue;
				}
				else if(sum < target) {
					leftIndex++;
				}
				else {
					rightIndex--;
				}
			}
		}
		return res;
    }
};

