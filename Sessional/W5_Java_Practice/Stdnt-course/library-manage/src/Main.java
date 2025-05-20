import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Check if command line argument is provided
        if (args.length != 1) {
            System.out.println("Please provide the number of books as a command line argument.");
            return;
        }

        // Parse number of books
        int numBooks;
        try {
            numBooks = Integer.parseInt(args[0]);
            if (numBooks <= 0) {
                System.out.println("Number of books must be positive.");
                return;
            }
        } catch (NumberFormatException e) {
            System.out.println("Invalid number format.");
            return;
        }

        Scanner scanner = new Scanner(System.in);
        Library library = new Library(numBooks);

        // Input book details
        System.out.println("Number of books provided from command line: " + numBooks);
        for (int i = 0; i < numBooks; i++) {
            System.out.println("\nEnter details for book " + (i + 1) + ":");
            boolean validInput = false;

            while (!validInput) {
                System.out.print("Title: ");
                String title = scanner.nextLine();
                System.out.print("Author: ");
                String author = scanner.nextLine();
                System.out.print("ISBN: ");
                String isbn = scanner.nextLine();

                // Check if ISBN is unique
                if (!library.isIsbnUnique(isbn)) {
                    System.out.println("ISBN already exists, please try again.");
                    continue;
                }

                System.out.print("Total copies: ");
                int totalCopies;
                try {
                    totalCopies = Integer.parseInt(scanner.nextLine());
                    if (totalCopies <= 0) {
                        System.out.println("Total copies must be positive.");
                        continue;
                    }
                } catch (NumberFormatException e) {
                    System.out.println("Invalid input for total copies.");
                    continue;
                }

                System.out.print("Borrowed copies: ");
                int borrowedCopies;
                try {
                    borrowedCopies = Integer.parseInt(scanner.nextLine());
                    if (borrowedCopies < 0 || borrowedCopies > totalCopies) {
                        System.out.println("Invalid value, please try again: ");
                        continue;
                    }
                } catch (NumberFormatException e) {
                    System.out.println("Invalid input for borrowed copies.");
                    continue;
                }

                // Create and add book
                Book book = new Book(title, author, isbn, totalCopies, borrowedCopies);
                library.addBook(book);
                validInput = true;
            }
        }

        // Search loop
        while (true) {
            System.out.print("\nSearch for a book by title: ");
            String searchTitle = scanner.nextLine();
            Book foundBook = library.searchBook(searchTitle);
            library.displayBookDetails(foundBook);

            // Optional: Ask if user wants to continue searching
            System.out.print("Do you want to search for another book? (yes/no): ");
            String continueSearch = scanner.nextLine().trim().toLowerCase();
            if (!continueSearch.equals("yes")) {
                break;
            }
        }

        scanner.close();
    }
}