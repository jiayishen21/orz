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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		int length = 0;
		ListNode* cur = head;
		while(cur != nullptr) {
			length++;
			cur = cur->next;
		}

		n = length - n;
		cur = head;

		if(n == 0) {
			ListNode *toReturn = head->next;
			head->next = nullptr;
			delete head;
			return toReturn;
		}

		while(n) {
			n--;
			if(n == 0) {
				ListNode *toDelete = cur->next;
				cur->next = toDelete->next;
				toDelete->next = nullptr;
				delete toDelete;
			}
			else {
				cur = cur->next;
			}
		}
		return head;
    }
};

