#include<iostream>
#include<vector>
#include<algorithm>
#include <exception>
#include <set>


/*Написать шаблонную функцию, которая берет на вход два массива src1 и src2 шаблонного типа и их длины. Если длины массивов не равны,
функция бросает исключение типа std::exception. Если длины массивов равны, то функция записывает в src2 поэлементный максимум элементов обоих*/
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


/*Написать функцию, которая берет на вход std::vector<int> и возвращает количество различных чисел. Функция должна использовать std::set.*/
//2 задание
int unique_finder(std::vector<int> m) {

	std::set<int> unique(m.begin(), m.end());

	std::cout << "Number of unique elements: " << unique.size() << "\n";
	return unique.size();
}

/*3.Рекурсивно сгенерировать все автомобильные номера, в которых N английских букв и M цифр. */
//3 задание
void plate_generator(int n, int m, std::string current, std::vector<std::string>& result) {

	if (n == 0 && m == 0) {
		result.push_back(current);
		return;
	}

	if (n > 0) {
		for (char c = 'A'; c <= 'Z'; ++c) {
			std::cout << "Adding letter " << c << " with n=" << n << ", m=" << m << ", current=" << current << "\n";
			plate_generator(n - 1, m, current + c, result);
		}
	}

	if (m > 0) {
		for (char d = '0'; d <= '9'; ++d) {
			std::cout << "Adding digit " << d << " with n=" << n << ", m=" << m << ", current=" << current << "\n";
			plate_generator(n, m - 1, current + d, result);
		}
	}
}

std::vector<std::string> do_generation(int n, int m) {

	std::vector<std::string> result;

	plate_generator(n, m, "", result);

	return result;
}

/*Сгенерировать все возможные графы, в которых у каждой вершины k соседей. Задается число вершин в графе n и число к  */
// 4 задание гроб

int main() {

	int n = 1;
	int m = 2;

	std::vector<std::string> plates = do_generation(n, m);

	for (auto& plate : plates) {
		std::cout << plate << "\n";
	}

	int arr1[5] = { 1, 2 ,5 , 6, 9 };
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