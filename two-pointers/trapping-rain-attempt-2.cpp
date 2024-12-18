class Solution {
public:
	int prefixSuffixSolution(vector<int>& height) {
		// prefix suffix solution is
		int n = height.size();
		vector<int> leftMax(n, 0);
		vector<int> rightMax(n, 0);
		leftMax[0] = height[0];
		rightMax[n-1] = height[n-1];
		for(int i = 1; i < n; i++) {
			leftMax[i] = max(leftMax[i-1], height[i]);
			rightMax[n-1-i] = max(rightMax[n-i], height[n-1-i]);
		}

		int total = 0;
		for(int i = 0; i < n; i++) {
			total += min(leftMax[i], rightMax[i]) - height[i];
		}
		return total;
	}

	// we derive this from the prefix suffix solution
    int trap(vector<int>& height) {
		int n = height.size();
		int left = 0;
		int right = n - 1;
		int leftMax = height[left];
		int rightMax = height[right];
		int total = 0;
		while(left < right) {
			// the tricky part is that we work are way in
			// from both sides as opposed to iterating i
			// from left to right
		}
    }
};

