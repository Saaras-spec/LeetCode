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
    
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        vector<int> v(2,-1);
        int n =1;
        vector<int> s;

        ListNode* curr = head;
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr){
            return v;
        }
        
        while(curr->next->next!=nullptr){
            n+=1;

            

            if(curr->next->val < curr->val && curr->next->val < curr->next->next->val){
                s.push_back(n);
            }
            else if(curr->next->val > curr->val && curr->next->val > curr->next->next->val){
                s.push_back(n);
            }
            
            curr = curr->next;
        }
        int x = s.size();  
        if(x<2) return v; 
        int min = INT_MAX;     
        
        for(int i=0;i<x-1;i++){
            if(s[i+1]-s[i]<min){
                min = s[i+1] - s[i];
            }            
        }
        v[0] = min;
        v[1] = s[x-1] - s[0];

        return v;

        

        
    }
};