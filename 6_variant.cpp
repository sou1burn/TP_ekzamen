#include<iostream>
#include<vector>
#include<algorithm>
#include<exception>
#include <list>
#include <map>

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
		try {
			src1[i] = f(src1[i]);
			std::cout << src1[i] << " ";
		}
		catch (std::exception) {
			throw (std::runtime_error("RUNTIME ERROR"));
		}
	}
}

int most_frequent(std::list<int> m) {
	std::map<int, int> mp;
	for (int i : m) {
		mp[i]++;
	}
	int max_freq = 0;

	int most_frequent = m.front();
	for (auto& pair : mp) {
		if (pair.second > max_freq) {
			max_freq = pair.second;
			most_frequent = pair.first;
		}
	}
	return most_frequent;
}


int main() {
	try {
		int src[] = { 1, 2, 0, 4, 5 };
		size_t len = sizeof(src) / sizeof(src[0]);

		exchanger(src, len);

		for (size_t i = 0; i < len; ++i) {
			std::cout << src[i] << " ";
		}
		std::cout << std::endl;
	}
    catch (const std::runtime_error& e) {
	std::cout << "Caught runtime_error: " << e.what() << std::endl;
}
	std::list<int> nums = { 1, 2, 2, 3, 3, 3, 3 ,3 , 4, 4, 4, 4 };
	std:: cout << "Most frequent: "<< most_frequent(nums);

	return 0;
}