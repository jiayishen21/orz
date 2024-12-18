class MinStack {
	stack<int> vals;
	stack<int> minVal;

public:
    MinStack() {
        
    }
    
    void push(int val) {
		vals.push(val);
		if(minVal.empty()) {
			minVal.push(val);
		}
		else {
			minVal.push(min(val, minVal.top()));
		}
    }
    
    void pop() {
        vals.pop();
		minVal.pop();
    }
    
    int top() {
		return vals.top();
    }
    
    int getMin() {
        return minVal.top();
    }
};

