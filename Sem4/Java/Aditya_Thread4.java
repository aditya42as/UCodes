class SleepDemo extends Thread{
    @Override
    public void run() {
        for(int i = 1; i <= 20; i++) {
            System.out.println(i);
            try {
                Thread.sleep(500);
            }
            catch(InterruptedException e) {
                System.out.println(e.getMessage());
            }
        }   
    }
}

public class Aditya_Thread4{
    public static void main(String arg[]) {
        SleepDemo s = new SleepDemo();

        s.start();

    }
}