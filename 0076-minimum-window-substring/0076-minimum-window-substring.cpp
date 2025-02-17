// https://leetcode.com/problems/minimum-window-substring/solutions/26808/here-is-a-10-line-template-that-can-solve-most-substring-problems/

class Solution {
public:
    string minWindow(string s, string t) {
        
        if(s.length()==0 || t.length()==0 || s.length()<t.length())
            return "";
        
        vector<int> v(256,0);
        for(int i=0;i<t.length();++i)
              v[t[i]]++;
        
        int start=0,end=0,ans_start=0;
        int minlength=INT_MAX;
        int count=0;
        while(end<s.length())
        {
            if(v[s[end]]>0)
                 count++;
            
            v[s[end]]--;
            while(count==(int)t.length())//until the the window condition is satified keep shriking the window
            {
                if(minlength>end-start+1)
                {
                    minlength=end-start+1;//update the minimum length continuously
                    ans_start=start; //starting index of the answer
                }
                
                v[s[start]]++;
                if(v[s[start]]>0)
                    count--;
                
                start++;
            }
            end++;
        }
        
        if(minlength==INT_MAX) //no string found
            return "";
        
        return s.substr(ans_start,minlength);
    }
};
