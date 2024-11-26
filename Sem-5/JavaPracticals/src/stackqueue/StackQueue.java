package stackqueue;

import java.util.Stack;
import java.util.LinkedList;
import java.util.Queue;

public class StackQueue {

    public void run() {
        // Stack operations
        System.out.println("Stack Operations:");
        Stack<Integer> stack = new Stack<>();
        stack.push(1);
        stack.push(2);
        stack.push(3);
        System.out.println("Stack after pushes: " + stack);

        stack.pop();
        System.out.println("Stack after pop: " + stack);

        System.out.println("Top of stack (peek): " + stack.peek());

        // Queue operations
        System.out.println("\nQueue Operations:");
        Queue<Integer> queue = new LinkedList<>();
        queue.add(1);
        queue.add(2);
        queue.add(3);
        System.out.println("Queue after adds: " + queue);

        queue.poll();
        System.out.println("Queue after poll: " + queue);

        System.out.println("Front of queue (peek): " + queue.peek());
    }
}