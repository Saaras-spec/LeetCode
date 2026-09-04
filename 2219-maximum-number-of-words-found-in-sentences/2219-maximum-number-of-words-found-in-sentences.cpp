class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int m= INT_MIN;
        for(int i=0;i<sentences.size();i++){
            int count=0;
            for(int j=1;j<sentences[i].size()-1;j++){
                if(sentences[i][j]==' ') count++;
            }
            if(count>m) m=count;
        }
        return m+1;
    }
};