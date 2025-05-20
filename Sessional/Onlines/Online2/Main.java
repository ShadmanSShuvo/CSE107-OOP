import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        System.out.println("Hello");

        int numBranch = Integer.parseInt(args[0]);
        if (numBranch > 10) {
            System.out.println("Number of branch cannot exceed 10");
            return;
        }
        System.out.println("Number of branch from cmd line" + numBranch);
        Branch[] branches = new Branch[numBranch];
        for (int i=0; i<numBranch; i++){
            Scanner scanner = new Scanner(System.in);
            System.out.println("Enter id for branch" + (i+1));
            branches[i].setID(Integer.parseInt(scanner.nextLine()));

            System.out.println("How many books to store");
            branches[i].setSize(Integer.parseInt(scanner.nextLine()));

            for (int j=0; j<branches[i].getSize(); j++){
                System.out.println("Enter book id:");
                branches[i].getBooks()[j].setId(Integer.parseInt(scanner.nextLine()));
                System.out.println("Enter Book title");
                branches[i].getBooks()[j].setName(scanner.nextLine());
                System.out.println("is Availabe? (Enter true/false");
                boolean isAv = scanner.nextBoolean();
                if(isAv)
                    branches[i].getBooks()[j].setAvailable(true);
                else
                    branches[i].getBooks()[j].setAvailable(false);

            }

        }


        boolean isExit = false;
        while (!isExit){
            Scanner scanner = new Scanner(System.in);
            System.out.println("Menu: ");
            System.out.println("1. borrow a book");
            System.out.println("2. return a book");
            System.out.println("3. Display all books");
            System.out.println("4. exit");

            int option = scanner.nextInt();
            switch (option) {
                case 1:
                    System.out.println("Branch id:");
                    int brId = scanner.nextInt();
                    System.out.println("Book id:");
                    int bId = scanner.nextInt();


                case 2:
                    System.out.println("Branch id:");
                    int brId = scanner.nextInt();
                    System.out.println("Book id:");
                    int bId = scanner.nextInt();


                case 3:
                    displayAll();

                case 4:
                    isExit = true;
            }

        }


    }

}
