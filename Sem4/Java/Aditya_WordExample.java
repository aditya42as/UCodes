import java.util.Scanner;

class WordExample {
    private String strdata;

    WordExample(String strdata) {
        this.strdata = strdata;
    }

    void countWord() {
        String words[] = strdata.split(" ");
        int count = 0;

        for(String w : words) {
            char first = w.charAt(0);
            char last = w.charAt(w.length()-1);

            if("AEIOU".indexOf(first)!=-1 && "AEIOU".indexOf(last)!=-1)
                count++;
        }
        System.out.println("Count = " + count);
    }

    void placeWord() {
        String words[] = strdata.split(" ");
        String v = "", nv = "";

        for(String w : words) {
            char first = w.charAt(0);
            char last = w.charAt(w.length()-1);

            if("AEIOU".indexOf(first)!=-1 && "AEIOU".indexOf(last)!=-1)
                v += w + " ";
            else
                nv += w + " ";
        }
        System.out.println(v + nv);
    }

}

class Aditya_WordExample{
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter String: ");
        String s = sc.nextLine();

        WordExample w = new WordExample(s);
        w.countWord();
        w.placeWord();

        sc.close();
    }
}