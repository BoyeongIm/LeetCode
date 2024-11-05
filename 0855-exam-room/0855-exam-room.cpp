#include <algorithm>
#include <vector>
using namespace std;

class ExamRoom {
public:
    int size;
    vector<int> seated;
    ExamRoom(int n) : size(n) {    }
    
    int seat() {
        if (seated.size()==0) {
            seated.push_back(0);
            return 0;
        }

        int seat = 0;
        sort(seated.begin(), seated.end());
        int max_distance = seated[0];

        for (int i=0; i<seated.size()-1; i++) {
            int currdist = (seated[i+1]-seated[i])/2;
            if (currdist > max_distance) {
                max_distance = currdist;
                seat = seated[i] + currdist;
            }
        }

        if (max_distance < (size-1)-seated.back()) {
            seat = size-1;
        }

        seated.push_back(seat);
        return seat;
    }
    
    void leave(int p) {
        seated.erase(remove(seated.begin(), seated.end(), p), seated.end());
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */