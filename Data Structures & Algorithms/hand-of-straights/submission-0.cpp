class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        map<int, int> map;

        for(auto h: hand){
            map[h]++;
        }


        for(auto m: map){
            if(m.second > 0 ){
                int count = m.second;
                
                for(int i = 0; i < groupSize; i++){
                    if(map[m.first + i] < count){
                        return false;
                    }
                    //cout<< m.first + i<<"--"<<map[m.first + i]<<endl;
                    map[m.first + i] -= count;
                }
            }
        }
        return true;
    }
};
