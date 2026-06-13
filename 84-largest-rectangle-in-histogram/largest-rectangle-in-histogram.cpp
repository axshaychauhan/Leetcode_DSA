class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = int(heights.size());
        stack<int> st;
        int maxArea = 0;
        for (int i = 0; i <= n; ++i) {
            int curr = i == n ? 0 : heights[i];
            while (!st.empty() && curr < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int rBoundry = i;
                int lBoundry = st.empty() ? -1 : st.top();
                int width = rBoundry - lBoundry - 1;
                int area = height * width;
                maxArea = max(maxArea, area);
            }
            st.push(i);
        }
        return maxArea;
    }
};