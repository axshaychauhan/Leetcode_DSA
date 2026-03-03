class Solution {
public:
   void solveRecursion(string& s, unordered_set<string>& Dict, vector<string>& ans, string temp, int startIndex) {
       if(startIndex == s.length()){
        temp.pop_back();
        ans.push_back(temp);
        return;
       }

       string substring = "";
       for(int i = startIndex; i<= s.length(); ++i) {
         substring.push_back(s[i]);
         if(Dict.count(substring)) {
            solveRecursion(s, Dict, ans, temp + substring + " ", i+1);
         } 
       }

       return;
   }
   
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> Dict(wordDict.begin(), wordDict.end());
        vector<string> ans;
        string temp = "";
    
        solveRecursion(s, Dict, ans, temp, 0);

        return ans;
        
    }
};