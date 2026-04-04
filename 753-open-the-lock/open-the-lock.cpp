class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        unordered_set<string> visited(
            deadends.begin(),
            deadends.end()); // use visited as both deadend and tracker
        queue<string> q;

        string start = "0000";
        if (visited.count(start))
            return -1; // if start is deadend return

        visited.insert(start);
        q.push(start);
        int turns = 0;

        while (!q.empty()) {

            int size = q.size();

            for (int i = 0; i < size; ++i) {

                string lockNode = q.front();
                q.pop();
                if (lockNode == target)
                    return turns;
                for (int i = 0; i < 4; ++i) {

                    string clockWise = lockNode;
                    clockWise[i] = clockWise[i] == '9' ? '0' : clockWise[i] + 1;

                    if (!visited.count(clockWise)) {
                        visited.insert(clockWise);
                        q.push(clockWise);
                    }

                    string antiClockWise = lockNode;
                    antiClockWise[i] =
                        antiClockWise[i] == '0' ? '9' : antiClockWise[i] - 1;

                    if (!visited.count(antiClockWise)) {
                        visited.insert(antiClockWise);
                        q.push(antiClockWise);
                    }
                }
            }
            ++turns;
        }
        return -1;
    }
};