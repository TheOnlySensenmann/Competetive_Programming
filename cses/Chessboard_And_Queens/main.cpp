#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>

const int size = 8;


bool checkIfNotAttacked(char matrix[size][size], int i, int depth);

void place(char matrix[size][size], int depth);

std::string arrToString(char matrix[size][size]);

int result = 0;

int main() {
    char matrix[size][size];

    for (auto & i : matrix) {
        std::string line;
        std::cin >> line;
        strcpy(i, line.c_str());
    }

    place(matrix, 0);

    std::cout << result << std::endl;

}


bool checkIfNotAttacked(char matrix[size][size], int i, int depth) {
    for (int j = 0; j < size; j++) {
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
        if (y < 0 || x < 0 || y >= size || x >= size) {
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

        if (y < 0 || x < 0 || y >= size || x >= size) {
            break;
        }
        if (matrix[y][x] == 'q') {
            return false;
        }
    }


    return true;
}

void place(char matrix[size][size], int depth) {
    if (depth == size) {
        result++;
        // std::ofstream file("../log.txt", std::ios::app);
        // file << arrToString(matrix);
        // file << std::endl;
        // file.close();
        // return;
    }
    for (int i = 0; i < size; i++) {
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

std::string arrToString(char matrix[size][size]) {
    std::string result;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result += matrix[i][j];
        }
        result += '\n';
    }
    return result;
}
