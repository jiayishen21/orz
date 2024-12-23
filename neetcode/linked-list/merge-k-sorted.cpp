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
	ListNode* mergeTwo(ListNode *l1, ListNode *l2) {
		if(l1 == nullptr) return l2;
		if(l2 == nullptr) return l1;

		ListNode *head;
		if(l1->val > l2->val) {
			swap(l1, l2);
		}
		ListNode *cur1 = l1->next;
		ListNode *cur2 = l2;
		ListNode *prev = l1;

		while(cur1 != nullptr && cur2 != nullptr) {
			if(cur1->val <= cur2->val) {
				prev->next = cur1;
				cur1 = cur1->next;
				prev = prev->next;
			}
			else {
				prev->next = cur2;
				cur2 = cur2->next;
				prev = prev->next;
			}
		}

		if(cur1 == nullptr) {
			prev->next = cur2;
		}
		else {
			prev->next = cur1;
		}
		return l1;
	}

    ListNode* mergeKLists(vector<ListNode*>& lists) {
		if(lists.size() == 0) return nullptr;

		ListNode *head = lists[0];
		for(int i = 1; i < lists.size(); i++) {
			head = mergeTwo(head, lists[i]);
		}
		return head;
    }
};

