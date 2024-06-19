#include <vector>
using namespace std;

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() : val(false), isLeaf(false), topLeft(nullptr), topRight(nullptr), bottomLeft(nullptr), bottomRight(nullptr) {}

    Node(bool _val, bool _isLeaf) : val(_val), isLeaf(_isLeaf), topLeft(nullptr), topRight(nullptr), bottomLeft(nullptr), bottomRight(nullptr) {}
};

bool isAllSame(vector<vector<int>>& grid, int x, int y, int n) {
    int val = grid[x][y];
    for (int i = x; i < x + n; ++i) {
        for (int j = y; j < y + n; ++j) {
            if (grid[i][j] != val) {
                return false;
            }
        }
    }
    return true;
}

Node* solve(vector<vector<int>>& grid, int x, int y, int n) {
    if (isAllSame(grid, x, y, n)) {
        return new Node(grid[x][y], true);
    } else {
        Node* root = new Node();
        root->topLeft = solve(grid, x, y, n / 2);
        root->topRight = solve(grid, x, y + n / 2, n / 2);
        root->bottomLeft = solve(grid, x + n / 2, y, n / 2);
        root->bottomRight = solve(grid, x + n / 2, y + n / 2, n / 2);
        return root;
    }
}

Node* construct(vector<vector<int>>& grid) {
    int n = grid.size();
    return solve(grid, 0, 0, n);
}

int main(){

    return 0;
}