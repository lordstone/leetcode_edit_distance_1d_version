class Solution {
public:    
    /**
     * @param word1 & word2: Two string.
     * @return: The minimum number of steps.
     */
    int minDistance(string word1, string word2) {
        // write your code here
        if(word1.length() == 0 && word2.length() == 0 || word1 == word2){
            return 0;
        }
        if(word1.length() == 0 || word2.length() == 0){
            return max(word1.length(),word2.length());
        }
        
        vector<int> res ( word1.length() + 1, 0);
        for(int i = 0; i <= word1.length(); i ++) res[i] = i;
        
        for(int i = 1; i <= word2.length(); i ++){
            res[0] = i; // init left val
            int leftTopCell = i - 1;
            for(int j = 1; j <= word1.length(); j ++){
                if(word1[j-1] == word2[i-1]){
                    int tmp = res[j];
                    res[j] = leftTopCell;
                    leftTopCell = tmp;
                    //swap(res[j],leftTopCell); // no prob
                }else{
                    int a = leftTopCell;
                    int b = res[j-1];
                    int c = res[j];
                    leftTopCell = res[j];
                    res[j] = min(min(a,b),c) + 1;
                }
            }
        }
        return res[word1.length()];
    }
};
