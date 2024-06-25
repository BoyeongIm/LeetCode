class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;
        for (char c : magazine) {
            mp[c] ++;
        }
        for (char c : ransomNote) {
            if (mp.find(c) == mp.end() || mp[c] == 0) { // 아예 못찾거나, 더이상 쓸 수 있는 문자가 없거나
                return false;
            }
            mp[c]--;
        }
        return true;
    }
};