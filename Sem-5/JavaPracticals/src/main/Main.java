package main;

import java.util.Scanner;

import stackqueue.StackQueue;
import polymorphisminterfaces.Polymorphism;
import producerconsumer.ProducerConsumer;
import customexception.CustomException;
import filecontentuppercase.FileContentUpperCase;
import analogclock.AnalogClock;
import scientificcalculator.ScientificCalculator;
import texteditor.TextEditor;
import servletcookies.ServletCookies;
import javabean.JavaBean;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        try {
            System.out.println("Java Practicals");
            System.out.println("1. Stack and Queue");
            System.out.println("2. Polymorphism and Interfaces");
            System.out.println("3. Producer and Consumer");
            System.out.println("4. Custom Exception");
            System.out.println("5. File Content Uppercase");
            System.out.println("6. Analog Clock");
            System.out.println("7. Scientific Calculator");
            System.out.println("8. Text Editor");
            System.out.println("9. Servlet Cookies");
            System.out.println("10. Java Bean");
            System.out.println("0. Exit");
            System.out.println("Select an experiment to run (1-10):");
            int choice = scanner.nextInt();

            while (true) {
                switch (choice) {
                    case 0:
                        System.out.println("Exiting...");
                        return;
                    case 1:
                        new StackQueue().run();
                        break;
                    case 2:
                        new Polymorphism().run();
                        break;
                    case 3:
                        new ProducerConsumer().run();
                        break;
                    case 4:
                        new CustomException().run();
                        break;
                    case 5:
                        new FileContentUpperCase().run();
                        break;
                    case 6:
                        new AnalogClock().run();
                        break;
                    case 7:
                        new ScientificCalculator().run();
                        break;
                    case 8:
                        new TextEditor().run();
                        break;
                    case 9:
                        new ServletCookies().run();
                        break;
                    case 10:
                        new JavaBean().run();
                        break;
                    default:
                        System.out.println("Invalid choice.");
                }
                System.out.println("Select an experiment to run (1-10):");
                choice = scanner.nextInt();
            }
        } catch (Exception e) {
            System.out.println("Invalid input.");
        } finally {
            scanner.close();
        }
    }
}
