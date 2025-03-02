#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
using namespace std;
class Library {
public:
    int Id, price, pages, edition;
    char name[100];
	char author[100];
	char student[100];
    bool isBorrowed;
    Library() {
	 isBorrowed = false;
	 strcpy(student, "");
	  }
};
vector<Library> books;
void saveToFile() {
    ofstream file("library_data.txt", ios::out | ios::trunc);
    for (Library &b : books) {
        file << b.Id << " " << b.name << " " << b.author << " "<< b.edition << " " << b.pages << " " << b.price << " "
             << b.isBorrowed << " " << b.student << endl;
    }
    file.close();
}
void loadFromFile() {
    ifstream file("library_data.txt");
    Library b;
    while (file >> b.Id >> b.name >> b.author >> b.edition >> b.pages >> b.price >> b.isBorrowed >> b.student) {
        books.push_back(b);
    }
    file.close();
}
void addBook() {
    Library b;
    cout << "Enter Book Id: ";
	 cin >> b.Id;
    cin.ignore();
    cout << "Enter Book Name: "; 
	cin.getline(b.name, 100);
    cout << "Enter Author: "; 
	cin.getline(b.author, 100);
    cout << "Enter Edition: "; 
	cin >> b.edition;
    cout << "Enter Pages: ";
	 cin >> b.pages;
    cout << "Enter Price: "; 
	cin >> b.price;
    books.push_back(b);
    saveToFile();
    cout << "Book added successfully!\n";
}
void displayBooks() {
    if (books.empty()) { 
	cout << "No books available!\n"; 
	return; 
	}
    for (Library &b : books) {
        cout << "\nId: " << b.Id << "\nName: " << b.name << "\nAuthor: " << b.author << "\nEdition: "
             << b.edition << "\nPages: " << b.pages << "\nPrice: " << b.price;
        if (b.isBorrowed) cout << "\nBorrowed by: " << b.student;
        cout << "\n------------------\n";
    }
}

void searchBook() {
    int id;
	 cout << "Enter Book ID to search: ";
	  cin >> id;
    for (Library &b : books) {
        if (b.Id == id) {
            cout << "Book Found: " << b.name << " by " << b.author << "\n";
            return;
        }
    }
    cout << "Book not found!\n";
}
void borrowBook() {
    int id; 
	cout << "Enter Book ID to borrow: ";
	 cin >> id;
    for (Library &b : books) {
        if (b.Id == id && !b.isBorrowed) {
            cout << "Enter Student Name: ";
            cin.ignore(); 
			cin.getline(b.student, 100);
            b.isBorrowed = true;
            saveToFile();
            cout << "Book borrowed successfully!\n";
            return;
        }
    }
    cout << "Book is already borrowed or not found!\n";
}
void returnBook() {
    int id; 
	cout << "Enter Book ID to return: ";
	 cin >> id;
    for (Library &b : books) {
        if (b.Id == id && b.isBorrowed) {
            b.isBorrowed = false;
            strcpy(b.student, "");
            saveToFile();
            cout << "Book returned successfully!\n";
            return;
        }
    }
    cout << "Book not found or not borrowed!\n";
}
void deleteBook() {
    int id;
	 cout << "Enter Book ID to delete: "; 
	 cin >> id;
    for (auto it = books.begin(); 
	it != books.end(); ++it) {
        if (it->Id == id) {
            books.erase(it);
            saveToFile();
            cout << "Book deleted successfully!\n";
            return;
        }
    }
    cout << "Book not found!\n";
}
void adminMenu() {
    int choice;
    do {
        cout << "\n1. Add Book\n2. Display Books\n3. Search Book\n4. Delete Book\n5. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
			 addBook();
			  break;
            case 2:
			 displayBooks();
			  break;
            case 3:
			 searchBook(); 
			 break;
            case 4: 
			deleteBook(); 
			break;
            case 5: 
			return;
            default:
			 cout << "Invalid choice!\n";
        }
    } while (true);
}
void studentMenu() {
    int choice;
    do {
        cout << "\n1. Display Books\n2. Borrow Book\n3. Return Book\n4. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: 
			displayBooks(); 
			break;
            case 2:
			 borrowBook(); 
			 break;
            case 3: 
			returnBook();
			 break;
            case 4:
			 return;
            default: 
			cout << "Invalid choice!\n";
        }
    } while (true);
}

int main() {
    loadFromFile();
    int role;
    do {
    	cout<<"Choose one of the following. "<<endl;
        cout << "\n1. Admin\n2. Student\n3. Exit\nEnter role: ";
        cin >> role;
        switch (role) {
            case 1: 
			adminMenu(); 
			break;
            case 2:
			 studentMenu(); 
			 break;
            case 3: 
			return 0;
            default: 
			cout << "Invalid choice!\n";
        }
    } while (true);
}
