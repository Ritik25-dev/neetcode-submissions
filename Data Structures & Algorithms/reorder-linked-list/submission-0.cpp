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

    ListNode* findMid(ListNode* head){
        if(!head->next ) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            fast = fast -> next->next;
            slow = slow -> next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* next = head;
        ListNode* prev = NULL;

        while(curr){
            next = curr-> next;
            curr->next = prev;
            prev =  curr;
            curr = next;
        }

        return prev;
    }


    void reorderList(ListNode* head) {
        if(!head) return;
        ListNode* mid = findMid(head);
        ListNode* revHead = reverse(mid->next);

        mid->next = NULL;

        ListNode* l1 = head;
        ListNode* l2 = revHead;


        while( l2){
            ListNode* next1 = l1->next;
            ListNode* next2 = l2->next;
            l1->next = l2;
            l2->next = next1;
            l1= next1;
            l2 = next2;
        }

    }
};