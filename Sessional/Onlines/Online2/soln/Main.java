import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArrayList<LibraryBranch> branches = new ArrayList<>();

        // Read number of branches
        int numBranches = Integer.parseInt(args[0]);
        if (numBranches > 10) {
            System.out.println("Maximum 10 branches allowed.");
            return;
        }

        // Initialize branches and add books
        for (int i = 1; i <= numBranches; i++) {
            LibraryBranch branch = new LibraryBranch(i);
            System.out.println("Enter number of books for Branch " + i + ":");
            int numBooks = scanner.nextInt();
            if (numBooks > 20) {
                System.out.println("Maximum 20 books per branch allowed.");
                continue;
            }
            for (int j = 0; j < numBooks; j++) {
                System.out.println("Enter Book ID:");
                int bookId = scanner.nextInt();
                scanner.nextLine(); // Consume newline
                System.out.println("Enter Book Title:");
                String title = scanner.nextLine();
                System.out.println("Is the book available? (true/false):");
                boolean isAvailable = scanner.nextBoolean();
                Book book = new Book(bookId, title, isAvailable);
                branch.addBook(book);
            }
            branches.add(branch);
        }

        // Menu loop
        while (true) {
            System.out.println("\nMenu:");
            System.out.println("1. Borrow a Book");
            System.out.println("2. Return a Book");
            System.out.println("3. Display All Branch Info");
            System.out.println("4. Exit");
            System.out.println("Choose an option:");
            int choice = scanner.nextInt();

            if (choice == 4) {
                System.out.println("Exiting program...");
                break;
            }

            switch (choice) {
                case 1: // Borrow a Book
                    System.out.println("Enter Branch ID:");
                    int borrowBranchId = scanner.nextInt();
                    System.out.println("Enter Book ID:");
                    int borrowBookId = scanner.nextInt();
                    LibraryBranch borrowBranch = findBranch(branches, borrowBranchId);
                    if (borrowBranch == null) {
                        System.out.println("Invalid Branch ID.");
                        break;
                    }
                    Book borrowBook = borrowBranch.findBook(borrowBookId);
                    if (borrowBook == null) {
                        System.out.println("Book not found.");
                        break;
                    }
                    if (borrowBook.isAvailable()) {
                        borrowBook.setAvailable(false);
                        System.out.println("Book borrowed successfully.");
                    } else {
                        System.out.println("Book is not available.");
                    }
                    break;

                case 2: // Return a Book
                    System.out.println("Enter Branch ID:");
                    int returnBranchId = scanner.nextInt();
                    System.out.println("Enter Book ID:");
                    int returnBookId = scanner.nextInt();
                    LibraryBranch returnBranch = findBranch(branches, returnBranchId);
                    if (returnBranch == null) {
                        System.out.println("Invalid Branch ID.");
                        break;
                    }
                    Book returnBook = returnBranch.findBook(returnBookId);
                    if (returnBook == null) {
                        System.out.println("Book not found.");
                        break;
                    }
                    if (!returnBook.isAvailable()) {
                        returnBook.setAvailable(true);
                        System.out.println("Book returned successfully.");
                    } else {
                        System.out.println("Book is already available.");
                    }
                    break;

                case 3: // Display All Branch Info
                    for (LibraryBranch branch : branches) {
                        System.out.println("Branch ID: " + branch.getBranchId());
                        ArrayList<Book> books = branch.getBooks();
                        if (books.isEmpty()) {
                            System.out.println("No books available.");
                        } else {
                            for (Book book : books) {
                                System.out.println("Book ID: " + book.getBookId() + ", Title: " + book.getTitle() + ", Available: " + book.isAvailable());
                            }
                        }
                        System.out.println();
                    }
                    break;

                default:
                    System.out.println("Invalid option.");
            }
        }
        scanner.close();
    }

    private static LibraryBranch findBranch(ArrayList<LibraryBranch> branches, int branchId) {
        for (LibraryBranch branch : branches) {
            if (branch.getBranchId() == branchId) {
                return branch;
            }
        }
        return null;
    }
}