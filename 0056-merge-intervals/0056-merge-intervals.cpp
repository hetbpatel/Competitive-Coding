// https://leetcode.com/problems/merge-intervals/description/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;

        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0]; 
        });
        
        int i;
        for (i = 0; i < intervals.size() - 1; i++) {
            // no overlap
            if (intervals[i][1] < intervals[i+1][0]) {
                result.push_back(intervals[i]);
                continue;
            }
            // overlap
            intervals[i+1][0] = intervals[i][0];
            intervals[i+1][1] = max(intervals[i][1], intervals[i+1][1]);
        }
        result.push_back(intervals[i]);

        return result;
    }
};

/*--------------------------------------------------------------------------------------------------------------*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;

        sort(intervals.begin(),intervals.end());

        int start = intervals[0][0];
        int end = intervals[0][1];

        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]<=end)
            {
                end = max(end,intervals[i][1]);
            }

            else
            {
                ans.push_back({start,end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        if(!ans.size() || ans[ans.size()-1][1] != intervals[intervals.size()-1][1]) ans.push_back({start,end});

        return ans;

    }
};
