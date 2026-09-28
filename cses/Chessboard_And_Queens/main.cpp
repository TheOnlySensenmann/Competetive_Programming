#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 8;


bool checkIfNotAttacked(vector<string> matrix, int i, int depth);

void place(vector<string> matrix, int depth);

std::string arrToString(vector<string> matrix);

int result = 0;

int main() {
    vector<string> matrix;

    for (int i = 0; i < SIZE; i++) {
        string line;
        cin >> line;
        matrix.push_back(line);
    }

    place(matrix, 0);

    std::cout << result << std::endl;

}


bool checkIfNotAttacked(vector<string> matrix, int i, int depth) {
    for (int j = 0; j < SIZE; j++) {
        if (j == depth) {
            continue;
        }
        if (matrix[j][i] == 'q') {
            return false;
        }
    }

    int minus = i < depth ? i : depth;

    for (int j = 0; true; j++) {
        if (j == minus) {
            continue;
        }
        int x = i - minus + j;
        int y = depth - minus + j;
        if (y < 0 || x < 0 || y >= SIZE || x >= SIZE) {
            break;
        }
        if (matrix[y][x] == 'q') {
            return false;
        }
    }

    minus = 7 - i < depth ? 7 - i : depth;

    for (int j = 0; true; j++) {
        if (j == minus) {
            continue;
        }
        int x = i + minus - j;
        int y = depth - minus + j;

        if (y < 0 || x < 0 || y >= SIZE || x >= SIZE) {
            break;
        }
        if (matrix[y][x] == 'q') {
            return false;
        }
    }


    return true;
}

void place(vector<string> matrix, int depth) {

    if (depth == SIZE) {
        result++;
        return;
    }
    for (int i = 0; i < SIZE; i++) {
        if (matrix[depth][i] == '*') {
            continue;
        }
        matrix[depth][i] = 'q';
        if (checkIfNotAttacked(matrix, i, depth)) {
            place(matrix, depth + 1);
        }
        matrix[depth][i] = '.';
    }
}