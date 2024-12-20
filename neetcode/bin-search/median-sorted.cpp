class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		if(nums2.size() < nums1.size()) {
			swap(nums1, nums2);
		}
		int m = nums1.size();
		int n = nums2.size();
		int half = (m+n)/2;

		if(m == 0) {
			if(n%2) {
				return nums2[n/2];
			}
			else {
				return (double)(nums2[n/2] + nums2[n/2-1]) / 2;
			}
		}

		// k is the number of elements to include from nums2
		int k = 0;
		for(int b = n/2; b >= 1; b /= 2) {
			while(k+b<n) {
				int complement = half - (k+b);
				if(complement < 0 || complement > m) break;

				// don't worry if k+b == 0, since b >= 1
				if(k+b == n) {
					if(nums2[k+b-1] <= nums1[complement]) {
						k += b;
						b = 0;
						break;
					}
					else {
						break;
					}
				}

				// if it is a good partition, we're done
				if(nums2[k+b-1] <= nums1[complement] &&
					nums1[complement-1] <= nums2[k+b]) {
					k += b;
					b = 0;
					break;
				}
				// if we took too much from nums2
				else if(nums2[k+b-1] > nums1[complement]) {
					break;
				}
				else {
					k += b;
				}
			}
		}

		int complement = half - k;
		bool isOdd = ((m+n) % 2) == 1;
		if(isOdd) {
			if(k == n) return nums1[complement];
			if(complement == m) return nums2[k];
			return min(nums1[complement], nums2[k]);
		}
		else {
			if(k == n) {
				return (double)(nums1[complement] + nums2[k-1]) / 2;
			}
			if(complement == m) {
				return (double)(nums1[complement-1] + nums2[k]) / 2;
			}
			double left = max(nums1[complement-1], nums2[k-1]);
			double right = min(nums1[complement], nums2[k]);
			return (left+right) /2;
		}

    }
};

