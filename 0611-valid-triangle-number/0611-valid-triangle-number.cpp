class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans=0;
        for (int i=0; i<nums.size(); i++) {
            for (int j=i+1; j<nums.size(); j++) {
                int n = nums[i]+nums[j];
                int start=j+1, end=nums.size()-1; // j 뒤쪽 보기
                while (start <= end) {
                    int mid = start + (end-start)/2;
                    if (nums[mid] < n) {  
                        // 두 개를 더한 값이, 뒷부분 mid의 값보다 크면 그 뒷부분만 보면됨
                        // sort 되어 있기 때문에!! 그래서 start를 mid 다음으로 옮겨줌
                        start = mid+1;
                    } else {
                        // 근데 두 개를 더한 값이, 뒷부분 mid의 값보다 작으면 현재 mid보다 앞부분을 봐야 함
                        // 그래서 end를 mid 앞으로 당겨줌
                        end = mid-1;
                    }
                }
                // end가 당겨지면 거기까지만 보고, start가 뒤로 옮겨가면 어차피 그 앞은 다 조건을 만족하는 값이기 때문에
                // j+1부터 end까지가 모두 가능한 값이 됨. 따라서 (end-j)개만큼이 해당함
                ans += end-j;
            }
        }
        return ans;
    }
};