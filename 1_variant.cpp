#include<iostream>
#include<vector>
#include<algorithm>
#include <exception>
#include <set>

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

int unique_finder(std::vector<int> m) {

	std::set<int> unique(m.begin(), m.end());

	std::cout << "Number of unique elements: " << unique.size() << "\n";
	return unique.size();
}

void generatePlateNumbers(int M, int N, std::string current, std::vector<std::string>& result) {
	// Base case: when the length of the current string equals M + N
	if (current.length() == M + N) {
		result.push_back(current);
		return;
	}

	// Add a letter if the number of letters added is less than M
	if (M > 0) {
		for (char c = 'A'; c <= 'Z'; ++c) {
			generatePlateNumbers(M - 1, N, current + c, result);
		}
	}

	// Add a digit if the number of digits added is less than N
	if (N > 0) {
		for (char d = '0'; d <= '9'; ++d) {
			generatePlateNumbers(M, N - 1, current + d, result);
		}
	}
}

std::vector<std::string> generatePlateNumbers(int M, int N) {
	std::vector<std::string> result;
	generatePlateNumbers(M, N, "", result);
	return result;
}


int main() {

	int N = 2; // letters
	int M = 2; // digits

	std::vector<std::string> plateNumbers = generatePlateNumbers(M, N);

	for (const std::string& plate : plateNumbers) {
		std::cout << plate << std::endl;
	}

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