class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int cx=0;
        int cy=0;
        if(ax1<=bx1)
            cx = max(cx, min(ax2, bx2)-bx1);
        else
            cx = max(cx, min(bx2, ax2)-ax1);
        
        if(ay1<=by1)
            cy = max(cy, min(ay2, by2)-by1);
        else
            cy = max(cy, min(by2, ay2)-ay1);
         
        return (ax2-ax1)*(ay2-ay1)+(bx2-bx1)*(by2-by1)-cx*cy;

        
    }
};