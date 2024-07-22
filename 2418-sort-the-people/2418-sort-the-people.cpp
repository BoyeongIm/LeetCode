class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, string> hname;
        for (int i = 0; i < names.size(); i++) 
            hname[heights[i]] = names[i];
        
        vector<string> sorted_result;
        for (auto it = hname.rbegin(); it != hname.rend(); it++)
            sorted_result.push_back(it->second);
        
        return sorted_result;
    }
};