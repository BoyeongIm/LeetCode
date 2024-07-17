class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        if (x<10) return true;

        string integer = to_string(x);
        int l = integer.length();
        for (int i=0; i<l/2; i++) {
            if (integer[i] != integer[(l-1)-i]) return false;
        }

        return true;
    }
};