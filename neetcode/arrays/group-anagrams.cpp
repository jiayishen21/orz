class Solution {
private:
  void computeFreqs(string &s, unordered_map<char, int> &freqs) {
    for(char i = 'a'; i <= 'z'; i++) {
      freqs[i] = 0;
    }
    for(char c : s) {
      freqs[c]++;
    }
  }

  bool areSame(unordered_map<char, int> &a, unordered_map<char, int> &b) {
    for(char i = 'a'; i <= 'z'; i++) {
      if(a[i] != b[i]) {
        return false;
      }
    }
    return true;
  }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      vector<pair<unordered_map<char, int>, vector<string>>> res;

      for(auto &s : strs) {
        unordered_map<char, int> freqs;
        computeFreqs(s, freqs);

        bool inserted = false;
        for(auto &p : res) {
          if(areSame(p.first, freqs)) {
            p.second.push_back(s);
            inserted = true;
            break;
          }
        }
        if(!inserted) {
          pair<unordered_map<char, int>, vector<string>> p(freqs, vector<string>{s});
          res.push_back(std::move(p));
        }
      }

      vector<vector<string>> actualRes;
      for(auto &p : res) {
        actualRes.push_back(std::move(p.second));
      }
      return actualRes;
    }
};

