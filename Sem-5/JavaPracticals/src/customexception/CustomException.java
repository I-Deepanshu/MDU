package customexception;

// Define a custom exception called `InvalidAgeException`
class InvalidAgeException extends Exception {
    public InvalidAgeException(String message) {
        super(message);
    }
}

public class CustomException {
    // Method that uses the `throws` keyword to declare a custom exception
    public void checkAge(int age) throws InvalidAgeException {
        // Use `throw` to create and throw an instance of the custom exception
        if (age < 18) {
            throw new InvalidAgeException("Age must be 18 or above.");
        } else {
            System.out.println("Access granted. Age is valid.");
        }
    }

    public void run() {
        System.out.println("Running CustomException experiment...");

        try {
            // Trying to check an invalid age
            checkAge(16); // This should throw the InvalidAgeException
        } catch (InvalidAgeException e) {
            // Handling the custom exception
            System.out.println("Caught an exception: " + e.getMessage());
        } finally {
            // Code in finally block always runs, regardless of exception
            System.out.println("Age check complete.");
        }
    }

}
