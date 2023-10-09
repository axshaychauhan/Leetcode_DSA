class Solution {
public:
    bool isAnagram(string s, string t) {
     if(s.size() != t.size()) {
         return false;
     }   
        
        int count1[256] ={0};
        int count2[256] = {0};
        
        for(int i=0; i<s.size(); i++) {
            int ch1 = s[i] - 0;
            int ch2 = t[i] - 0;
            count1[ch1]++;
            count2[ch2]++;          
            
            
        }
        
        
        for(int i=0; i<256; i++) {
            if(count1[i] != count2[i])
                return false;
        }
        
        return true;
    }
};