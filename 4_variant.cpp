#include<iostream>
#include<vector>
#include<algorithm>
#include<exception>
#include<list>


//1 �������
/*1.�������� ��������� ������� �� ���� ����� ��� ������� ���������� ���� src1, src2 � result.
������� �������� � ������ result ��� ������ src, ������� ����� ������� �����, ���� ����� ������� result �� �������,
������� ������� ���������� std:: exception */
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

/*������ ������� �������:
template <typename T>
void copy_array(const T* src1, size_t len1, const T* src2, size_t len2, T* result, size_t len_result) {
    const T* larger_src = (len1 >= len2) ? src1 : src2;
    size_t larger_len = (len1 >= len2) ? len1 : len2;

    if (len_result < larger_len) {
        throw std::runtime_error("Length of result array is not sufficient");
    }

    for (size_t i = 0; i < larger_len; ++i) {
        result[i] = larger_src[i];
    }
}*/

/*2.�������� �������, ������� ����� �� ���� std::list<int>. ������� ������� ��� �������� ����� �� ������.*/
//2 �������
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

/*�������� �������, ������� ���������� ���������� ��� ���������� ����� N �� ���������, ��� ������ ��������� �� ��������� K.*/
//3 �������
void find_combs(int n, int k, std::vector<int>& current, std::vector<std::vector<int>>& result) {

    if (n == 0) {
        result.push_back(current);
        return;
    }

    for (int i = 1; i <= k; ++i) {
        if (i <= n) {
            current.push_back(i);
            find_combs(n - i, k, current, result);
            current.pop_back();
        }
    }
}

std::vector<std::vector<int>> generate_combs(int n, int k) {

    std::vector<std::vector<int>> result;
    std::vector<int> current;
    find_combs(n, k, current, result);

    return result;
}

/*�������� ���������, ������� ���������� �������� �� ����� ������ ������ ����� ��� ������ ������ (����� dfs)*/
//4 ������� ����

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

    int N = 5;  // �������� �����
    int K = 3;  // ������������ �������� ����������

    std::vector<std::vector<int>> combinations = generate_combs(N, K);

    std::cout << "All combinations of " << N << " with each term not exceeding " << K << ":" << std::endl;
    for (const auto& combination : combinations) {
        for (int num : combination) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
	return 0;
}