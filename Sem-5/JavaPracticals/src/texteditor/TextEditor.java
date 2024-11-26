package texteditor;

import java.awt.*;
import javax.swing.*;
import java.io.*;
import java.awt.event.*;
import javax.swing.plaf.metal.*;
import javax.swing.text.*;

public class TextEditor extends JFrame implements ActionListener {
    private JTextArea textArea;
    private JFrame frame;

    public TextEditor() {
        initializeUI();
    }

    private void initializeUI() {
        // Create a frame
        frame = new JFrame("Text Editor");

        try {
            // Set metal look and feel
            UIManager.setLookAndFeel("javax.swing.plaf.metal.MetalLookAndFeel");
            MetalLookAndFeel.setCurrentTheme(new OceanTheme());
        } catch (Exception e) {
            JOptionPane.showMessageDialog(frame, "Failed to set LookAndFeel: " + e.getMessage());
        }

        // Text component
        textArea = new JTextArea();

        // Create a menu bar
        JMenuBar menuBar = new JMenuBar();

        // File menu
        JMenu fileMenu = new JMenu("File");
        createMenuItem(fileMenu, "New");
        createMenuItem(fileMenu, "Open");
        createMenuItem(fileMenu, "Save");
        createMenuItem(fileMenu, "Print");

        // Edit menu
        JMenu editMenu = new JMenu("Edit");
        createMenuItem(editMenu, "Cut");
        createMenuItem(editMenu, "Copy");
        createMenuItem(editMenu, "Paste");

        // Close menu item
        JMenuItem closeItem = new JMenuItem("Close");
        closeItem.addActionListener(this);
        menuBar.add(fileMenu);
        menuBar.add(editMenu);
        menuBar.add(closeItem);

        frame.setJMenuBar(menuBar);
        frame.add(new JScrollPane(textArea), BorderLayout.CENTER);
        frame.setSize(500, 500);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    private void createMenuItem(JMenu menu, String text) {
        JMenuItem menuItem = new JMenuItem(text);
        menuItem.addActionListener(this);
        menu.add(menuItem);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        String command = e.getActionCommand();

        switch (command) {
            case "Cut":
                textArea.cut();
                break;
            case "Copy":
                textArea.copy();
                break;
            case "Paste":
                textArea.paste();
                break;
            case "Save":
                saveFile();
                break;
            case "Open":
                openFile();
                break;
            case "New":
                textArea.setText("");
                break;
            case "Print":
                printFile();
                break;
            case "Close":
                frame.setVisible(false);
                frame.dispose();
                break;
        }
    }

    private void saveFile() {
        JFileChooser fileChooser = new JFileChooser("f:");
        int response = fileChooser.showSaveDialog(null);
        if (response == JFileChooser.APPROVE_OPTION) {
            File file = new File(fileChooser.getSelectedFile().getAbsolutePath());
            try (BufferedWriter writer = new BufferedWriter(new FileWriter(file))) {
                writer.write(textArea.getText());
            } catch (IOException ex) {
                JOptionPane.showMessageDialog(frame, "Error saving file: " + ex.getMessage());
            }
        } else {
            JOptionPane.showMessageDialog(frame, "Save operation canceled");
        }
    }

    private void openFile() {
        JFileChooser fileChooser = new JFileChooser("f:");
        int response = fileChooser.showOpenDialog(null);
        if (response == JFileChooser.APPROVE_OPTION) {
            File file = new File(fileChooser.getSelectedFile().getAbsolutePath());
            try (BufferedReader reader = new BufferedReader(new FileReader(file))) {
                textArea.read(reader, null);
            } catch (IOException ex) {
                JOptionPane.showMessageDialog(frame, "Error opening file: " + ex.getMessage());
            }
        } else {
            JOptionPane.showMessageDialog(frame, "Open operation canceled");
        }
    }

    private void printFile() {
        try {
            textArea.print();
        } catch (Exception ex) {
            JOptionPane.showMessageDialog(frame, "Error printing file: " + ex.getMessage());
        }
    }

    public void run() {
        frame.setVisible(true);
    }
}
