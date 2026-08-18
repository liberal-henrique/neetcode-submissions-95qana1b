class Solution {
public:
    pair<int, int> get1Position(vector<vector<char>>& grid) {
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[row].size(); col++) {
                if (grid[row][col] == '1')
                    return {row, col};
            }
        }
        return pair{-1, -1};
    }

    void floodFill(vector<vector<char>>& grid, int row, int col, int rowLimit, int colLimit) {
        if (row > rowLimit || row < 0 || col < 0 || col > colLimit || grid[row][col] == '0' || grid[row][col] == 'a')
            return;
        if (grid[row][col] == '1') 
            grid[row][col] = 'a';
        floodFill(grid, row - 1, col, rowLimit, colLimit);
        floodFill(grid, row + 1, col, rowLimit, colLimit);
        floodFill(grid, row, col - 1, rowLimit, colLimit);
        floodFill(grid, row, col + 1, rowLimit, colLimit);
    }

    int numberOfIslands(vector<vector<char>>& grid, int counter, int rowsSize, int columnsSize) {
        pair<int, int> initialPos = get1Position(grid);
        if (initialPos.first == -1 )
            return counter;
        floodFill(grid, initialPos.first, initialPos.second, rowsSize, columnsSize);
        return numberOfIslands(grid, ++counter, rowsSize, columnsSize);
    }

    int numIslands(vector<vector<char>>& grid) {
        return numberOfIslands(grid, 0, grid.size() - 1, grid[0].size() - 1);
    }
};
