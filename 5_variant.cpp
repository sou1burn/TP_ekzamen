#include<iostream>
#include<vector>
#include<algorithm>
#include<exception>
#include <list>
#include<string>
#include <set>

template <typename T>
T f(const T& a) {
	if (a == 0) {
		throw std::exception("A is 0");
	}
	return 2 / a;
}

template <typename T>
void exchanger(T& src1, size_t len) {
	for (size_t i = 0; i < len; ++i) {
		try{
			src1[i] = f(src1[i]);
			std::cout << src1[i] << " ";
		}
		catch (std::exception){
			src1[i] = 0;
		}
	}
}

int unique_strings(std::list<std::string> lst) {

	std::set<std::string> set_str;

	for (auto & str : lst) {
		set_str.insert(str);
	}
	return set_str.size();
}

int main() {

	int src[] = { 1, 2, 3, 4, 5 };
	size_t length = sizeof(src) / sizeof(src[0]);
	exchanger(src, length);

	return 0;
}