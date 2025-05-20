import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        MovieCollection collection = new MovieCollection();

        // Get number of movies from command line argument
        int numMovies = Integer.parseInt(args[0]);
        System.out.println("Number of movies from command line argument: " + numMovies);

        // Input movie details
        for (int i = 1; i <= numMovies; i++) {
            System.out.println("\nEnter details for movie " + i + ":");
            System.out.print("Title: ");
            String title = scanner.nextLine();
            System.out.print("Genre: ");
            String genre = scanner.nextLine();

            // Validate rating
            double rating;
            do {
                System.out.print("Rating (out of 10): ");
                rating = scanner.nextDouble();
                if (rating < 0 || rating > 10) {
                    System.out.print("Invalid value, please try again: ");
                }
            } while (rating < 0 || rating > 10);

            // Validate copies
            int totalCopies, rentedCopies;
            do {
                System.out.print("Total copies: ");
                totalCopies = scanner.nextInt();
                System.out.print("Rented copies: ");
                rentedCopies = scanner.nextInt();
                if (rentedCopies > totalCopies) {
                    System.out.println("Error: Rented copies cannot exceed total copies. Please try again.");
                }
            } while (rentedCopies > totalCopies);

            scanner.nextLine(); // Clear buffer
            Movie movie = new Movie(title, genre, rating, totalCopies, rentedCopies);
            collection.addMovie(movie);
        }

        // Display command menu
        System.out.println("\n---");
        System.out.println("Commands:");
        System.out.println("- search <title>: Search for a movie by title and display details.");
        System.out.println("- rent <title>: Attempt to rent a movie by title, increasing rented copies if available.");
        System.out.println("---");

        // Process commands
        boolean runn = true;
        while (runn) {
            System.out.print("\nEnter command: ");
            String command = scanner.nextLine();
            String[] parts = command.split(" ", 2);

            if (parts.length < 2) {
                System.out.println("Invalid command format.");
                continue;
            }

            String action = parts[0].toLowerCase();
            String title = parts[1];

            if (action.equals("search")) {
                Movie movie = collection.searchMovie(title);
                if (movie != null) {
                    movie.displayDetails();
                } else {
                    System.out.println("Movie not found.");
                }
            } else if (action.equals("rent")) {
                Movie movie = collection.searchMovie(title);
                if (movie != null) {
                    if (collection.rentMovie(title)) {
                        System.out.println("Rent successful! Available copies for " + title + ": " + movie.getAvailableCopies());
                    } else {
                        System.out.println("Error: All copies of \"" + title + "\" are currently rented out.");
                    }
                } else {
                    System.out.println("Movie not found.");
                }
            } else if (action.equals("exit")) {
                runn = false;
            } else {
                System.out.println("Invalid command.");
            }
        }
        scanner.close();
    }
}