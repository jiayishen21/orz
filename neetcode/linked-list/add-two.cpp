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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int m = 0;
		int n = 0;
		ListNode* cur = l1;
		while(cur != nullptr) {
			m++;
			cur = cur->next;
		}
		cur = l2;
		while(cur != nullptr) {
			n++;
			cur = cur->next;
		}

		if(m < n) swap(l1, l2);

		addHelper(l1, l2, nullptr, 0);

		return l1;
    }

	void addHelper(ListNode* a, ListNode *b, ListNode *prevA, int overflow) {
		if(a == nullptr && b == nullptr) {
			if(overflow > 0) {
				prevA->next = new ListNode(overflow);
			}
			return;
		}

		if(b == nullptr) {
			int digitSum = a->val + overflow;
			a->val = digitSum % 10;
			addHelper(a->next, nullptr, a, digitSum/10);
			return;
		}

		int digitSum = a->val + b->val + overflow;
		a->val = digitSum % 10;
		addHelper(a->next, b->next, a, digitSum/10);
	}
};

