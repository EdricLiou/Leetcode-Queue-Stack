//BFS 
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited{{0}};
        queue<int> q{{0}};
        while (!q.empty()) {
            int t = q.front(); q.pop();
            for (int key : rooms[t]) {
                if (visited.count(key)) continue;
                visited.insert(key);
                if (visited.size() == rooms.size()) return true;
                q.push(key);
            }
        }
        return visited.size() == rooms.size();
    }
};

//HashSet
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited;
        helper(rooms, 0, visited);
        return visited.size() == rooms.size();
    }
    void helper(vector<vector<int>>& rooms, int cur, unordered_set<int>& visited) {
        visited.insert(cur);
        for (int key : rooms[cur]) {
            if (!visited.count(key)) helper(rooms, key, visited);
        }
    }
};

//https://www.cnblogs.com/grandyang/p/10415773.html
