bool cmp(pair<int, int> &a, pair<int, int> &b) {
  return a.second > b.second;
}

class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freqs;
    for(auto n : nums) {
      if(freqs.find(n) != freqs.end()) {
        freqs[n]++;
      }
      else {
        freqs[n] = 1;
      }
    }

    vector<pair<int, int>> sortedFreqs;
    for(const auto &p : freqs) {
      sortedFreqs.push_back(p);
    }
    sort(sortedFreqs.begin(), sortedFreqs.end(), cmp);
    vector<int> res;
    for(int i = 0; i < k; i++) {
      res.push_back(sortedFreqs[i].first);
    }
    return res;
  }
};

