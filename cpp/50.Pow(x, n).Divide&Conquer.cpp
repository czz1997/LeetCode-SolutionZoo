// 100% faster
// Time complexity O(logn)

class Solution {
public:
    double myPow(double x, int n) {
        double res;
        if(n == 0)
            return 1;
        if(n % 2 == 0)
            res = myPow(x * x, abs(n)/2);
        else{
            res = x * myPow(x * x, (abs(n)-1)/2);
        }
        if(n<0){
            res = 1 / res;
        }
        return res;
    }
};
