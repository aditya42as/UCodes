class AdThread extends Thread {
    String name;

    AdThread(String name) {
        this.name = name;
    }
    public void run() {
        for(int i = 1; i <= 20; i++) {
            System.out.println(name + " " + i);

            try {
                if(name.equals("MyThread")) {
                    Thread.sleep(1000);
                }
            } catch (InterruptedException e) {
            }
        }

    }

}

public class Aditya_Thread3 {
    public static void main(String[] args) {
        AdThread ad = new AdThread("MyThread");

        ad.start();
    }
}