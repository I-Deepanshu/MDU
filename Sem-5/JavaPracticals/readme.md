# JavaPracticals Project Setup and Execution Guide

## Project Structure

The project directory is organized as follows:

```
JavaPracticals/
├── src/
│   ├── main/
│   │   └── Main.java
│   ├── stackqueue/
│   │   └── StackQueue.java
│   ├── polymorphisminterfaces/
│   │   └── Polymorphism.java
│   ├── producerconsumer/
│   │   └── ProducerConsumer.java
│   ├── customexception/
│   │   └── CustomException.java
│   ├── filecontentuppercase/
│   │   └── FileContentUpperCase.java
│   ├── analogclock/
│   │   └── AnalogClock.java
│   ├── scientificcalculator/
│   │   └── ScientificCalculator.java
│   ├── texteditor/
│   │   └── TextEditor.java
│   ├── servletcookies/
│   │   └── ServletCookies.java
│   └── javabean/
│       └── JavaBean.java
```

## Steps to Compile and Run

1. **Navigate to the `src` Directory**  
   Open a command prompt or terminal and change to the `src` directory:

    ```bash
    cd "~\JavaPracticals\src"
    ```
2. **Compile All Java Files**

    Run the following command to compile all Java files across all packages:
  
      ```bash
      javac main/Main.java stackqueue/*.java polymorphisminterfaces/*.java producerconsumer/*.java customexception/*.java filecontentuppercase/*.java analogclock/*.java scientificcalculator/*.java texteditor/*.java servletcookies/*.java javabean/*.java
      ```
    After this run this command to run the Main.java file
    ```bash
    java main.Main
    ```
  
    This command compiles all classes and packages, ensuring that the `Main.java` file can access the other classes.