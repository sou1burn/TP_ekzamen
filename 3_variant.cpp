#include<iostream>
#include<vector>
#include<algorithm>
#include<exception>

/*Написать функцию, которая берет на вход std::vector<int>, int before, int after и вставляет после каждого числа before число after.*/
//1 задание
void before_after(std::vector<int>& nums, int before, int after) {

	for (int i = 0; i < nums.size(); ++i) {

		if (nums[i] == before) {
			nums.insert(nums.begin() + i + 1, after);
		}
	}
}

/*2.Написать шаблонную функцию, которая берет на вход три шаблонных массива src1, src2, result и их длины.
Функция копирует в массив result сначала массив  src1, а за ним массив  srс2. Если длины массива не хватает,
функция бросает исключение типа std::exception*/
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

/*3.Дано дерево class Node{Node*left, Node *right, int value} Написать программу подсчета числа листьев в дереве */
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

/*4.Сгенерировать все варианты полных (всегда два потомка у вершины) двоичных деревьев из n вершин*/
//4 задание
std::vector<Node*> generate_trees(int n) {
	if (n % 2 == 0) return {};

	if (n % 2 == 1) return { new Node(0) };

	std::vector<Node*> result;

	for (int left_size = 1; left_size < n; left_size += 2) {

		int right_size = n - 1 - left_size;

		std::vector<Node*> left_trees = generate_trees(left_size);
		std::vector<Node*> right_trees = generate_trees(right_size);

		for (Node* left : left_trees) {
			for (Node* right : right_trees) {

				Node* root = new Node(0);
				root->left = left;
				root->right = right;
				result.push_back(root);
			}
		}
	}

	return result;
}

void print_tree(Node* root, std::string indent = "") {

	if (root == nullptr) {
		return;
	}

	std::cout << indent << root->value << "\n";
	print_tree(root->left, indent + " ");
	print_tree(root->right, indent + " ");

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
	const size_t len2 = 4 ;
	const size_t result_len = len1 + len2;

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


	delete root->right->right;
	delete root->left->right;
	delete root->left->left;
	delete root->right;
	delete root->left;
	delete root;

	int n = 7; 
	std::vector<Node*> trees = generate_trees(n);

	std::cout << "Number of trees: " << trees.size() << "\n";
	for (Node* tree : trees) {
		print_tree(tree);
		std::cout << "\n";
	}

	return 0;
}