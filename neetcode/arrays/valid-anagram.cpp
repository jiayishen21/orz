class Solution {
public:
    bool isAnagram(string s, string t) {
      unordered_map<char, int> freqs;

      for(char i = 'a'; i <= 'z'; i++) {
        freqs[i] = 0;
      }

      // record frequency of chars in s and t
      if(s.size() != t.size()) {
        return false;
      }
      for(size_t i = 0; i < s.size(); i++) {
        freqs[s[i]] ++;
        freqs[t[i]] --;
      }

      for(char i = 'a'; i <= 'z'; i++) {
        if(freqs[i] != 0) {
          return false;
        }
      }
      return true;
    }
};

