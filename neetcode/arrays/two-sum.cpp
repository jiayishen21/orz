class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int, int> indices;
      for(size_t i = 0; i < nums.size(); i++) {
        int n = nums[i];
        if(indices.find(target - n) != indices.end()) {
          vector<int> ans{indices[target - n], i};
          return ans;
        }
        indices[n] = i;
      }
    }
};

