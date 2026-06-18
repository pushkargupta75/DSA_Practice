class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minu=6.0*minutes;
        double ho=30.0*hour+0.5*minutes;
        double diff=abs(minu-ho);
        return min(diff,360.0-diff);
    }
};