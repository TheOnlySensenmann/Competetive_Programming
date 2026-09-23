using namespace std;
#include <vector>

bool checkIfNotAttacked(vector<vector<char>> matrix, int i, int depth);


int result = 0;

int main() {



    vector<vector<char>> matrix;



    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            matrix[i][j] = 'q';
            if (checkIfNotAttacked(matrix, i, j)) {
                ++result;
            }
        }
    }
}

bool checkIfNotAttacked(vector<vector<char>> matrix, int i, int depth) {
    for (int j = 0; j < matrix[0].size(); j++) {
        if (j == depth) {
            continue;
        }
        if (matrix[i][j] == 'q') {
            return false;
        }
    }
    int minus = i > depth ? i : depth;



    return true;
}

void place(vector<vector<char>> matrix, int depth) {
    if (depth == matrix.size()) {
        result++;
        return;
    }
    for (int i = 0; i < matrix.size(); i++) {
        if (matrix[i][depth] == '*') {
            continue;
        }
        matrix[depth][i] = 'q';
        if (checkIfNotAttacked(matrix, i, depth)) {
            place(matrix, depth + 1);
        }
        matrix[depth][i] = '.';
    }
}
