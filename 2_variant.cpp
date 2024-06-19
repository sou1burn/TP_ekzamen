#include<iostream>
#include<vector>
#include<algorithm>
#include <exception>
#include <set>
#include<map>

class Node {
public:
	Node* left;
	Node* right;
	int val;

	Node(int val) : left(nullptr), right(nullptr), val(0) {}
};

// 1 задание
template <typename T>
void divisioner(T* src1, T* src2, size_t len) {
	for (size_t i = 0; i < len; ++i) {
		if (src2[i] == 0) {
			throw std::exception("Division by zero");
		}
		std::cout << src1[i] / src2[i] << " ";
	}

}
// 2 задание
void frequency_finder(std::vector<std::string> str) {

	std::map<std::string, int> mp;
	for (std::string i : str) {
		mp[i]++;
	}

	int max = 0;
	for (auto& pair : mp) {
		max = std::max(max, pair.second);
	}
	std::cout << "\nMost frequent string: ";
	for (const auto& pair : mp) {
		if (pair.second == max) {
			std::cout << pair.first << std::endl;
		}
	}

}

// 3 задание
int count_nodes(Node* root) {
	if (root == nullptr) {
		return 0;
	}

	int lefts = count_nodes(root->left);
	int rights = count_nodes(root->right);

	return lefts + rights + 1;

}

// 4 задание

void dfs(std::vector<std::vector<int>> graph, std::vector<bool>& visited, int start) {

	visited[start] = true;
	for (int i = 0; i < graph[start].size(); ++i) {
		if (graph[start][i] == 1 && !visited[i]) {
			dfs(graph, visited, i);
		}
	}
}

bool is_connected(int vertices, std::vector<std::vector<int>> graph) {

	std::vector<bool> visited(vertices, false);

	dfs(graph, visited, 0);

	for (int i = 0; i < vertices; ++i) {
		if (!visited[i]) {
			return false;
		}
	}
	return true;
}

bool has_cycle(std::vector<std::vector<int>> graph, std::vector<bool>& visited, int v, int parent) {

	visited[v] = true;

	for (int i = 0; i < graph[v].size(); ++i) {
		if (graph[v][i] == 1) {
			if (!visited[i]) {
				if (has_cycle(graph, visited, i, v)) {
					return true;
				}
			}
			else if (i != parent){
				return true;
			}
		}
	}

	return false;
}

bool is_tree(int edges, int vertices, std::vector<std::vector<int>> graph) {

	if (edges != vertices - 1) {
		return false;
	}

	std::vector <bool> visited(vertices, false);
	if (has_cycle(graph, visited, 0, -1)) {
		return false;
	}

	return is_connected(vertices, graph);
	
}


int main() {

	std::vector<int> arr1 = { 1, 0, 4, 0, 5, 55 };
	std::vector<int> arr2 = { 1, 3, 23, 43, 43, 1 };
	try {
		divisioner(arr1.data(), arr2.data(), arr1.size());
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::vector<std::string> arr = { "apple", "banana", "apple", "orange", "banana", "apple" };
	frequency_finder(arr);


	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	// Подсчитываем количество вершин в дереве
	int totalNodes = count_nodes(root);
	std::cout << "Total number of nodes in the tree: " << totalNodes << std::endl;
	delete root->right->right;
	delete root->right->left;
	delete root->right;
	delete root->left->right;
	delete root->left->left;
	delete root->left;
	delete root;

	return 0;
}