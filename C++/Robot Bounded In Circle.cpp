// https://leetcode.com/problems/robot-bounded-in-circle/

/*
Hint : try drawing the vectors on paper
Quick Explanation :
if at end of one set of instructions if the robot is back at (0,0)
or points at any direction other than North, then the robot is guaranteed
to be inside some circle. Here dir : 0,1,2,3 represent N,W,S,E respectively.
*/

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int dir = 0, x = 0, y = 0;
        for (auto i : instructions) {
            if (i == 'L')dir = (dir + 1) % 4;
            if (i == 'R')dir = (dir - 1 + 4) % 4;
            if (i == 'G') {
                if (dir == 0)y++;
                if (dir == 1)x--;
                if (dir == 2)y--;
                if (dir == 3)x++;
            }
        }
        return ((x == 0 and y == 0) or (dir != 0));
    }
};
