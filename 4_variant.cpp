#include<iostream>
#include<vector>
#include<algorithm>
#include<exception>
#include<list>

template <typename T>
void copier(std::vector<T> src1, std::vector<T> src2, std::vector<T>& result) {
	
	std::vector<T>& larger = (src1.size() > src2.size())? src1 : src2;

	if (result.size() < larger.size()) {
		throw std::exception("Not enough space");
	}

	for (size_t i = 0; i < larger.size(); ++i) {
		result[i] = larger[i];
	}
	
}

void deleter_of_odd(std::list<int>& lst) {

    for (auto it = lst.begin(); it != lst.end();) {
        if (*it % 2 != 0) {
            it = lst.erase(it);
        }
        else {
            ++it;
        }
    }
}

int main() {

    std::vector<int> src1 = { 1, 2, 3 };
    std::vector<int> src2 = { 4, 5, 6, 7, 8 };
    std::vector<int> result(5); 

    try {
        copier(src1, src2, result);

        for (size_t i = 0; i < result.size(); ++i) {
            std::cout << result[i] << " ";
        }
        std::cout << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::list<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    std::cout << "Original list: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    deleter_of_odd(numbers);

    std::cout << "List after removing odd numbers: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
	return 0;
}