class Solution {
public:
    int trap(vector<int>& height) {
		int n = height.size();

		stack<int> s;
		stack<int> insertions;
		int total = 0;
		int prevHeight = 0;

		for(int i = 0; i < n; i++) {
			while(!s.empty() && height[s.top()] <= height[i]) {
				int area = (height[s.top()] - prevHeight) * (i - s.top() - 1);
				total += area;
				prevHeight = height[s.top()];
				s.pop();
			}
			if(!s.empty()) {
				int area = (height[i] - prevHeight) * (i - s.top() - 1);
				total += area;
			}
			prevHeight = height[i];
			s.push(i);
		}
		return total;
    }
};

