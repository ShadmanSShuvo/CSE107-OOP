import java.util.ArrayList;

public class MovieCollection {
    private ArrayList<Movie> movies;

    public MovieCollection() {
        movies = new ArrayList<>();
    }

    public void addMovie(Movie movie) {
        movies.add(movie);
    }

    public Movie searchMovie(String title) {
        for (Movie movie : movies) {
            if (movie.getTitle().equalsIgnoreCase(title))
                return movie;
        }
        return null;
    }

    public boolean rentMovie(String title) {
        Movie movie = searchMovie(title);
        if (movie != null) {
            return movie.rentMovie();
        }
        return false;
    }
}
