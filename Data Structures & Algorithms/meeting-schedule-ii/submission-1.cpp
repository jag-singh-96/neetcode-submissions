/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {

        
        vector<pair<int,int>> p;

        for(auto i: intervals){
            p.push_back({i.start,1});
            p.push_back({i.end,-1});
        }


        sort(p.begin(),p.end());

        int count = 0;

        int maxAns = 0;
        for(auto i : p){
            count += i.second;
            maxAns = max(maxAns, count);
        }


        return maxAns;
        
        
    }
};
