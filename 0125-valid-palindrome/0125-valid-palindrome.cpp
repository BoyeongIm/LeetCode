class Solution {
public:
    bool isPalindrome(string s) {
        if (s.length() == 1) return true;

        string new_str;
        for (int i=0; i<s.length(); i++) {
            if (isalpha(s[i]) || isdigit(s[i])) {
                new_str += tolower(s[i]);
            }
        }
        
        for (int j=0; j<new_str.length()/2; j++) {
            if (new_str[j] != new_str[new_str.length()-1-j]) return false;
        }

        return true;
    }
};