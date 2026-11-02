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

        vector<pair<int,int>> v;

        for(auto i: intervals){
            v.push_back({i.start,1});
            v.push_back({i.end,-1});
        }

        sort(v.begin(),v.end());

        int count = 0;

        int maxt = 0;


        for(auto i: v){

            count += i.second;
            maxt = max(maxt,count);

        }
        
        return maxt;
    }
};
