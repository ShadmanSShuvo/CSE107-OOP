public class Movie {
    private String title;
    private String genre;
    private double rating;
    private int totalCopies;
    private int rentedCopies;

    public Movie(String title, String genre, double rating, int totalCopies, int rentedCopies) {
        this.title = title;
        this.genre = genre;
        this.rating = rating;
        this.totalCopies = totalCopies;
        this.rentedCopies = rentedCopies;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getGenre() {
        return genre;
    }

    public void setGenre(String genre) {
        this.genre = genre;
    }

    public double getRating() {
        return rating;
    }

    public void setRating(double rating) {
        if (rating >= 0 && rating <= 10) {
            this.rating = rating;
        }
        else{
            System.out.println("Invalid rating input");
            return;
        }
    }

    public int getTotalCopies() {
        return totalCopies;
    }

    public void setTotalCopies(int totalCopies) {
        this.totalCopies = totalCopies;
    }

    public int getRentedCopies() {
        return rentedCopies;
    }


    public int getAvailableCopies() {
        return totalCopies - rentedCopies;
    }

    public void setRentedCopies(int rentedCopies) {
        this.rentedCopies = rentedCopies;
    }

    public boolean rentMovie() {
        if (getAvailableCopies() > 0) {
            rentedCopies++;
            return true;
        }
        return false;
    }


    public void displayDetails() {
        System.out.println("Movie details:");
        System.out.println("- Title: " + title);
        System.out.println("- Genre: " + genre);
        System.out.println("- Rating: " + rating);
        System.out.println("- Available copies: " + getAvailableCopies());
    }
}
