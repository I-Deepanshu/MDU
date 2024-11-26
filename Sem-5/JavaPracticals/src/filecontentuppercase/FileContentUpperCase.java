package filecontentuppercase;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;

public class FileContentUpperCase {

    public void run() {
        System.out.println("Running FileContentUpperCase experiment...");

        // Specify the path to the file
        Path filePath = Paths.get("./filecontentuppercase/test.txt");

        try {
            // Read all lines from the file
            List<String> lines = Files.readAllLines(filePath);

            // Convert each line to uppercase
            for (int i = 0; i < lines.size(); i++) {
                lines.set(i, lines.get(i).toUpperCase());
            }

            // Write the modified content back to the file
            Files.write(filePath, lines);

            System.out.println("File content converted to uppercase successfully.");
        } catch (IOException e) {
            System.out.println("An error occurred: " + e.getMessage());
        }
    }
}
