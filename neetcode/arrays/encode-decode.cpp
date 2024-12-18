class Solution {
public:

    string encode(vector<string>& strs) {
      string res = "";
      for(auto &s: strs) {
        res += to_string(s.size()) + "|" + s;
      }
      return res;
    }

    vector<string> decode(string s) {
      vector<string> res;
      size_t i = 0;
      while(i < s.size()) {
        int len = 0;
        while(s[i] != '|') {
          len *= 10;
          len += s[i] - '0';
          i++;
        }
        i++;

        res.push_back(s.substr(i, len));
        i += len;
      }
      return res;
    }
};

