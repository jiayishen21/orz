class Solution {
public:
    int findDuplicate(vector<int>& nums) {
		int rabit = nums[0];
		int turtle = 0;

		while(true) {
			if(rabit == turtle || nums[rabit] == turtle) break;
			rabit = nums[nums[rabit]];
			turtle = nums[turtle];
		}

		int turtle2 = nums[turtle];
		while(true) {
			if(turtle == turtle2) return turtle;
			turtle = nums[turtle];
			turtle2 = nums[turtle2];
		}
		return -1;
    }
};

