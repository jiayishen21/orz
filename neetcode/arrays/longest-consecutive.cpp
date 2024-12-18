class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      unordered_map<int, int> m;
      for(auto n : nums) {
        m[n] = 1;
      }

      int longest = 0;
      for(const auto &it : m) {
        int cur = it.first;
        if(it.second == 0) {
          continue;
        }
 
        for(int next = it.first + 1; m.find(next) != m.end() && m[next] != 0; next++) {
          m[cur] += m[next];
          m[next] = 0;
        }

        if(it.second > longest) {
          longest = it.second;
        }
      }

      return longest;
    }
};

