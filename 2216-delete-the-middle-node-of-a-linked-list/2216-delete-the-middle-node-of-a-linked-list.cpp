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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return nullptr;
        ListNode* f = head;
        ListNode* s = head;

        while(f!=nullptr && f->next!=nullptr){
            s=s->next;
            f=f->next->next;

        }
        ListNode* curr = head;
        ListNode* temp = head;
        while(curr!=nullptr){
            if(curr->next==s){
                temp = s;
                curr->next =  curr->next->next;
                delete s;
                break;                

            }
            curr=curr->next;
        }
        return head;

        
    }
};