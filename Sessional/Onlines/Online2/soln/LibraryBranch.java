import java.util.ArrayList;

public class LibraryBranch {
    private int branchId;
    private ArrayList<Book> books;

    public LibraryBranch(int branchId) {
        this.branchId = branchId;
        this.books = new ArrayList<>();
    }

    public int getBranchId() {
        return branchId;
    }

    public boolean addBook(Book book) {
        if (books.size() >= 20) {
            return false;
        }
        books.add(book);
        return true;
    }

    public Book findBook(int bookId) {
        for (Book book : books) {
            if (book.getBookId() == bookId) {
                return book;
            }
        }
        return null;
    }

    public ArrayList<Book> getBooks() {
        return books;
    }
}