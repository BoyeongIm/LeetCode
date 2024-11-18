#include <string>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
class Solution {
public:
static bool cmp(pair<char, int>&a, pair<char, int>&b) {
    return a.second > b.second;
}

string frequencySort(string s) {
    map<char, int> frequency;
    for (char c : s) {
        frequency[c]++;
    }
    
    vector<pair<char, int>> freq2(frequency.begin(), frequency.end());
    sort(freq2.begin(), freq2.end(), cmp);

    string answer = "";
    for (auto p : freq2) {
        for (int j=0; j<p.second; j++) answer += p.first;
    }

    return answer;
}
};