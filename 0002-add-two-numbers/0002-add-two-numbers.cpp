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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        

        int carry = 0;
        ListNode *temp=dummy;

        while(l1!=NULL || l2 != NULL ||carry !=0){
            int sum =0;
            if(l1 != NULL){
                sum+=l1->val;
                l1 = l1->next;
            }

            if(l2!= NULL){
                sum+= l2->val;
                l2 = l2->next;
            }
            sum+= carry;

            carry = sum/10;
            int digit = sum%10;
            ListNode* new_node = new ListNode(digit);
            dummy->next = new_node;
            dummy = dummy->next;

            sum = 0;
        }

        return temp->next;

        
    }
};