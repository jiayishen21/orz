class Solution {
private:
	bool eatable(vector<int>& piles, int h, int k) {
		int timeUsed = 0;
		for(auto x : piles) {
			timeUsed += x / k;
			if(x % k) {
				timeUsed++;
			}
		}
		return h >= timeUsed;
	}

public:
    int minEatingSpeed(vector<int>& piles, int h) {
		int left = 1;
		int right = 1;
		for(auto x : piles) {
			right = max(right, x);
		}
		while(left < right) {
			int mid = (left + right) / 2;
			bool success = eatable(piles, h, mid);
			if(success) {
				right = mid;
			}
			else {
				if(left == mid) {
					left++;
				}
				else {
					left = mid;
				}
			}
		}
		return left;
    }
};

