#include <iostream>
#include<string>
using namespace std;


template <typename T>
int linearSearch(T arr[], int size, T key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

template <typename T>
int binarySearch(T arr[], int size, T key) {
    int start = 0;
    int end = size - 1;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] < key) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return -1;
}



class LibraryItem {
public:
    virtual void display() = 0;   
};


class Book : public LibraryItem {
private:
    string title;
    string author;
    int pages;

public:
    Book() {
        title = "";
        author = "";
        pages = 0;
    }

    Book(string t, string a, int p) {
        title = t;
        author = a;
        pages = p;
    }

    string getTitle() {
        return title;
    }

    int getPages() {
        return pages;
    }

    void display() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Pages: " << pages << endl;
    }
};


class Newspaper : public LibraryItem {
private:
    string name;
    string date;
    string edition;

public:
    Newspaper() {
        name = "";
        date = "";
        edition = "";
    }

    Newspaper(string n, string d, string e) {
        name = n;
        date = d;
        edition = e;
    }

    string getName() {
        return name;
    }

    string getEdition() {
        return edition;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Date: " << date << endl;
        cout << "Edition: " << edition << endl;
    }
};



class Library {
private:
    Book books[10];
    Newspaper newspapers[10];
    int bookCount;
    int newspaperCount;

public:
    Library() {
        bookCount = 0;
        newspaperCount = 0;
    }

    void addBook(Book b) {
        books[bookCount] = b;
        bookCount++;
    }

    void addNewspaper(Newspaper n) {
        newspapers[newspaperCount] = n;
        newspaperCount++;
    }

    void displayCollection() {
        cout << "Books:\n";
        for (int i = 0; i < bookCount; i++) {
            books[i].display();
            cout << endl;
        }

        cout << "Newspapers:\n";
        for (int i = 0; i < newspaperCount; i++) {
            newspapers[i].display();
            cout << endl;
        }
    }

    void sortBooksByPages() {
        for (int i = 0; i < bookCount - 1; i++) {
            for (int j = 0; j < bookCount - 1 - i; j++) {
                if (books[j].getPages() > books[j + 1].getPages()) {
                    Book temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
            }
        }
    }
    void sortNewspapersByEdition() {
        for (int i = 0; i < newspaperCount - 1; i++) {
            for (int j = 0; j < newspaperCount - 1 - i; j++) {
                if (newspapers[j].getEdition() > newspapers[j + 1].getEdition()) {
                    Newspaper temp = newspapers[j];
                    newspapers[j] = newspapers[j + 1];
                    newspapers[j + 1] = temp;
                }
            }
        }
    }
    Book* searchBookByTitle(string key) {
        string titles[10];
        for (int i = 0; i < bookCount; i++)
        {
            titles[i] = books[i].getTitle();
        }
        int index = linearSearch(titles, bookCount, key);
        if (index != -1) {
            return &books[index];
        }
    }
  
    Newspaper* searchNewspaperByName(string key) {
        string names[10];
        for (int i = 0; i < newspaperCount; i++) 
        { 
            names[i] = newspapers[i].getName();
        } 
        int index = linearSearch(names, newspaperCount, key); 
        if (index != -1) { 
            return &newspapers[index];
        }
    }
};

    

int main() {
    // Create book objects 
    Book book1("The Catcher in the Rye", "J.D. Salinger", 277);
    Book book2("To Kill a Mockingbird", "Harper Lee", 324);

    // Create newspaper objects 
    Newspaper newspaper1("Washington Post", "2024-10-13", "Morning Edition");
    Newspaper newspaper2("The Times", "2024-10-12", "Weekend Edition");

    // Create a library object 
    Library library;

    // Add books and newspapers to the library 
    library.addBook(book1);
    library.addBook(book2);
    library.addNewspaper(newspaper1);
    library.addNewspaper(newspaper2);

    // Display the entire collection 
    cout << "Before Sorting:\n";
    library.displayCollection();

    // Sort books by pages and newspapers by edition 
    library.sortBooksByPages();
    library.sortNewspapersByEdition();

    cout << "\nAfter Sorting:\n";
    library.displayCollection();

    // Search for a book by title 
    Book* foundBook = library.searchBookByTitle("The Catcher in the Rye");
    if (foundBook) {
        cout << "\nFound Book:\n";
        foundBook->display();
    }
    else {
        cout << "\nBook not found.\n";
    }

    // Search for a newspaper by name 
    Newspaper* foundNewspaper = library.searchNewspaperByName("The Times");
    if (foundNewspaper) {
        cout << "\nFound Newspaper:\n";
        foundNewspaper->display();
    }
    else {
        cout << "\nNewspaper not found.\n";
    }

    return 0;
}