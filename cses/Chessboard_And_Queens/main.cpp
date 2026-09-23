using namespace std;
#include <vector>

bool check(vector<vector<char>> matrix, int i, int j);


int main() {
    int result = 0;


    vector<vector<char>> matrix;



    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            matrix[i][j] = 'q';
            if (check(matrix, i, j)) {
                ++result;
            }
        }
    }
}

bool check(vector<vector<char>> matrix, int i, int j) {

}

void place(vector<vector<char>> matrix, int depth) {
    for (int i = 0; i < matrix.size(); i++) {

    }
}
