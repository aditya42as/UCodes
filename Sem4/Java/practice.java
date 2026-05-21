
import java.io.FileReader;
import java.io.IOException;

class practice{

    static void readfile(String filename) throws IOException {
        try (FileReader file = new FileReader(filename)) {
            int data;
            while ((data = file.read()) != -1) {
                System.out.println((char)data);
            }
        }
    }

    public static void main(String[] args) {
        try {
            readfile("myfile.txt");
        } catch (IOException e) {
            System.out.println("File not found: " + e.getMessage());
        }
    }
    
}