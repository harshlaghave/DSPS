#include <iostream>

using namespace std;

#define MAX 100 // Maximum size of the stack

// Simulating a stack using an array
class Stack
{
	char arr[MAX];
	int top;

  public:
	Stack()
	{
		top = -1;
	}

	// Push element onto the stack
	void push(char ch)
	{
		if (top == MAX - 1)
		{
			cout << "Stack Overflow\n";
			return;
		}
		arr[++top] = ch;
	}

	// Pop element from the stack
	char pop()
	{
		if (top == -1)
		{
			cout << "Stack Underflow\n";
			return -1;
		}
		return arr[top--];
	}

	// Peek at the top element of the stack
	char peek()
	{
		if (top == -1)
		{
			return -1;
		}
		return arr[top];
	}

	// Check if the stack is empty
	bool isEmpty()
	{
		return top == -1;
	}
};

// Function to return precedence of operators
int precedence(char op)
{
	if (op == '+' || op == '-')
	{
		return 1;
	}
	else if (op == '*' || op == '/')
	{
		return 2;
	}
	else if (op == '^')
	{
		return 3;
	}
	return 0;
}

// Function to check if the character is an operator
bool isOperator(char ch)
{
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Function to check if the character is an alphabet (operand)
bool isAlphabet(char ch)
{
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

// Function to check if the character is a digit (operand)
bool isDigit(char ch)
{
	return (ch >= '0' && ch <= '9');
}

// Function to convert infix expression to postfix
string infixToPostfix(string infix)
{
	Stack s;
	string postfix = "";

	for (int i = 0; i < infix.length(); i++)
	{
		char ch = infix[i];

		// If the character is an operand (alphabet or digit), add it to the output
		if (isAlphabet(ch) || isDigit(ch))
		{
			postfix += ch;
		}
		// If the character is '(', push it to the stack
		else if (ch == '(')
		{
			s.push(ch);
		}
		// If the character is ')', pop and add to output until '(' is found
		else if (ch == ')')
		{
			while (!s.isEmpty() && s.peek() != '(')
			{
				postfix += s.pop();
			}
			s.pop(); // Remove the '(' from stack
		}
		// If the character is an operator
		else if (isOperator(ch))
		{
			while (!s.isEmpty() && precedence(s.peek()) >= precedence(ch))
			{
				postfix += s.pop();
			}
			s.push(ch);
		}
	}

	// Pop all the remaining operators from the stack
	while (!s.isEmpty())
	{
		postfix += s.pop();
	}

	return postfix;
}

int main()
{
	string infix;
	cout << "Enter an infix expression: ";
	cin >> infix;

	string postfix = infixToPostfix(infix);
	cout << "Postfix expression: " << postfix << endl;

	return 0;
}