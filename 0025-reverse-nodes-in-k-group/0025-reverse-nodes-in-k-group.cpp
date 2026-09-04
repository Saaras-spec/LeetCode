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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n=0;
        ListNode* curr = head;
        while(curr!=nullptr){
            n++;
            curr=curr->next;
        }
        int x = floor(n/k);
        curr=head;
        ListNode* prev=nullptr;
        ListNode* first =nullptr;
        ListNode* firstans=nullptr;
        ListNode* nex=nullptr;
        ListNode* ans = nullptr;

        while(x--){
            int c=k;
            prev=nullptr;                    
            while (c!=0) {
                if(c==k) first = curr;
                nex = curr->next;                 
                curr->next = prev;        
                prev = curr;             
                curr = nex;
                c--;             
            }
            if(x==floor(n/k)-1) ans=prev;
            if(firstans!=nullptr) firstans->next=prev;
            firstans = first;   


             

        }
        if(nex!=nullptr) firstans->next=nex;
        return ans;

        
    }
};