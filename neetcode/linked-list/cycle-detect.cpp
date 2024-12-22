/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
		if(head == nullptr || head->next == nullptr) return false;
		ListNode* bunny = head->next;
		ListNode* turtle = head;
		while(true) {
			if(bunny->next == nullptr || bunny->next->next == nullptr) return false;
			if(bunny == turtle || bunny->next == turtle) return true;
			bunny = bunny->next->next;
			turtle = turtle->next;
		}
		return false;
    }
};

