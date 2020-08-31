class SubrectangleQueries {
private:
    vector<vector<int> > rect;
    vector<vector<int> > history;
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        rect = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        vector<int> hist = { row1, row2, col1, col2, newValue };
        history.push_back(hist);
    }
    
    int getValue(int row, int col) {
        for (int i = history.size() - 1; i >= 0; i--) {
            if (row <= history[i][1] && row >= history[i][0] && col <= history[i][3] && col >= history[i][2])
                return history[i][4];
        }
        
        return rect[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
