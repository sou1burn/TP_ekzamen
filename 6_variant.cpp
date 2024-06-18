#include<iostream>
#include<vector>
#include<algorithm>
#include<exception>
#include <list>
#include <map>

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
		try {
			src1[i] = f(src1[i]);
			std::cout << src1[i] << " ";
		}
		catch (std::exception) {
			throw (std::runtime_error("RUNTIME ERROR"));
		}
	}
}

int most_frequent(std::list<int> m) {
	std::map<int, int> mp;
	for (int i : m) {
		mp[i]++;
	}
	int max_freq = 0;

	int most_frequent = m.front();
	for (auto& pair : mp) {
		if (pair.second > max_freq) {
			max_freq = pair.second;
			most_frequent = pair.first;
		}
	}
	return most_frequent;
}

bool find_sum(std::vector<int> nums, int curr_id, int curr_sum, int sum) {

    if (curr_id == nums.size()) {
        return curr_sum == sum;
    }

    if (find_sum(nums, curr_id + 1, curr_sum + nums[curr_id], sum)) {
        return true;
    }

    if (find_sum(nums, curr_id + 1, curr_sum - nums[curr_id], sum)) {
        return true;
    }

    return false;
}

bool can_find_sum(int s, std::vector<int> nums) {

    return find_sum(nums, 0, 0, s);
}


struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

template <typename T>
class Stack {
public:
    Stack(size_t capacity) : top(-1), capacity(capacity) {
        stack = new T[capacity];
    }

    ~Stack() {
        delete[] stack;
    }

    void push(T value) {
        if (top < capacity - 1) {
            stack[++top] = value;
        }
        else {
            std::cerr << "\nStack overflow" << std::endl;
        }
    }

    T pop() {
        if (top >= 0) {
            return stack[top--];
        }
        else {
            std::cerr << "\nStack underflow" << std::endl;
            return nullptr; 
        }
    }

    bool isEmpty() {
        return top == -1;
    }

private:
    T* stack;
    int top;
    size_t capacity;
};


void printTreeNodes(Node* root) {

    if (root == nullptr) {
        return;
    }

    Stack<Node*> stack(100); 

    stack.push(root);

    while (!stack.isEmpty()) {
        
        Node* current = stack.pop();
        std::cout << current->value << " ";

        
        if (current->right != nullptr) {
            stack.push(current->right);
        }

        
        if (current->left != nullptr) {
            stack.push(current->left);
        }
    }
}

int main() {
	try {
		int src[] = { 1, 2, 0, 4, 5 };
		size_t len = sizeof(src) / sizeof(src[0]);

		exchanger(src, len);

		for (size_t i = 0; i < len; ++i) {
			std::cout << src[i] << " ";
		}
		std::cout << std::endl;
	}
    catch (const std::runtime_error& e) {
	std::cout << "Caught runtime_error: " << e.what() << std::endl;
}
	std::list<int> nums = { 1, 2, 2, 3, 3, 3, 3 ,3 , 4, 4, 4, 4 };
	std:: cout << "Most frequent: "<< most_frequent(nums);

    std::vector<int> numbers = { 1, 2, 3, 4, 5 };
    int target_sum = 15;

    if (can_find_sum(target_sum, numbers)) {
        std::cout << "\nIt is possible to form the sum " << target_sum << " using + and - between the numbers." << std::endl;
    }
    else {
        std::cout << "\nIt is not possible to form the sum " << target_sum << " using + and - between the numbers." << std::endl;
    }

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);


    printTreeNodes(root);

    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

	return 0;
}