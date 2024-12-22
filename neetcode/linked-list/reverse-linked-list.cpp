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
    ListNode* reverseList(ListNode* head) {
		if(head == nullptr || head->next == nullptr) return head;

		ListNode* cur = head;
		while(cur->next != nullptr) {
			cur = cur->next;
		}
		ListNode* tail = cur;
		cur = head;
		while(cur != tail) {
			ListNode *temp = cur->next;
			cur->next = tail->next;
			tail->next = cur;
			cur = temp;
		}
		return tail;
    }
};

