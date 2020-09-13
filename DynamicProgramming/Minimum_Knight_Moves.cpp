/* In an infinite chess board with coordinates from -infinity to +infinity, you have a knight at square [0, 0].

A knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction, then one square in an orthogonal direction.

Return the minimum number of steps needed to move the knight to the square [x, y].  It is guaranteed the answer exists.

 

Example 1:

Input: x = 2, y = 1
Output: 1
Explanation: [0, 0] → [2, 1]
Example 2:

Input: x = 5, y = 5
Output: 4
Explanation: [0, 0] → [2, 1] → [4, 2] → [3, 4] → [5, 5] */

class Solution {
    unordered_map<int, unordered_map<int, int>> visited;
public:
    int minKnightMoves(int x, int y) {
        unordered_map <string, int> hashmap;
        hashmap["0,0"] = 0;
        hashmap["1,0"] = 3;
        hashmap["1,1"] = 2;
		hashmap["2,0"] = 2;
        int val = helper2(x,y,hashmap);
        for (auto p: hashmap)
            cout<<p.first<<":"<<p.second<<endl;
        return val;
    }
    int helper2(int x, int y, unordered_map<string, int>& hashmap){
        // Sysmetrical of axis
		x=abs(x);
		y=abs(y);
        if (x<y)
            swap(x,y);
        string s = to_string(x) + "," + to_string(y);
        if (hashmap.find(s) != hashmap.end())
            return hashmap[s];
        int temp = min(helper2(x-2,y-1, hashmap), helper2(x-1, y-2, hashmap))+1;
        hashmap[s] = temp;
        return temp;
    }
};


//With BFS, very slow
static const vector<pair<int,int>> DIRECTIONS = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
class Solution {
public:
    int minKnightMoves(int x, int y) {
        x = abs(x);
        y = abs(y);
        queue<pair<int,int>> q;
        set<string> visited;
        q.push({0,0});
        visited.insert("0,0");
        int i =0, j=0;
        int count = 0;
        while(!q.empty())
        {
            int len = q.size();
            count++;
            //cout<<"count is" <<count<<endl;
            for (int k=0; k<len; ++k)
            {
                auto cord = q.front(); q.pop();
                if (cord.first == x and cord.second == y)
                    return count-1;
                for (auto dir: DIRECTIONS)
                {
                    int ii = cord.first + dir.first;
                    int jj = cord.second + dir.second;
                    if (ii >=-1 and jj >=-1 and visited.find(to_string(ii)+ "," + to_string(jj))==visited.end())
                    {
                        //cout<<"hereInside"<<endl;
                        visited.insert(to_string(ii)+ "," + to_string(jj));
                        q.push({ii,jj});
                    }
                }
            }
        }
        return -1;
    }
};