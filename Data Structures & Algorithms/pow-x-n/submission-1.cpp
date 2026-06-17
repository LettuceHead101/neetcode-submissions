class Solution {
public:
    double myPow(double x, int n) {
        double var = 1;
        int size = (n < 0)? (n * -1) : n;

        for(int i = 0; i < size; ++i){
            var = var * x;
        }

        return (n < 0) ? (1/var) : var;

        
    }
};
