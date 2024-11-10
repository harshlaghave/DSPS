#include <iostream>
using namespace std;

#define MAX 100

struct s
{
	string type;
	string size;
	int count;
};

s q[MAX];
int front = -1, rear = -1;

class Pizaa
{
  public:
	void insertAtRear(string type, string size, int count)
	{
		if (rear == MAX - 1)
		{
			cout << "Orders are full" << endl;
			return;
		}
		if (front == -1)
		{
			front = 0;
		}
		rear = rear + 1;
		q[rear].type = type;
		q[rear].size = size;
		q[rear].count = count;
	}

	void deleteFromFront()
	{
		if (front == -1)
		{
			cout << "All orders are delivered!" << endl;
			return;
		}

		cout << "-------------------------------------------------------------------------------" << endl;
		cout << "Type: " << q[front].type << "\t Size: " << q[front].size << "\t Number of pizza: " << q[front].count << endl;

		if (q[front].size == "S")
		{
			cout << "Total price of pizza is: " << q[front].count * 250 << endl;
		}
		else if (q[front].size == "M")
		{
			cout << "Total price of pizza is: " << q[front].count * 350 << endl;
		}
		else if (q[front].size == "L")
		{
			cout << "Total price of pizza is: " << q[front].count * 400 << endl;
		}
		else if (q[front].size == "XL")
		{
			cout << "Total price of pizza is: " << q[front].count * 800 << endl;
		}
		else
		{
			cout << "Invalid size entered!" << endl;
		}

		cout << "-------------------------------------------------------------------------------" << endl;

		if (front == rear)
		{
			front = -1;
			rear = -1;
		}
		else
		{
			front = front + 1;
		}
	}

	void displayDeque()
	{
		if (front == -1)
		{
			cout << "Oops! No Any Order!" << endl;
			return;
		}

		cout << "-------------------------------------------------------------------------------" << endl;
		for (int i = front; i <= rear; i++)
		{
			cout << "Type: " << q[i].type << "\t Size: " << q[i].size << "\t Number of pizza: " << q[i].count << endl;
		}
		cout << "-------------------------------------------------------------------------------" << endl;
		cout << endl;
	}
};

int main()
{
	Pizaa p;
	int ch, tc;
	string t, s;
	while (true)
	{
		cout << "Menu\n1. Order Pizza\n2. Serve Pizza\n3. Display (remaining)\n4. Exit...\nEnter your choice: ";
		cin >> ch;

		if (ch < 1 || ch > 4)
		{
			cout << "Invalid choice! Please try again." << endl;
			continue;
		}

		switch (ch)
		{
		case 1:
			cout << "\nEnter which type of pizza you want: ";
			cin >> t;
			cout << "\nEnter size of pizza (S, M, L, XL): ";
			cin >> s;
			cout << "\nEnter how many pizzas you want: ";
			cin >> tc;
			p.insertAtRear(t, s, tc);
			break;

		case 2:
			p.deleteFromFront();
			break;

		case 3:
			p.displayDeque();
			break;

		case 4:
			return 0;
		}
	}

	return 0;
}