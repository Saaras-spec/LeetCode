class Solution {
public:
    bool matching(char a,char b){
        return (
            (a=='(' && b==')') ||
            (a=='{' && b=='}') ||
            (a=='[' && b==']')
        );

        
    }
    bool isValid(string s) {
        stack<char> st;
        for(char c:s){
            if(c=='(' || c=='{' || c=='['){
                st.push(c);
            }
            else{
                if(st.empty()) return false;

                if(matching(st.top(),c)==false) return false;
                else st.pop();
                
            }
        }
        return (st.empty()==true);

        

        

                
    }
};