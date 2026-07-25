class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int pMax = INT_MIN;
        for(auto p: piles) pMax = max(pMax, p);

        int left = 1;
        int right = pMax;
        int minSpeed = -1;
        while(left <= right){
            int mid =  left + (right - left)/ 2;
            if(canEat(piles, h, mid)){
                minSpeed = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return minSpeed;
    }

    bool canEat(vector<int>& piles, int maxTime, int speed){
        long long totalTime = 0;
        for(auto p: piles) 
            totalTime += (p + speed -1)/speed;
        return totalTime <= maxTime;
    }
};