#include<iostream>
#include<vector>
#include<algorithm>
#include <exception>
#include <set>

//1 задание
template <typename T>
void merger(const T* src1, T* src2, size_t len1, size_t len2) {

	if (len1 != len2) {
		throw std::exception("Lengths are not the same");
	}

	for (int i = 0; i < len2; ++i) {
		src2[i] = std::max(src1[i], src2[i]);
		std::cout << src2[i] << ", ";
	}
	std::cout << "\n";

}

//2 задание
int unique_finder(std::vector<int> m) {

	std::set<int> unique(m.begin(), m.end());

	std::cout << "Number of unique elements: " << unique.size() << "\n";
	return unique.size();
}

//3 задание
void generatePlates(int N, int M, std::string current, std::vector<std::string>& plates) {

	if (N == 0 && M == 0) {
		plates.push_back(current);
		return;
	}

	if (N > 0) {
		for (char c = 'A'; c <= 'Z'; ++c) {
			generatePlates(N - 1, M, current + c, plates);
		}
	}

	if (M > 0) {
		for (char d = '0'; d <= '9'; ++d) {
			generatePlates(N, M - 1, current + d, plates);
		}
	}
}

std::vector<std::string> generateAllPlates(int N, int M) {
	std::vector<std::string> plates;
	generatePlates(N, M, "", plates);
	return plates;
}


int main() {

	int N = 2; // Number of letters
	int M = 3; // Number of digits

	std::vector<std::string> plates = generateAllPlates(N, M);

	for (const auto& plate : plates) {
		std::cout << plate << std::endl;
	}

	std::cout << "Total plates: " << plates.size() << std::endl;

	int arr1[5] = { 1, 2 ,5 ,6 , 9 };
	int arr2[5] = { 1, 6, 4, 9329, 99 };
	int arr3[6] = { 4, 5, 99, 77, 87, 66 };

	std::vector<int> mas = { 1, 1 ,1, 3, 5, 5, 8, 9, 7, 1 };

	try {
		merger(arr1, arr3, 5, 5);
	}
	catch (std::exception& e){
		std::cerr << "Error: " << e.what() << std::endl;
	}

	unique_finder(mas);

	return 0;
}