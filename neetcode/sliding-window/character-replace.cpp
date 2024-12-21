class Solution {
private:
	int maxFreq(vector<int> &freqs) {
		int m = 0;
		for(int i = 0; i < freqs.size(); i++) {
			m = max(m, freqs[i]);
		}
		return m;
	}

	int sumFreq(vector<int> &freqs) {
		int acc = 0;
		for(int i = 0; i < freqs.size(); i++) {
			acc += freqs[i];
		}
		return acc;
	}

public:
    int characterReplacement(string s, int k) {
		int n = s.size();
		vector<int> freqs(26, 0);
		int left = 0;
		int right = 0;
		int maxLen = 0;
		while(right < n) {
			freqs[s[right] - 'A']++;
			if(sumFreq(freqs) - maxFreq(freqs) > k) {
				while(sumFreq(freqs) - maxFreq(freqs) > k) {
					freqs[s[left] - 'A']--;
					left++;
				}
			}
			right++;
			maxLen = max(maxLen, right-left);
		}
		return maxLen;
    }
};

