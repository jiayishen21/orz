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
    ListNode* reverseKGroup(ListNode* head, int k) {
		int counter = 0;
		ListNode* cur = head;

		ListNode* lastEnd = nullptr;
		ListNode* curStart;

		while(hasKGroup(cur, k)) {
			ListNode* curStart = cur;
			ListNode* prev = nullptr;
			for(int i = 0; i < k; i++) {
				ListNode *temp = cur->next; 
				cur->next = prev;
				prev = cur;
				cur = temp;
			}
			// prev is now the first node of the reversed list
			if(lastEnd != nullptr) {
				lastEnd->next = prev;
			}
			else {
				head = prev;
			}
			// curStart is now the end of the reversed list
			lastEnd = curStart;
		}
		if(lastEnd) {
			lastEnd->next = cur;
		}
		return head;
    }

	ListNode* skipK(ListNode* cur, int k) {
		for(int i = 0; i < k; i++) {
			cur = cur->next;
		}
		return cur;
	}

	bool hasKGroup(ListNode* cur, int k) {
		int counter = 0;
		while(cur != nullptr && counter < k) {
			counter++;
			cur = cur->next;
		}
		return counter == k;
	}
};

