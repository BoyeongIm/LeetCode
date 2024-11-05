#include <algorithm>
#include <set>
using namespace std;

class ExamRoom {
public:
    int size;
    set<int> seated;
    ExamRoom(int n) : size(n) {    }
    
    int seat() {
        if (seated.empty()) {
            seated.insert(0);
            return 0;
        }

        int seat = 0;
        int max_distance = *seated.begin();

        auto prev = seated.begin();
        for (auto it=seated.begin(); it!=seated.end(); it++) {
            int currdist = (*it-*prev)/2;
            if (currdist > max_distance) {
                max_distance = currdist;
                seat = *prev + currdist;
            }
            prev = it;
        }

        if (max_distance < (size-1)-*prev) {
            seat = size-1;
        }

        seated.insert(seat);
        // sort(seated.begin(), seated.end());
        return seat;
    }
    
    void leave(int p) {
        seated.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */