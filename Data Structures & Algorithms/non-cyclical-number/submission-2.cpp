class Solution {
public:

    long long get(int n){

        long long  sum = 0;

        while(n != 0){

            long long q = n%10;
            sum += (q*q);
            n = n / 10;
        }

        return sum;
    }

    bool isHappy(int n) {

        long long s = get(n), f = get(get(n));

        while(s != f && s != 1){

            s = get(s);
            f = get(get(f));
        }

        return s == 1;
    }
};
