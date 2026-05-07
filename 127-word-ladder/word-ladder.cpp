class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());

        queue<string> q;
        q.push(beginWord);
        int level = 1;


        while(!q.empty()){
            int sz = q .size();

            for(int i = 0; i<sz; ++i){
                string currentWord = q.front();
                q.pop();

                if(currentWord == endWord){
                    return level;
                }

                for(int i = 0; i< currentWord.length(); ++i) {
                    char originalChar = currentWord[i];

                    for(char c = 'a'; c<= 'z' ; ++c) {
                        if(c == originalChar) continue;

                        currentWord[i] = c;

                        if(dict.find(currentWord) != dict.end()) {
                            q.push(currentWord);
                            dict.erase(currentWord);
                        }
                    }
                    currentWord[i] = originalChar;
                } 
            }

            ++level;
        }

        return 0;
    }
};