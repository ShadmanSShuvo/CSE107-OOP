/**
 * Represents a book in the Library Book Management System.
 * Stores details such as title, author, ISBN, total copies, and borrowed copies.
 */
public class Book {
    private String title;
    private String author;
    private String isbn;
    private int totalCopies;
    private int borrowedCopies;

    /**
     * Constructs a Book object with the specified details.
     *
     * @param title         The title of the book
     * @param author        The author of the book
     * @param isbn          The ISBN of the book
     * @param totalCopies   The total number of copies available
     * @param borrowedCopies The number of copies currently borrowed
     * @throws IllegalArgumentException if inputs are invalid
     */
    public Book(String title, String author, String isbn, int totalCopies, int borrowedCopies) {
        setTitle(title);
        setAuthor(author);
        setIsbn(isbn);
        setTotalCopies(totalCopies);
        setBorrowedCopies(borrowedCopies);
    }

    /**
     * Gets the title of the book.
     *
     * @return The title
     */
    public String getTitle() {
        return title;
    }

    /**
     * Sets the title of the book.
     *
     * @param title The title to set
     * @throws IllegalArgumentException if title is null or empty
     */
    public void setTitle(String title) {
        if (title == null || title.trim().isEmpty()) {
            throw new IllegalArgumentException("Title cannot be null or empty");
        }
        this.title = title.trim();
    }

    /**
     * Gets the author of the book.
     *
     * @return The author
     */
    public String getAuthor() {
        return author;
    }

    /**
     * Sets the author of the book.
     *
     * @param author The author to set
     * @throws IllegalArgumentException if author is null or empty
     */
    public void setAuthor(String author) {
        if (author == null || author.trim().isEmpty()) {
            throw new IllegalArgumentException("Author cannot be null or empty");
        }
        this.author = author.trim();
    }

    /**
     * Gets the ISBN of the book.
     *
     * @return The ISBN
     */
    public String getIsbn() {
        return isbn;
    }

    /**
     * Sets the ISBN of the book.
     *
     * @param isbn The ISBN to set
     * @throws IllegalArgumentException if ISBN is null or empty
     */
    public void setIsbn(String isbn) {
        if (isbn == null || isbn.trim().isEmpty()) {
            throw new IllegalArgumentException("ISBN cannot be null or empty");
        }
        this.isbn = isbn.trim();
    }

    /**
     * Gets the total number of copies.
     *
     * @return The total copies
     */
    public int getTotalCopies() {
        return totalCopies;
    }

    /**
     * Sets the total number of copies.
     *
     * @param totalCopies The total copies to set
     * @throws IllegalArgumentException if totalCopies is not positive
     */
    public void setTotalCopies(int totalCopies) {
        if (totalCopies <= 0) {
            throw new IllegalArgumentException("Total copies must be positive");
        }
        this.totalCopies = totalCopies;
    }

    /**
     * Gets the number of borrowed copies.
     *
     * @return The borrowed copies
     */
    public int getBorrowedCopies() {
        return borrowedCopies;
    }

    /**
     * Sets the number of borrowed copies.
     *
     * @param borrowedCopies The borrowed copies to set
     * @throws IllegalArgumentException if borrowedCopies is negative or exceeds total copies
     */
    public void setBorrowedCopies(int borrowedCopies) {
        if (borrowedCopies < 0) {
            throw new IllegalArgumentException("Borrowed copies cannot be negative");
        }
        if (borrowedCopies > totalCopies) {
            throw new IllegalArgumentException("Borrowed copies cannot exceed total copies");
        }
        this.borrowedCopies = borrowedCopies;
    }

    /**
     * Calculates the number of available copies.
     *
     * @return The number of copies available (total - borrowed)
     */
    public int getAvailableCopies() {
        return totalCopies - borrowedCopies;
    }
}