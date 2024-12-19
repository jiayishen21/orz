class Solution {
public:
    vector<string> generateParenthesis(int n) {
		// hahahahhahahaa
		// catalan recurrence
		vector<vector<string>> dp(n + 1);
		dp[0].push_back("");
		for(int i = 1; i < n + 1; i++) {
			for(int j = 0; j < i; j++) {
				int k = i-1-j;
				for(const auto &p : dp[j]) {
					for(const auto &p2 : dp[k]) {
						dp[i].push_back("(" + p + ")" + p2);
					}
				}
			}
		}
		return dp[n];
    }
};

