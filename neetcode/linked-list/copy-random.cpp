/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
		if(head == nullptr) {
			return nullptr;
		}

		Node* cur = head;
		Node* copyHead = new Node(head->val);
		Node* copyCur = copyHead;
		unordered_map<Node*, Node*> oldToNew;
		oldToNew[head] = copyHead;

		while(cur->next) {
			cur = cur->next;
			copyCur->next = new Node(cur->val);
			copyCur = copyCur->next;
			oldToNew[cur] = copyCur;
		}

		cur = head;
		copyCur = copyHead;
		while(cur != nullptr) {
			if(cur->random != nullptr) {
				copyCur->random = oldToNew[cur->random];
			}
			cur = cur->next;
			copyCur = copyCur->next;
		}
		return copyHead;
    }
};

