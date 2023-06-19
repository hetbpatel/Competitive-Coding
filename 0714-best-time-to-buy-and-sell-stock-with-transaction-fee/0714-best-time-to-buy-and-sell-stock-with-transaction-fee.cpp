// https://www.youtube.com/watch?v=DzH4kVcyuOI&t=275s&ab_channel=CodewithAlisha
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,0));
        dp[0][0] = -(prices[0]+fee);
        for(int i=1;i<prices.size();i++)
        {
            dp[i][0] = max(dp[i-1][0],dp[i-1][1] - (prices[i]+fee));
            dp[i][1] = max(dp[i-1][0] + prices[i],dp[i-1][1]);
        }
        return dp[prices.size()-1][1];
    }
};