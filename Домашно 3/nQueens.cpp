#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
using namespace std;

bool isSafe(vector<vector<int>> &mat, int row, int col){
    for(int i=0; i<row; i++)
        if(mat[i][col])
            return 0;
    for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--)
        if(mat[i][j])
            return 0;
    for(int i=row-1, j=col+1; i>=0 && j<mat.size(); i--, j++)
        if(mat[i][j])
            return 0;
    return 1;
}

void placeQueens(vector<vector<int>> &mat, vector<vector<int>> &result, int row){
    if(row==mat.size()){
        vector<int> ans;
        for(size_t i=0; i<mat.size(); i++){
            for(size_t j=0; j<mat[i].size(); j++)
                if (mat[i][j])
                    ans.push_back(j+1);
        }
        result.push_back(ans);
        return;
    }
    
    for(int i=0; i<mat.size(); i++){
        if(isSafe(mat, row, i)){
            mat[row][i]=1;
            placeQueens(mat, result, row+1);
            mat[row][i]=0;
        }
    }
}

vector<vector<int>> nQueen(int n){
    vector<vector<int>> mat(n, vector<int>(n, 0));
    vector<vector<int>> result;
    placeQueens(mat, result, 0);
    return result;
}

int main(){
    int n;
    cin >> n;
    auto start=std::chrono::high_resolution_clock::now();
    vector<vector<int>> result=nQueen(n);
    auto end=std::chrono::high_resolution_clock::now();
    double time_ms=std::chrono::duration<double, std::milli>(end - start).count();
    cout << "The nQueens problem for " << n << 'x' << n << " chessboard has " << result.size() << " solutions!" << '\n';
    cout << time_ms;
    /*for(size_t i=0; i<result.size(); i++){
        for(size_t j=0; j<result[i].size(); j++)
            cout << result[i][j] << " ";
        cout << '\n';
    } */
    
    return 0;
}