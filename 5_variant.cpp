#include<iostream>
#include<vector>
#include<algorithm>
#include<exception>
#include <list>
#include<string>
#include <set>

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

int unique_strings(std::list<std::string> lst) {

	std::set<std::string> set_str;

	for (auto & str : lst) {
		set_str.insert(str);
	}
	return set_str.size();
}

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
	return 0;
}