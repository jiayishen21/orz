class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		unordered_set<char> usedChars;

		int left = 0;
		int right = 0;
		char lastUsed = '\0';
		bool catchUp = false;
		int maxLen = 0;
		while(right <= s.size()) {
			if(catchUp) {
				if(s[left] == lastUsed) {
					catchUp = false;
				}
				else {
					usedChars.erase(usedChars.find(s[left]));
				}
				left++;
			}
			else if(right == s.size()) {
				break;
			}
			else if(usedChars.find(s[right]) != usedChars.end()){
				maxLen = max(maxLen, right - left); // no need to +1 or -1
				catchUp = true;
				lastUsed = s[right];
				right++;
			}
			else {
				usedChars.insert(s[right]);
				right++;
			}
		}
		maxLen = max(maxLen, right - left);
		return maxLen;
    }
};

