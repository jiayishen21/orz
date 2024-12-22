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
    void reorderList(ListNode* head) {
		int length = 0;
		ListNode* cur = head;
		while(cur != nullptr) {
			length++;
			cur = cur->next;
		}
		reorderHelper(head, length);
    }

	ListNode* reorderHelper(ListNode* cur, int length) {
		if(length == 1) {
			ListNode *toReturn = cur->next;
			cur->next = nullptr;
			return toReturn;
		}
		if(length == 2) {
			ListNode *toReturn = cur->next->next;
			cur->next->next = nullptr;
			return toReturn;
		}

		ListNode *temp = cur->next;
		ListNode *next = reorderHelper(cur->next, length-2);

		ListNode *toReturn = next->next;
		cur->next = next;
		next->next = temp;
		return toReturn;
	}
};

