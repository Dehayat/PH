
#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;

const int N = 100000000;
int a[N];

inline void Function() {
	for (int i = 0; i < N; i++) {
		a[i] = i;
	}
}

int main()
{

	srand(time(0));
	chrono::high_resolution_clock clock;
	std::cout << std::fixed << std::setprecision(10);


	auto t1 = clock.now();
	Function();
	auto t2 = clock.now();

	chrono::duration<double> duration = t2 - t1;

	cout << duration.count() << endl;

	return 0;
}
