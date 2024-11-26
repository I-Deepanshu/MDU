package polymorphisminterfaces;

// Define an interface called `Animal`
interface Animal {
    void sound();
}

// Implement the `Animal` interface with a `Dog` class
class Dog implements Animal {
    public void sound() {
        System.out.println("Dog says: Woof Woof");
    }
}

// Implement the `Animal` interface with a `Cat` class
class Cat implements Animal {
    public void sound() {
        System.out.println("Cat says: Meow Meow");
    }
}

// Implement the `Animal` interface with a `Cow` class
class Cow implements Animal {
    public void sound() {
        System.out.println("Cow says: Moo Moo");
    }
}

// Main class to demonstrate dynamic polymorphism
public class Polymorphism {
    public void run() {
        System.out.println("Running...");

        // Create instances of different `Animal` types dynamically
        Animal myDog = new Dog();
        Animal myCat = new Cat();
        Animal myCow = new Cow();

        // Call the `sound` method on each `Animal` instance
        myDog.sound();  // Output: Dog says: Woof Woof
        myCat.sound();  // Output: Cat says: Meow Meow
        myCow.sound();  // Output: Cow says: Moo Moo
    }
    
    public static void main(String[] args) {
        // Instantiate the `Polymorphism` class and run the experiment
        Polymorphism experiment = new Polymorphism();
        experiment.run();
    }
}
