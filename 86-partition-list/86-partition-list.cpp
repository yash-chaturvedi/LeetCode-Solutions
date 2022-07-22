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
    ListNode* partition(ListNode* head, int x) {
        ListNode *first = new ListNode(), *second = new ListNode();
        ListNode *firstStart = first, *secondStart = second;
        while(head) {
            if(head->val < x) {
                first->next = head;
                first = first->next;
            }
            else {
                second->next = head;
                second = second->next;
            }
            head = head->next;
        }
        second->next = NULL;
        first->next = secondStart->next;
        return firstStart->next;
    }
};