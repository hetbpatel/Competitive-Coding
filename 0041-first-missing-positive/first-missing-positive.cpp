// https://leetcode.com/problems/first-missing-positive/description/

class Solution
{
public:
    int firstMissingPositive(int A[], int n)
    {
        int n = nums.size();

        for(int i=0;i<n;i++)
        {
            if(nums[i]>0 and nums[i]<=n and nums[nums[i]-1]!=nums[i])
            {
                swap(nums[i],nums[nums[i]-1]);
                i--;
            }
        }

        for(int i=0;i<n;i++)
        {
            if(nums[i]!=i+1)    return i+1;
        }

        return n+1;
    }
};
