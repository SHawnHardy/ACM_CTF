class Solution {
public:
    /*
     * @param : An integer
     * @param : An integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        // write your code here
        while (a&b) {
            int aa=a;
            int bb=b;
            a=aa^bb;
            b=(aa&bb)<<1;
        }
        return a^b;
    }
};
