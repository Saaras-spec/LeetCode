/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr) return nullptr;
        Node* h1 =  new Node(head->val);
        Node* c1 = h1;
        Node* curr = head->next;
        while(curr!=nullptr){
            Node* n = new Node(curr->val);
            c1->next = n;
            c1=c1->next;
            curr=curr->next;
        }
    
        Node* check = head;
        c1=h1;

        while(check!=nullptr){
            if(check->random!=nullptr){
                curr=h1;
                Node* original = head;
                int x =0;
                while(original!=nullptr){
                    if(check->random == original){
                        
                        break;
                    }
                    original=original->next;
                    x++;
                }
                while(x>0){
                    curr=curr->next;
                    x--;
                }
                c1->random = curr;

            }
            else{
                c1->random=nullptr;
            }
            c1=c1->next;
            check=check->next;
        }
        return h1;

        
    }
};