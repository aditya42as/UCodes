class Shared {

    int value;
    boolean avail = false;
    
    synchronized void produce(int val) {
        if (avail) {
            try {
                wait();
            } 
            catch (Exception e) {
                System.out.println(e.getMessage());
            }
        }
        value = val;
        System.out.println("Produced: " + value);
        avail = true;
        notify();

    }

    synchronized void consume() {
        if(!avail) {
            try {
                wait();
            } 
            catch (Exception e) {
                System.out.println(e.getMessage());
            }
        }
        System.out.println("Consumed: " + value);
        avail = false;
        notify();
    }

}

class Producer extends Thread {
    Shared s1;
    Producer(Shared s1) {
        this.s1 = s1;
    }
    public void run() {
        for(int i = 1; i <= 5; i++) {
            s1.produce(i);
        }
    }
    
}

class Consumer extends Thread {
    Shared s1;
    Consumer(Shared s1) {
        this.s1 = s1;
    }
    public void run() {
        for(int i = 1; i <= 5; i++) {
            s1.consume();
        }
    }
}

class Aditya_S {
    public static void main(String arg[]) {
        Shared s = new Shared();
        Producer p = new Producer(s);
        Consumer c = new Consumer(s);

        p.start();
        c.start();
    }
}
