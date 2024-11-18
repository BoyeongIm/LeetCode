class Solution {
public:
    static string repeatString(string& s, int n) {
        string result = "";
        for(int i=0; i<n; i++) {
            result += s;
        }
        return result;
    }

    static bool cmp(string& a, string& b) {
        return repeatString(a, 10) > repeatString(b, 10);
    }

    string largestNumber(vector<int>& nums) {
        vector<string> tostr;
        for (int n : nums) {
            tostr.push_back(to_string(n));
        }

        sort(tostr.begin(), tostr.end(), cmp);
        string answer = "";
        for (string n : tostr) {
            answer += n;
        }

        if (answer[0] == '0') return "0";

        return answer;
    }
};