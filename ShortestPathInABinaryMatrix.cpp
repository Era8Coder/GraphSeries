#include<bits/stdc++.h>
using namespace std;

// Step - 1) BaSiC => Always make a data structure point in the case of Grid 
struct Point{           // Defining the new data_type
    int x,y;    
    Point(int _x, int _y){              // Making _x and _y as new coordinates using point 
        x = _x;
        y = _y;             
    }

    // These two functions are required because of Use of Comparing two points are equal or not in map
    // Overload < operator for map key comparison
    bool operator<(const Point& other) const {
        return tie(x, y) < tie(other.x, other.y);
    }

    // Overload == operator for equality comparison
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

// Step - 2) Next Work is to check that points on which we are traversing and modifying are valid or not
bool isValidPoint(int x, int y, int rows, int cols){            // Checking validity of point
    return (x>=0 && x<rows && y>=0 && y<cols);          // if all these conditions are satisfied simultaneously then only we are on the valid point
}

int BFS(Point start, map<Point,vector<Point>> &graph, Point end){
    queue<Point> q;
    map<Point,int> distance;
    
    for(auto &it : graph){
        distance[it.first] = INT_MAX;
    }

    distance[start] = 0;
    q.push(start);

    while(!q.empty()){
        Point node = q.front();
        q.pop();

        for(auto &neighbor : graph[node]){
            if(distance[neighbor] == INT_MAX){
                distance[neighbor] = distance[node] + 1;
                q.push(neighbor);
            }
        }
    }

    if(distance[end] != INT_MAX){
        return distance[end] + 1;               // -->> SINCE WE HAVE TO RETURN MAXIMUM NUMBER OF NODES <<--
    }

    return -1;
}

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    if(n == 1 && grid[0][0] == 0){
        return 1;
    }else if(n == 1 && grid[0][0] == 1){
        return -1;
    }

    if(grid[n-2][n-2] == 1 && grid[n-2][n-1] == 1 && grid[n-1][n-2] == 1){
        return -1;
    }
    map<Point,vector<Point>> graph;                 // Creating a Graph for Using Point data - structure
    vector<int> delta_x = {-1, -1, -1, 1, 1, 1, 0, 0};
    vector<int> delta_y = {-1, 0, 1, 0, 1, -1, -1, 1};
    int rows = grid.size();
    int cols = grid[0].size();

    // Check if start or end is blocked
    if(grid[0][0] == 1 || grid[rows-1][cols-1] == 1) {
        return -1;
    }

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(grid[i][j] == 0){
                for(int k=0; k<8; k++){
                    int new_x = i + delta_x[k];
                    int new_y = j + delta_y[k];
                    if(isValidPoint(new_x,new_y,rows,cols) && grid[new_x][new_y] == 0){
                        graph[Point(i,j)].push_back(Point(new_x,new_y));     
                    }
                }
            }
        }
    }
    Point start = Point(0,0);
    Point end = Point(rows-1, cols-1);
    int ans = BFS(start,graph,end);
    return ans;
}

int main(){
    vector<vector<int>> grid = {{0,0,0,0,1},{1,0,0,0,0},{0,1,0,1,0},{0,0,0,1,1},{0,0,0,1,0}};
    cout << shortestPathBinaryMatrix(grid) << endl;
    return 0;
}
