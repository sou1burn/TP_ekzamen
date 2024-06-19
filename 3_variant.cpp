#include<iostream>
#include<vector>
#include<algorithm>
#include<exception>

//1 задание
void before_after(std::vector<int>& nums, int before, int after) {

	for (int i = 0; i < nums.size(); ++i) {
		if (nums[i] == before) {
			nums.insert(nums.begin() + i + 1, after);
			++i;
		}
	}
}

//2 задание
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
class Node {
public:
	Node* left;
	Node* right;
	int value;

	Node(int value) : value(value), left(nullptr), right(nullptr){}
};

//3 задание
int leaves_counter(Node* root) {
	if (root == nullptr) {
		return 0;
	}

	if (root->left == nullptr && root->right == nullptr) {
		return 1;
	}

	return leaves_counter(root->left) + leaves_counter(root->right);
}

//4 задание

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

	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->right = new Node(6);

	int leafCount = leaves_counter(root);
	std::cout << "Number of leaves in the tree: " << leafCount << std::endl;

	// Освобождаем память (удаление всех узлов дерева)
	delete root->right->right;
	delete root->left->right;
	delete root->left->left;
	delete root->right;
	delete root->left;
	delete root;
	return 0;
}