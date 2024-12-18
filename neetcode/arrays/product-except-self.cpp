class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      int n = nums.size();
      vector<int> leftProducts(n, 1);
      vector<int> rightProducts(n, 1);

      for(size_t i = 1; i < n; i++) {
        leftProducts[i] = leftProducts[i-1] * nums[i-1];
        rightProducts[n-i-1] = rightProducts[n-i] * nums[n-i];
      }

      vector<int> res;
      for(size_t i = 0; i < n; i++) {
        res.push_back(leftProducts[i] * rightProducts[i]);
      }
      return res;
    }
};

