#include <iostream>
#include <fstream>

//Последовательность Джона Фарея
std::ofstream result("output.txt");
void fact_T(int n, int x, int y, int z, int t) {
	int a = x + z;
	int b = y + t;
	if (b <= n) {
		fact_T(n, x, y, a, b);
		result << a << "/" << b << std::endl;
		fact_T(n, a, b, z, t);
	}
}

void fact(int n) {
	fact_T(n, 0, 1, 1, 1);
}

int main()
{
	int x;
	std::ifstream Value("input.txt");
	Value >> x;
	Value.close();

	fact(x);

	result.close();
}
