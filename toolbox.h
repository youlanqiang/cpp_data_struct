#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

namespace toolbox {
	template <typename T>
	void println(T str) {
		std::cout << str << std::endl;
	}

	template <typename T>
	void print(T str) {
		std::cout << str;
	}
}
