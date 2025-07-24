#include <iostream>
#include <cassert>
#include <optional>

// Operations----------------------
// Push, Pop, Peek, isEmpty, isFull
class Stack {
private:
	int top, cap;
	int* a;

public:
	Stack(int cap) {
		assert(cap > 0);

		this->cap = cap;
		top = -1;
		a = new int[cap];

		std::cout << "Stack initialized.\n";
	}

	~Stack() {
		delete[] a;
	}

	void Push(int val) {
		if (top >= cap - 1) {
			std::cout << "Stack's full\n";
			return;
		}

		a[++top] = val;
	}

	void Pop() {
		if (top < 0) {
			std::cout << "Stack's empty\n";
			return;
		}

		std::cout << a[top--] << "\n";
	}

	void Peek() {
		if (!isEmpty()) {
			std::cout << a[top] << "\n";
		}
		else {
			std::cout << "Stack's empty\n";
		}
	}

	bool isEmpty() const {
		return top == -1;
	}

	bool isFull() const {
		return top == cap - 1;
	}

	void Print() const {

		if (!isEmpty()) {
			std::cout << "THE STACK\n";
			for (int i = 0; i <= top; ++i) {
				std::cout << a[i] << "\n";
			}
		}
		else {
			std::cout << "Stack's empty\n";
		}
	}
};

int main() {
	
	std::cout << "WELCOME TO THE STACK\n";
	std::cout << "ENTER STACK's CAPACITY : ";

	int cap;
	std::cin >> cap;
	std::cout << "\n";

	Stack stack(cap);

	int choice = 0;
	bool running = true;

	while (running) {
		std::cout << "1. PUSH\n";
		std::cout << "2. POP\n";
		std::cout << "3. PEEK\n";
		std::cout << "4. EMPTY?\n";
		std::cout << "5. FULL?\n";
		std::cout << "666. QUIT?\n";

		std::cin >> choice;
		switch (choice) {
		case 1:
			int val;
			std::cout << "Value: ";
			std::cin >> val;
			stack.Push(val);
			break;
		case 2:
			stack.Pop();
			break;
		case 3:
			stack.Peek();
			break;
		case 4:
			if (stack.isEmpty()) {
				std::cout << "Stack's empty\n";
			}
			else {
				std::cout << "No\n";
			}
			break;
		case 5:
			if (stack.isFull()) {
				std::cout << "Stack's full\n";
			}
			else {
				std::cout << "No\n";
			}
			break;
		case 666:
			running = false;
			break;
		default:
			std::cout << "wrong choice.\n";
			break;
		}

		stack.Print();
	}

	std::cout << "b'bye\n";

	return 0;
}