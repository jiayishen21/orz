class Solution {
public:
    int findDuplicate(vector<int>& nums) {
		int n = nums.size() - 1;

		int next = nums[0];
		// i is the number of elements we looked through
		for(int i = 0; i < n+1; i++) {
			if(nums[next] == -1) return next;
			int temp = nums[next];
			nums[next] = -1;
			next = temp;
		}
		return -1;
    }
};

