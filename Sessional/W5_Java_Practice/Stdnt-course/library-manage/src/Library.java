import java.util.Scanner;

public class Library {
    private Book[] books;
    private int bookCount;

    // Constructor
    public Library(int size) {
        books = new Book[size];
        bookCount = 0;
    }

    // Add a book to the library
    public void addBook(Book book) {
        if (bookCount < books.length) {
            books[bookCount] = book;
            bookCount++;
        }
    }

    // Check if ISBN already exists
    public boolean isIsbnUnique(String isbn) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i].getIsbn().equals(isbn)) {
                return false;
            }
        }
        return true;
    }

    // Search for a book by title
    public Book searchBook(String title) {
        for (Book book : books) {
            if (book != null && book.getTitle().equalsIgnoreCase(title)) {
                return book;
            }
        }
        return null;
    }

    // Display book details
    public void displayBookDetails(Book book) {
        if (book == null) {
            System.out.println("Book not found.");
            return;
        }
        System.out.println("\nBook details:");
        System.out.println("- Title: " + book.getTitle());
        System.out.println("- Author: " + book.getAuthor());
        System.out.println("- ISBN: " + book.getIsbn());
        System.out.println("- Available copies: " + book.getAvailableCopies());
        if (book.getAvailableCopies() == 0) {
            System.out.println("Status: All copies are currently borrowed.");
        }
    }
}