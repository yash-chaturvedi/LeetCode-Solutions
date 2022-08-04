class Solution {
public:
    int mirrorReflection(int p, int q) {
        while(p%2 == 0 && q%2 == 0) {
            p/=2;
            q/=2;
        }
        int numReflections = p, numRooms = q;
        
        if(numReflections % 2 == 0) return 2;
        
        if(numRooms % 2 == 0) return 0;
        
        return 1;
    }
};