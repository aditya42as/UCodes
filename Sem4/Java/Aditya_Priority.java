class Priority extends Thread {
    @Override
    public void run() {
        System.out.println(Thread.currentThread().getName() + " Priority: " + Thread.currentThread().getPriority());
    }
}

public class Aditya_Priority {
    public static void main(String arg[]) {
        Priority t1 = new Priority();
        Priority t2 = new Priority();

        t1.setPriority(Thread.MIN_PRIORITY);
        t2.setPriority(Thread.MAX_PRIORITY);

        t1.start();
        t2.start();
    }
}