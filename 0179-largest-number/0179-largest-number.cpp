class Solution {
public:
    static bool cmp(string& a, string& b) {
        return a+b > b+a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> numstring;
        for (auto n : nums) {
            numstring.push_back(to_string(n));
        }

        sort(numstring.begin(), numstring.end(), cmp);
        string answer;

        for (auto s : numstring) {
            answer += s;
        }
        if (answer[0] == '0') return "0";
        return answer;
    }
};