#include <cassert>
using namespace std;

typedef char type;

class Stack {
private:
	// Tip: We can make this struct internally
	struct Node {
		type data { };
		Node* next { };
		Node(int data) :
				data(data) {
		}
	};

	Node *head { };

public:
	~Stack() {
		while (!isEmpty())
			pop();
	}
	void display() {
		for (Node* cur = head; cur; cur = cur->next)
			cout << cur->data << " ";
		cout << "\n";
	}

	void push(type value) {
		Node* item = new Node(value);
		item->next = head;
		head = item;
	}

	type pop() {
		assert(!isEmpty());
		int element = head->data;
		Node* temp = head;
		head = head->next;
		delete temp;
		return element;
	}

	type peek() {
		assert(!isEmpty());
		int element = head->data;
		return element;
	}

	int isEmpty() {
		return !head;
	}
};

int precedence(char op) {
    if (op == '+' || op == '-')
		return 1;
	if (op == '*' || op == '/')
		return 2;
    if(op == '^')
        return 3;
	return 0;
}

class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
    	Stack operators;
    	string postfix;
    
        s += '-';			// Whatever the lowest priority: force stack got empty
    	operators.push('#');	// Remove IsEmpty
    
    	for(int i{}; i < s.size(); ++i) {
    		if (isdigit(s[i]) || isalpha(s[i]))
    			postfix += s[i];
    		else if (s[i] == '(')
    			operators.push(s[i]);
    		else if (s[i] == ')') {
    			while (operators.peek() != '(')
    				postfix += operators.pop();
    			operators.pop();	// pop (
    		} else {
    			while (precedence(operators.peek()) >= precedence(s[i]))
    				postfix += operators.pop();
    			operators.push(s[i]);
    		}
    	}
    
    	return postfix;
    }
};
