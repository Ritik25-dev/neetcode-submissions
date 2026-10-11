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

    // 'ListNode* merge2list(ListNode* l1, ListNode* l2){
    //     if(!l1 && !l2 ) return NULL;
    //     if(!l1 || !l2) return l1?l1:l2;
    //     if(l1->val < l2->val){
    //         l1->next = merge2list(l1->next,l2);
    //         return l1;
    //     }else{
    //         l2->next = merge2list(l1,l2->next);
    //         return l2;
    //     }
    // }'
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        if(lists.size() == 1) return lists[0];
        priority_queue <pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> m;

        for(int i = 0; i<lists.size(); i++ ){
            pair<int,ListNode*> p;
            if(lists[i]){
                p.first = lists[i]->val;
                p.second = lists[i];
                m.push(p);
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while(!m.empty()){
            pair<int,ListNode*> p;
            p = m.top();
            temp->next = p.second;
            temp = temp->next;
            m.pop();
            if(p.second-> next){
                pair<int,ListNode*> np;
                np.first = p.second-> next -> val;
                np.second = p.second-> next;
                m.push(np);
            }
        }

        return dummy -> next;
    }
};