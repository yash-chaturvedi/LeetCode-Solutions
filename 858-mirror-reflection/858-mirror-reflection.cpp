class Solution {
public:
    int mirrorReflection(int p, int q) {
        // while(p%2 == 0 && q%2 == 0) {
        //     p/=2;
        //     q/=2;
        // }
        
        int g = gcd(p, q);
        p /= g;
        q /= g;
        
        int minReflections = p, minRooms = q;
        
        if(minReflections % 2 == 0) return 2;
        
        if(minRooms % 2 == 0) return 0;
        
        return 1;
    }
};