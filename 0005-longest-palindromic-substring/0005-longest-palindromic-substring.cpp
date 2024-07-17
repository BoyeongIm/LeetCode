class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length()<=1) return s;

        int l = s.length();
        vector<vector<bool>> dp(l+1, vector<bool>(l+1)); // dp[i][j]: jth index에서 시작하는, i개의 문자로 이루어진 단어가 pandrolime인지 확인하고자 함

        for (int i=0; i<l; i++) {
            dp[1][i] = true;
        }

        int max_len = 1;

        for (int i=0; i<l-1; i++) {
            if (s[i]==s[i+1]) {
                dp[2][i] = true;
                max_len = 2;
            }
        }
        
        for (int i=3; i<=l; i++) { // 총 길이
            for (int j=0; j<l-i+1; j++) { // 시작점
                if (dp[i-2][j+1]) { // 지금 현재 길이에서 양 끝 두개를 뺀 것이 pandrolime인지 확인
                    if (s[j] == s[j+i-1]) { // 양 끝이 같은 문자인지 확인
                        dp[i][j] = true;
                        // 여기서 j를 max의 start로 잡고 뒤에서 이걸 시작점으로 해버리면, 양 끝이 같은 문자가 아닌 경우에는 start가 업데이트가 안되는데 위에서 int start를 초기화해준 값이 그대로 밑으로 내려가서 제대로 업데이트가 안됨
                        max_len = i;
                    }
                }
            }
        }

        string ans;
        for (int i=0; i<l; i++) {
            if (dp[max_len][i]) {
                ans = s.substr(i, max_len);
            }
        }

        return ans;
    }

    /*
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.length()-1;

        while (start<end) {
            if (s[start]!=s[end]) {
                return false;
            }

            start++;
            end--;
        }

        return true;
    }
    string longestPalindrome(string s) {
        if (s.length() <=1) return s;

        int start = 0;
        int max_length = 1;
        for (int i=0; i<s.length(); i++) {
            for (int j=i+max_length; j<=s.length(); j++) {
                if (j-i > max_length && isPalindrome(s.substr(i, j-i))) {
                    max_length = j-i;
                    start = i;
                }
            }
        }

        return s.substr(start, max_length);
    }
    */
};