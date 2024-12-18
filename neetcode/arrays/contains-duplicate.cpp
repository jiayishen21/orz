#include <unordered_set>

using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
      unordered_set<int> s;
      for(auto n: nums) {
        if(s.find(n) != s.end()) {
          return true;
        }
        s.insert(n);
      }
      return false;
    }
};

