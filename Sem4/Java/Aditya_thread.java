class AdThread extends Thread {
    String name;
    public AdThread(String name) {
        this.name = name;
        
    }
    
    public void run() {
        for(int i = 0; i < 5; i++) {
            System.out.println(name + " " + (i+1));
        }
        try {
            Thread.sleep(500);
        }
        catch(InterruptedException e) {
            System.out.println(e.getMessage());
        }
    }
}

public class Aditya_thread {
    public static void main(String arg[]) {
        AdThread a1 = new AdThread("CSThread");
        AdThread a2 = new AdThread("ITThread");

        a1.start();
        a2.start();
    }
}
