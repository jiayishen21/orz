class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
		int maxArea = 0;
		stack<pair<int, int>> s;
		int n = heights.size();

		for(int i = 0; i < n; i++) {
			maxArea = max(maxArea, heights[i]);
			if(s.empty() || heights[i] > s.top().second) {
				s.push(pair<int,int>(i, heights[i]));
			}
			else {
				int lastPop = i;
				while(!s.empty() && heights[i] < s.top().second) {
					int area = (i-s.top().first+1) * heights[i];
					maxArea = max(maxArea, area);

					area = (i-s.top().first) * s.top().second;
					maxArea = max(maxArea, area);

					lastPop = s.top().first;
					s.pop();
				}
				s.push(pair<int,int>(lastPop, heights[i]));
			}
		}

		if(s.empty()) {
			return maxArea;
		}
		pair<int,int> t = s.top();
		s.pop();

		while(!s.empty()) {
			int area = (t.first-s.top().first+1) * s.top().second;
			maxArea = max(maxArea, area);
			s.pop();
		}
		return maxArea;
    }
};

