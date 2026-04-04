class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> ledger(n + 1);
        if (n == 1)
           return 1;
        for(auto pair: trust) {
            
            ledger[pair[0]]--;
            ledger[pair[1]]++;
        }

        for(int i = 0; i<ledger.size(); ++i){
            if(ledger[i] == n - 1)
               return i;
        }
             
        return -1;
    }
};