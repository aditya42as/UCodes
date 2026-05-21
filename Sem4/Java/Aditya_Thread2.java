class AdThread implements Runnable {
    @Override
    public void run() {
        for(int i = 2; i <= 10; i = i+2) {
            System.out.println(i);
        }
    }
}

public class Aditya_Thread2 {
    public static void main(String arg[]) {
        Thread t = new Thread(new AdThread());

        t.start();
    }
}