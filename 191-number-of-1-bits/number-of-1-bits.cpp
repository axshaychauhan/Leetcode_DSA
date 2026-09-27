class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        uint32_t u = (uint32_t)n;
        while (u != 0) {
            if ((1 & u) == 1)
                ++count;
            u = u >> 1;
        }
        return count;
    }
};