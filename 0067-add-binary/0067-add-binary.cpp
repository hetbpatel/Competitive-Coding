class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int n = a.size();
        int m = b.size();
        string res = "";
        int i = n - 1, j = m - 1;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) {
                sum += a[i--] - '0';
            }
            if (j >= 0) {
                sum += b[j--] - '0';
            }
            res += to_string(sum % 2);
            carry = sum / 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

/*-------------------------------------------------------------------------------------------------------*/

class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size();
        int m = b.size();
        int carry=0;
        int i=n-1;
        int j=m-1;
        string ans="";

        while(i>=0 or j>=0 or carry)
        {
            if(i>=0)    carry+=a[i]-'0';
            if(j>=0)    carry+=b[j]-'0';
        
            ans+=carry%2+'0';
            carry/=2;

            i--;j--;
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};
