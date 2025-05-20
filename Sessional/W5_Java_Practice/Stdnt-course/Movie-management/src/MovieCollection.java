public class MovieCollection {
}
import java.util.ArrayList;

public class MovieCollection {
    private ArrayList<Movie> movies;

    // Constructor
    public MovieCollection() {
        movies = new ArrayList<>();
    }

    // Add a movie
    public void addMovie(Movie movie) {
        movies.add(movie);
    }

    // Search for a movie by title
    public Movie searchMovie(String title) {
        for (Movie movie : movies) {
            if (movie.getTitle().equalsIgnoreCase(title)) {
                return movie;
            }
        }
        return null;
    }

    // Rent a movie by title
    public boolean rentMovie(String title) {
        Movie movie = searchMovie(title);
        if (movie != null) {
            return movie.rentMovie();
        }
        return false;
    }
}