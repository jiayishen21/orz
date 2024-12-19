class Solution {
public:
    int evalRPN(vector<string>& tokens) {
		stack<int> s;
		for(const auto &token : tokens) {
			if(token[0] == '+') {
				int b = s.top();
				s.pop();
				int a = s.top();
				s.pop();
				s.push(a + b);
			}
			else if(token[0] == '-' && token.size() == 1) {
				int b = s.top();
				s.pop();
				int a = s.top();
				s.pop();
				s.push(a - b);
			}
			else if(token[0] == '*') {
				int b = s.top();
				s.pop();
				int a = s.top();
				s.pop();
				s.push(a * b);
			}
			else if(token[0] == '/') {
				int b = s.top();
				s.pop();
				int a = s.top();
				s.pop();
				s.push(a / b);
			}
			else {
				int a = stoi(token);
				s.push(a);
			}
		}
		return s.top();
    }
};

