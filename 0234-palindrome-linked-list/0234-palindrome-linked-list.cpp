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
    ListNode* middle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;

        }

        return slow;
    }

    ListNode* reverse(ListNode* mid){
        ListNode* prev= NULL;
        ListNode* cur = mid;
        ListNode* next= NULL;
        while(cur){
            next = cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }

        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* mid=middle(head);
        ListNode* rev = reverse(mid);

        while(rev!=NULL){
            if(head->val!=rev->val){
                return false;

            }

            head = head->next;
            rev = rev->next;

        }

        return true;



    }

        

};