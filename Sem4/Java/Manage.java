import java.util.Scanner;

class Library{
    String name;
    String location;

    void setLibraryinfo(String name, String location) {
        this.name = name;
        this.location = location;
    }

    void displayLibraryinfo() {
        System.out.println("Library Name: " + name);
        System.out.println("Location: " + location);
    }


}

class Book extends Library {
    int bookId;
    String bookTitle;
    String author;
    boolean isIssued;

    void addBook(int bookId, String bookTitle, String author) {
        this.bookId = bookId;
        this.bookTitle = bookTitle;
        this.author = author;
    }

    void displayBook() {
        super.displayLibraryinfo();
        System.out.println("Book ID: " + bookId);
        System.out.println("Title: " + bookTitle);
        System.out.println("Author: " + author);
    }

}

class IssuedBook extends Book {
    String issueDate;
    String returnDate;
    int allowedDays = 7;
    double finePerDay = 10;

    void issueBook(String issueDate) {
        super.isIssued = true;
        this.issueDate = issueDate;
    }

    void returnBook(String returnDate) {
        super.isIssued =false;
        this.returnDate = returnDate;
    }

    double calculateFine() {

    }
}

class Manage {
    public static void main(String arg[]) {
        
        Scanner sc = new Scanner(System.in);
        
        Library l1 = new Library();
        
        l1.setLibraryinfo("Corv", "Harbhajwala");
    }
}