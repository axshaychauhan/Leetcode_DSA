class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // create set of deadends to act as visited
        // create queue and push starting state
        // do BFS and find target while traversing increase turn for every
        // combination

        unordered_set<string> visited(deadends.begin(), deadends.end());
        string start = "0000";
        if(visited.count(start)) return -1;
        queue<string> q;
        q.push(start);
        visited.insert(start);

        int turns = 0;
        while (!q.empty()) {

            int sz = q.size();

            for (int i = 0; i < sz; ++i) {
                string comb = q.front();
                q.pop();

                if (comb == target)
                    return turns;
                for (int j = 0; j < 4; ++j) {

                    string clockWise = comb;
                    clockWise[j] = clockWise[j] == '9' ? '0' : ++clockWise[j];

                    if (!visited.count(clockWise)) {
                        visited.insert(clockWise);
                        q.push(clockWise);
                    }

                    string anticlockWise = comb;
                    anticlockWise[j] =
                        anticlockWise[j] == '0' ? '9' : --anticlockWise[j];
                    if (!visited.count(anticlockWise)) {
                        visited.insert(anticlockWise);
                        q.push(anticlockWise);
                    }
                }
            }
            ++turns;
        }
        return -1;
    }
};