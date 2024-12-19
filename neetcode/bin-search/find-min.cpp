class Solution {
public:
	// standard
    int findMinStandard(vector<int> &nums) {
		int n = nums.size();
		int low = 0;
		int high = n-1;
		while(nums[low] > nums[high]) {
			int mid = (low+high)/2;
			if(nums[mid] >= nums[low]) low = mid+1;
			else high = mid;
		}
		return nums[low];
    }

	// iteration version
	int findMin(vector<int> &nums) {
		int n = nums.size();
		int k = 0;
		for(int b = n/2; b >= 1; b /= 2) {
			while(k < n && nums[k+b] > nums[k]) k += b;
		}
		k = (k+1) % n;
		return nums[k];
    }
};

