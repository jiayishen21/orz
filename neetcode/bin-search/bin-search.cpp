class Solution {
public:
    int normal_search(vector<int>& nums, int target) {
		int n = nums.size();
		int left = 0;
		int right = n-1;
		while(left <= right) {
			int mid = (left+right)/2;
			if(nums[mid] == target) {
				return mid;
			}
			if(nums[mid] > target) right = mid -1;
			else left = mid + 1;
		}
		return -1;
    }

    int search(vector<int>& nums, int target) {
		int n = nums.size();
		int k = 0;
		// b is the jump size
		for(int b = n/2; b >= 1; b /= 2) {
			// this handles the jumping
			while(k+b < n && nums[k+b] <= target) {
				k+= b;
			}
		}
		if(nums[k] == target) {
			return k;
		}
		return -1;
	}
};

