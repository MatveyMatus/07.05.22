#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::string n;

    long long k;

    std::ifstream Values("input.txt");
    Values >> n >> k;
    Values.close();

    long res = 0,
        idx = 0;

    while (idx < n.length()) {
        while (res < k) {
            res = res * 10 + (n[idx++] - '0');
        }
        res = res % k;
    }


    std::ofstream result("output.txt");
    result << res;
    result.close();
}
