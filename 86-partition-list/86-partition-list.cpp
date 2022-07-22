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
            ListNode *temp = head;
            head = head->next;
            temp->next = NULL;
            if(temp->val < x) {
                first->next = temp;
                first = first->next;
            }
            else {
                second->next = temp;
                second = second->next;
            }
        }
        first->next = secondStart->next;
        return firstStart->next;
    }
};