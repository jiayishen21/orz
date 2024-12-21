class Solution {
	bool noNegatives(vector<int> &freqs) {
		for(auto x : freqs) {
			if(x < 0) return false;
		}
		return true;
	}

public:
    string minWindow(string s, string t) {
		string res = "";
		int minWidth = 0;

		// shouldve used hashmap, but its fine
		vector<int> freqs(150,0);
		for(auto c : t) {
			freqs[c-'A']--;
		}

		int n = s.size();
		int left = 0;
		int right = 0;
		bool foundGood = false;
		while(right < n) {
			if(noNegatives(freqs)) {
				foundGood = true;
				freqs[s[left]-'A']--;
				left++;
			}
			else {
				int curWidth = right - left + 1;
				if(foundGood && (minWidth == 0 || minWidth > curWidth)) {
					minWidth = curWidth;
					res = s.substr(left-1, curWidth);
				}
				freqs[s[right]-'A']++;
				right++;
			}
		}

		while(noNegatives(freqs)) {
			freqs[s[left]-'A']--;
			left++;

			if(!noNegatives(freqs)) {
				int curWidth = right - left + 1;
				if(minWidth == 0 || minWidth > curWidth) {
					res = s.substr(left-1, right-left+1);
				}
			}
		}

		return res;
    }
};

