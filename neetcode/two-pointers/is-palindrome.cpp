class Solution {
public:
	bool isPalindrome(string s) {
		size_t left = 0;
		size_t right = s.size() - 1;
		size_t n = s.size();
		while(left < right && left < n) {
			if(!isalnum(s[left])) {
				left++;
				continue;
			}
			if(!isalnum(s[right])) {
				right--;
				continue;
			}
			if(tolower(s[left]) != tolower(s[right])) {
				return false;
			}
			left++;
			right--;
		}
		return true;
    }
};

