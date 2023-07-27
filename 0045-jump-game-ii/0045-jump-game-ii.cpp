// https://www.youtube.com/watch?v=wLPdkLM_BWo&ab_channel=CodewithAlisha
// https://github.com/hetbpatel/Love-Babbar-450/blob/master/14_DP/27_min_jump_to_reach_end.cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int current = 0;
        int farthest = 0;
        
        for (int i = 0; i < nums.size() - 1; i++) {
            farthest = max(farthest, i + nums[i]);
            
            if (i == current) {
                jumps++;
                current = farthest;
            }
        }
        return jumps;
    }
};
