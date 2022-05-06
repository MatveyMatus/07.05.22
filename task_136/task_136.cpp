#include <iostream>
#include <fstream>
#include <iomanip>

int main()
{
    int size;
    std::ifstream Values("input.txt");
    Values >> size;

    int** Array = new int* [size] {};
    for (int i = 0; i < size; ++i) {
        Array[i] = new int[size];
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            Values >> Array[i][j];
        }
    }

    Values.close();

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << std::setw(4) << Array[i][j];
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    for (int q = 0; q < size; ++q) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (Array[i][q] != -1 && Array[q][j] != -1 && i != j) {
                    if (Array[i][j] == -1) {
                        Array[i][j] = Array[i][q] + Array[q][j];
                    }
                    else {
                        Array[i][j] = std::min(Array[i][j], Array[i][q] + Array[q][j]);
                    }
                }
            }
        }
    }

    int result = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (Array[i][j] > result) {
                result = Array[i][j];
            }
        }
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << std::setw(4) << Array[i][j];
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << result;


    std::ofstream out("output.txt");
    out << result;
    out.close();

    for (int i = 0; i < size; ++i) {
        delete[] Array[i];
    }
    delete[] Array;
}
