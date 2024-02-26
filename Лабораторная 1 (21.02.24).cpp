#include <iostream>
#include <locale.h>
#include <string>
#include <vector>

using namespace std;

class Book {
	string author;
	string name;
	double queue;
	double copies;
public:
	Book(string p_author, string p_name, double p_queue, double p_copies) {
		author = p_author;
		name = p_name;
		queue = p_queue;
		copies = p_copies;
	}

	void print() {
		cout << "Name of book: " << name << endl;
		cout << "Author: " << author << endl;
		cout << "Amount of copies: " << copies << endl;
		cout << "Amount of people who want to read it: " << queue << endl;
	}

	void sr_queue() {
		cout << "Average queue length: " << queue / copies;
	}

	double queues() {
		return queue;
	}

	string names() {
		return name;
	}
};

int main() {
	Book book1("Pushkin", "Evgeniy Onegin", 100, 700);
	Book book2("Bulgakov", "Master and Margarita", 200, 900);
	Book book3("Tolstoy", "Anna Karenina", 150, 600);
	vector<Book> books;
	double k = book1.queues();
	string m;
	books.push_back(book1);
	books.push_back(book2);
	books.push_back(book3);
	for (int i = 0; i < 2; ++i) {
		if (books[i + 1].queues() > k) {
			k = books[i + 1].queues();
		}
	}

	for (int i = 0; i < 3; ++i) {
		if (books[i].queues() == k) {
			m = books[i].names();
		}
	}

	cout << "The most popular book is " << m << endl << endl;
	for (int i = 0; i < 3; ++i) {
		books[i].print();
		cout << "Average queue length of this book: "; books[i].sr_queue();
		cout << endl << endl;
	}
	return 0;
}
