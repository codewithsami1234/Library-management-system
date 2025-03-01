# Library-management-system
This is a simple Library Management System implemented in C++. It allows administrators to manage books and students to borrow and return books. The system uses file handling to ensure data persistence.

Features

Admin Features:

Add new books to the library

View all books

Search for books by ID

Delete books from the library

Student Features:

View available books

Borrow books

Return borrowed books

File Handling

The system stores book data in library_data.txt. Any changes made (adding, deleting, borrowing, or returning books) are automatically saved.

Installation & Usage

Prerequisites

A C++ compiler (e.g., g++ or Dev C++)

Selecting User Role

Admin: Manages library books.

Student: Borrows and returns books.

Exit: Closes the application.

Admin Operations

Add Book: Enter book details (ID, name, author, edition, pages, and price).

Display Books: Lists all books.

Search Book: Find a book using its ID.

Delete Book: Removes a book from the system.

Student Operations

View Books: Lists available books.

Borrow Book: Enter an ID to borrow a book.

Return Book: Enter an ID to return a borrowed book.
