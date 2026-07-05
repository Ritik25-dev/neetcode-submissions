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
         if(head == NULL) return head;
        ListNode* fastPtr = head;
        ListNode* slowPtr = head;

        for (int i = 0; i<n; i++){
            fastPtr = fastPtr->next;
        }

        if(fastPtr ==NULL){
            ListNode* nextHead = head->next;
            delete head;
            return nextHead;
        }

        while(fastPtr->next != NULL){
            fastPtr= fastPtr->next;
            slowPtr = slowPtr -> next;
        }

        ListNode* nthNode = slowPtr -> next;
        slowPtr->next =  slowPtr->next->next;
        delete nthNode;

        return head;
    }
};
