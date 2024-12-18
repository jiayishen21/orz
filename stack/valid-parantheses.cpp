class Solution {
private:
  char invertBracket(char c) {
    if(c == ')') {
      return '(';
    }
    else if(c == ']') {
      return '[';
    }
    else {
      return '{';
    }
  }

public:
  bool isValid(string s) {
    stack<char> unclosed;
    for(auto c : s) {
      if(c == '(' || c == '[' || c == '{') {
        unclosed.push(c);
      }
      else {
        if(unclosed.empty()) {
          return false;
        }
        if(unclosed.top() != invertBracket(c)) {
          return false;
        }
        unclosed.pop();
      }
    }
    return unclosed.empty();
  }
};

