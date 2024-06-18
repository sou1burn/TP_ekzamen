#include<iostream>
#include<vector>
#include<algorithm>
#include<exception>


void before_after(std::vector<int>& nums, int before, int after) {

	for (int i = 0; i < nums.size(); ++i) {
		if (nums[i] == before) {
			nums.insert(nums.begin() + i + 1, after);
			++i;
		}
	}
}

template <typename T>

void copier(const T* src1, const T* src2, T* result, size_t len1, size_t len2, size_t len_res) {

	if (len_res < len1 || len_res < len1 + len2) {
		throw std::exception("Not enough length");
	}

	for (size_t i = 0; i < len1; ++i) {
		result[i] = src1[i];
	}

	for (size_t i = 0; i < len2; ++i) {
		result[len1 + i] = src2[i];
	}

}

int main() {

	std::vector<int> vec = { 1, 2, 3, 2, 4, 2, 5 };
	int before = 2;
	int after = 10;

	before_after(vec, before, after);

	
	for (int num : vec) {
		std::cout << num << " ";
	}
	std::cout << std::endl;

	const size_t len1 = 3;
	const size_t len2 = 4;
	const size_t result_len = len1 + len2  ;

	int src1[len1] = { 1, 2, 3 };
	int src2[len2] = { 4, 5, 6, 7 };
	int result[result_len];

	try {
		copier(src1,  src2,  result, len1, len2, result_len);

		for (size_t i = 0; i < result_len; ++i) {
			std::cout << result[i] << " ";
		}
		std::cout << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}