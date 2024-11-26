package producerconsumer;
import java.util.LinkedList;

public class ProducerConsumer {
    LinkedList<Integer> list = new LinkedList<>();
    int capacity = 5;

    // Producer thread
    public void produce() throws InterruptedException {
        int value = 0;
        while (true) {
            synchronized (this) {
                // Wait if the list is full
                while (list.size() == capacity) {
                    wait();
                }

                // Produce a value and add it to the list
                System.out.println("Producer produced: " + value);
                list.add(value++);

                // Notify the consumer thread that it can consume
                notify();

                // Sleep for demonstration
                Thread.sleep(1000);
            }
        }
    }

    // Consumer thread
    public void consume() throws InterruptedException {
        while (true) {
            synchronized (this) {
                // Wait if the list is empty
                while (list.isEmpty()) {
                    wait();
                }

                // Consume a value from the list
                int value = list.removeFirst();
                System.out.println("Consumer consumed: " + value);

                // Notify the producer thread that it can produce
                notify();

                // Sleep for demonstration
                Thread.sleep(1000);
            }
        }
    }

    public void run() throws InterruptedException {
        ProducerConsumer pc = new ProducerConsumer();

        // Create Producer thread
        Thread producerThread = new Thread(() -> {
            try {
                pc.produce();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        });

        // Create Consumer thread
        Thread consumerThread = new Thread(() -> {
            try {
                pc.consume();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        });

        // Start both threads
        producerThread.start();
        consumerThread.start();

        // Wait for threads to finish (in this case, they run indefinitely)
        producerThread.join();
        consumerThread.join();
    }
}