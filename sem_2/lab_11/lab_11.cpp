#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct elem
{
	string key;
	elem *prev;
	elem *next;
};
elem* delete_element(string del_key, int n, elem* head)
{
	elem* c;
	elem* p;
	c = head->next;
	if (head->key == del_key)
	{
		head = head->next;
	}
	if (head->key != del_key)
	{
		for (int i = 0; i < n - 1; i++)
		{
			if (c->key == del_key)
			{
				p = c->prev;
				p->next = c->next;
				c = c->next;
				c->prev = p;
			}
			else
			{
				c = c->next;
			}
		}
	}
	cout << "list after deleting the element: " << endl;
	cout << head->key << endl;
	c = head->next;
	for (int i = 0; i < n - 2; i++)
	{
		cout << c->key << endl;
		c = c->next;
	}
	return head;
}
elem* add_elem(int n, int k, elem* head)
{
	elem* c;
	elem* p;
	for (int i = 0; i < k; i++)
	{
		c = head;
		p = new elem;

		p->next = c;
		cout << "enter the key of the new element: ";
		cin >> p->key;
		c->prev = p;
		head = p;
	}
	cout << "list after adding new elements: " << endl;
	cout << head->key << endl;
	c = head->next;
	for (int i = 0; i < n + k - 2; i++)
	{
		cout << c->key << endl;
		c = c->next;
	}
	return head;
}
elem* create_and_print_list(int n)
{
	elem* p;
	elem* c;
	elem* head;
	head = new elem;
	cout << "enter head key: ";
	cin >> head->key;
	head->prev = nullptr;
	c = new elem;
	c->prev = head;
	c->next = nullptr;
	cout << "enter key: ";
	cin >> c->key;
	head->next = c;
	p = head;
	for (int i = 0; i < n - 1; i++)
	{
		c = new elem;
		c->prev = p;
		c->next = nullptr;
		cout << "enter key: ";
		cin >> c->key;
		p->next = c;
		p = c;
	}
	cout << head->key << endl;
	c = head->next;
	for (int i = 0; i < n - 1; i++)
	{
		cout << c->key << endl;
		c = c->next;
	}
	return head;
}
void write_to_file(int n, int k, elem* head)
{
	elem* c;
	ofstream f("f11.txt");
	f << head->key << endl;
	c = head->next;
	for (int i = 0; i < n + k - 2; i++)
	{
		f << c->key << endl;
		c = c->next;
	}
	f.close();
}
void delete_list(int n, int k, elem* head)
{
	elem* c = head->next;
	elem* r = c->next;
	for (int i = 0; i < n + k - 2; i++)
	{
		c = nullptr;
		c = r;
		if (r->next != nullptr)
		{
			r = r->next;
		}
	}
	head = nullptr;
}
elem* restore_list(int n, int k)
{
	string line;
	elem* c;
	elem* p;
	elem* head = new elem;
	ifstream f1("f11.txt");
	if (!f1)
	{
		cout << "file is not opened";
	}
	getline(f1, line);
	head->key = line;
	head->prev = nullptr;
	p = head;
	while (getline(f1, line))
	{
		c = new elem;
		c->key = line;
		c->prev = p;
		p->next = c;
		c->next = nullptr;
		p = c;
	}
	cout << "list after restoring: " << endl;
	cout << head->key << endl;
	c = head->next;
	for (int i = 0; i < n + k - 2; i++)
	{
		cout << c->key << endl;
		c = c->next;
	}
	f1.close();
	return head;
}
int main()
{
	int k;
	int n = 5;
	elem* head = create_and_print_list(n);
	string del_key;
	cout << "delete element with key: ";
	cin >> del_key;
	head = delete_element(del_key, n, head);
	cout << "enter number of elements to add: ";
	cin >> k;
	head = add_elem(n, k, head);
	write_to_file(n, k, head);
	cout << "deleting list..." << endl;
	delete_list(n, k, head);
	restore_list(n, k);
}