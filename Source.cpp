#include <iostream>
using namespace std;

template<typename T>
struct stack
{
	void push(T data);
	void pop();
	int getSize();
	void showLastElement();

	struct Node
	{
		Node(T data)
		{
			this->data = data;
		}
		Node* pnext = nullptr;
		T data;
	};
	Node* head = nullptr;
	int size = 0;
};

template<typename T>
void stack<T>::push(T data)
{
	if (head == nullptr)
		head = new Node(data);
	else
	{
		Node* temp = head;
		head = new Node(data);
		head->pnext = temp;
	}
	++size;
}

template<typename T>
void stack<T>::pop()
{
	if (head != nullptr)
	{
		Node* temp = head;
		head = temp->pnext;
		delete temp;
		--size;
	}
	else
		cout << "���� ����!" << endl;
}

template<typename T>
int stack<T>::getSize()
{
	return size;
}

template<typename T>
void stack<T>::showLastElement()
{
	if (head != nullptr)
		cout << head->data << endl;
	else
		cout << "������ ����!" << endl;
}

int main()
{
	system("chcp 1251>>null");
	stack<int> s1;
	int n;
	int a;
	cout << "������� ���������� ���������: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "������� " << i+1 << " �������: ";
		cin >> a;
		s1.push(a);
	}
	cout << "������ �������: ";
	cout << s1.getSize() << endl;
	cout << "��������� �������: ";
	s1.showLastElement();
	cout << endl;
	s1.pop();
	cout << "������ �������: ";
	cout << s1.getSize() << endl;
	cout << "��������� �������: ";
	s1.showLastElement();
	return 0;
}