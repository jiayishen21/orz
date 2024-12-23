class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
		int n = temp.size();
		stack<int> s;
		vector<int> res(n, 0);
		for(int i = 0; i < n; i++) {
			while(!s.empty() && temp[i] > temp[s.top()]) {
				res[s.top()] = i - s.top();
				s.pop();
			}
			s.push(i);
		}
		return res;
    }
};

