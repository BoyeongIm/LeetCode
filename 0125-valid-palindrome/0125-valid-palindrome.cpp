class Solution {
public:
    bool isPalindrome(string s) {
        if (s.length() == 1) return true;

        string new_str;
        for (int i=0; i<s.length(); i++) {
            if ((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='0'&&s[i]<='9')) {
                new_str += tolower(s[i]);
            }
        }
        
        for (int j=0; j<new_str.length()/2; j++) {
            if (new_str[j] != new_str[new_str.length()-1-j]) return false;
        }

        return true;
    }
};