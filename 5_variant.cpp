#include<iostream>
#include<vector>
#include<algorithm>
#include<exception>
#include <list>
#include<string>
#include <set>

/*1.Дана шаблонная функция T f(const &T a), которая может бросить исключение типа std::exception. Написать шаблонную функцию,
которая берет на вход массив src и его длину и заменяет все элементы src[I] на f(src[I]). Если f бросила исключение на каком-то элементе,
заменить его на 0*/
// 1 задание
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
		try{
			src1[i] = f(src1[i]);
			std::cout << src1[i] << " ";
		}
		catch (std::exception){
			src1[i] = 0;
		}
	}
}

/*2.Написать функцию, которая берет на вход std::list<string> и возвращает количество различных строк. Функция должна использовать std::set.*/
// 2 задание
int unique_strings(std::list<std::string> lst) {

	std::set<std::string> set_str;

	for (auto & str : lst) {
		set_str.insert(str);
	}
	return set_str.size();
}

/*3.Написать программу, которая выводит все идентификаторы вершин дерева, у которых ровно три сына.
Вершина дерева хранится как class Node{int val; vector<Node> childs}*/
// 3 задание
class Node {
public:
	int val;
	std::vector<Node*> childs;

	Node(int val) : val(val) {}
};


void find_nodes_with_3childs(Node* root) {
	
	if (root == nullptr) {
		return;
	}

	if (root->childs.size() == 3) {
		std::cout << "Node with 3 childs is : " << root->val <<"\n";
	}

	for (Node* child : root->childs) {
		find_nodes_with_3childs(child);
	}
}

/*4.Дан лабиринт в виде двумерного массива: 0 - проход, 1 - стена, 2 - выход (всегда есть). Написать рекурсивную функцию,
которая получает на вход координаты старта и строит в лабиринте путь (заполняет цифрой 3) путь от старта до выхода.*/
// 4 задание
bool pathfinder(std::vector<std::vector<int>>& net, int x, int y) {

	if (x < 0 || x >= net.size() || y < 0 || y >= net[0].size()) {
		return false;
	}

	if (net[x][y] == 2) {
		return true;
	}

	if (net[x][y] != 0) {
		return false;
	}

	net[x][y] = 3;

	if (pathfinder(net, x + 1, y) || pathfinder(net, x - 1, y) || pathfinder(net, x, y + 1) || pathfinder(net, x, y - 1)) {
		return true;
	}

	net[x][y] = 0;
	return false;
}

void follow_pathfinder(std::vector<std::vector<int>>& net, int x, int y) {

	if (!pathfinder(net, x, y)) {
		std::cout << "There is no path, no hope..." << "\n";
	}
	else {
		std::cout << "\n";
		for (const auto& row : net) {
			for (int cell : row) {
				std::cout << cell << " ";
			}
			std::cout << "\n";
		}
	}
}

int main() {

	int src[] = { 1, 2, 3, 4, 5 };
	size_t length = sizeof(src) / sizeof(src[0]);
	exchanger(src, length);


	Node* root = new Node(1);
	root->childs.push_back(new Node(2));
	root->childs.push_back(new Node(3));
	root->childs.push_back(new Node(4));

	root->childs[0]->childs.push_back(new Node(5));
	root->childs[0]->childs.push_back(new Node(6));
	root->childs[0]->childs.push_back(new Node(7));

	root->childs[1]->childs.push_back(new Node(8));
	root->childs[1]->childs.push_back(new Node(9));
	root->childs[1]->childs.push_back(new Node(10));

	root->childs[2]->childs.push_back(new Node(11));

	find_nodes_with_3childs(root);

	delete root->childs[0]->childs[0];
	delete root->childs[0]->childs[1];
	delete root->childs[0]->childs[2];
	delete root->childs[0];

	delete root->childs[1]->childs[0];
	delete root->childs[1]->childs[1];
	delete root->childs[1];

	delete root->childs[2]->childs[0];
	delete root->childs[2];

	delete root;


	std::vector<std::vector<int>> maze = {
		{0, 1, 0, 0, 0},
		{0, 1, 0, 1, 0},
		{0, 0, 0, 1, 0},
		{0, 1, 1, 1, 0},
		{0, 0, 0, 2, 0}
	};

	int startX = 0, startY = 0;
	follow_pathfinder(maze, startX, startY);

	return 0;
}