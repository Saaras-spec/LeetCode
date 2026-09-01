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

        ListNode* curr = head;
        int size = 0;
        

        while(curr!=NULL){
            size = size+1;
            curr = curr->next;
        }
        ListNode* n1 = head;
        int i = 1;

        if(size==1 || size==n){
            ListNode* temp = n1;
            head = head->next;
            delete temp;
            return head;
            
        }
        else{
            while(i!=(size-n)){
            n1=n1->next;
            i=i+1;
            }
            ListNode* temp = n1->next;
            n1->next = n1->next->next;
            delete temp;
            return head;


        }

        
        
        
    }
};