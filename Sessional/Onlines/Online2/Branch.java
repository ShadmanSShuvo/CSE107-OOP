import java.util.ArrayList;

public class Branch {
    private int ID;
    private int size;
    private int bookCount=0;
    private int borrowed=0;

    private Branch[] branches;
    private Book[] books;

    public Branch(int size) {
        if (size > 20) {
            System.out.println("Number of books cannot exceed 20");
            return;
        }
        this.size = size;
        books = new Book[size];
    }

    public int getBookCount() {
        return bookCount;
    }

    public void setBookCount(int bookCount) {
        this.bookCount = bookCount;
    }

    public int getBorrowed() {
        return borrowed;
    }

    public void setBorrowed(int borrowed) {
        this.borrowed = borrowed;
    }

    public Branch[] getBranches() {
        return branches;
    }

    public void setBranches(Branch[] branches) {
        this.branches = branches;
    }

    public int getID() {
        return ID;
    }

    public void setID(int ID) {
        this.ID = ID;
    }

    public int getSize() {
        return size;
    }

    public void setSize(int size) {
        this.size = size;
    }

    public Book[] getBooks() {
        return books;
    }

    public void setBooks(Book[] books) {
        this.books = books;
    }

    public void displayAll(){
        System.out.println("Branch " + getID() +":");
        for (int i = 0; i < getSize(); i++) {

            System.out.println("Book " + books[i].getId());
            System.out.println(" -Name" + books[i].getName());
            System.out.println(" -" + books[i].getName());
            if (books[i].isAvailable())
                System.out.println("Available");
            else
                System.out.println("Unavailable");
        }
    }

    public void addBook(Book b){
        if (bookCount < size)
            this.books[bookCount++] = b;
        else
            System.out.println("Cannot add more books");
    }

    public void borrowBook(int id){
        for (int i=0; i<bookCount; i++){
            if(id == books[i].getId()){
                if (books[i].isAvailable()) {
                    System.out.println("You Borrowed book with id "+ id);
                    books[i].setAvailable(false) ;
                    return;
                }
                else{
                    System.out.println("Not Available");
                    return;
                }
            }
        }
        System.out.println("Book isnot found");
    }

    public void returnBook(int id){
        for (int i=0; i<bookCount; i++){
            if(id == books[i].getId()){
                System.out.println("You returned book with id "+ id);
                books[i].setAvailable(true);
                return;
            }

        }
        System.out.println("Book is not found");
    }

}
