class Solution {
public:
    int search(vector<int>& nums, int target) {
		int n = nums.size();

		int k = 0;
		for(int b = n/2; b >= 1; b /= 2) {
			while(k+b < n && (
					(nums[k+b] > nums[k] && target < nums[k]) ||
					nums[k+b] <= target
				) && nums[k] != target)
				k+=b;
		}
		if(nums[k] == target) return k;

		return -1;
    }
};

