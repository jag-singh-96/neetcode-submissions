class Solution {
public:

    unordered_map<string,int> map;

    int p(vector<int>& prices, int i, string op){

        if(i >= prices.size()){
            return 0;
        }

        int profit = 0;

        string st = to_string(i) + "#" + op + "#" + to_string(prices[i]) + "#";

        if(map.find(st) != map.end()){
            return map[st];
        }


        if(op == "buy"){
            profit += max(-1*prices[i]+ p(prices,i+1,"sell"),p(prices,i+1,"buy"));
        }else{
            profit += max(prices[i] + p(prices,i+2,"buy"),p(prices,i+1,"sell"));
        }

        return map[st] = profit;


    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        int index = 0;

       

        return p(prices,index,"buy");
        
    }
};
