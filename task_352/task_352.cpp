#include <iostream>
#include <fstream>
#include <string>

bool irred(int x, int y, int k) {
	for (int i = 0; i < y; ++i) {
		if (x % k == 0 && y % k == 0) {
			return true;
		}
		k++;
	}
	return false;
}

int main()
{
	int num;
	std::ifstream Value("input.txt");
	Value >> num;
	Value.close();

	int dr[2]{};
	int duration = 2;

	for (int ch = 1; ch < num - 1; ++ch) {
		for (int zn = ch + 1; zn < num; ++zn) {
			if (ch + zn == num && !irred(ch,zn,duration)) {
				dr[0] = ch;
				dr[1] = zn;
			}
		}
	}

	std::ofstream result("output.txt");
	result << dr[0] << "/" << dr[1];
	result.close();
}
