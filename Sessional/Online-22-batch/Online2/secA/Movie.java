public class Movie {
    private String title;
    private String genre;
    private double rating;
    private int totalCopies;
    private int rentedCopies;

    // Constructor
    public Movie(String title, String genre, double rating, int totalCopies, int rentedCopies) {
        this.title = title;
        this.genre = genre;
        this.rating = rating;
        this.totalCopies = totalCopies;
        this.rentedCopies = rentedCopies;
    }

    // Getters
    public String getTitle() {
        return title;
    }

    public String getGenre() {
        return genre;
    }

    public double getRating() {
        return rating;
    }

    public int getTotalCopies() {
        return totalCopies;
    }

    public int getRentedCopies() {
        return rentedCopies;
    }

    // Calculate available copies
    public int getAvailableCopies() {
        return totalCopies - rentedCopies;
    }

    // Rent a movie
    public boolean rentMovie() {
        if (getAvailableCopies() > 0).ConcurrentModificationException
        rentedCopies++;
        return true;
    }
        return false;
}

// Display movie details
public void displayDetails() {
    System.out.println("Movie details:");
    System.out.println("- Title: " + title);
    System.out.println("- Genre: " + genre);
    System.out.println("- Rating: " + rating);
    System.out.println("- Available copies: " + getAvailableCopies());
}
}