/*
 * The following applet code is commented in the file. 
 * You can use this code along with the Swing components to view the desired output.
 */

// package analogclock;

// import java.applet.Applet;
// import java.awt.Color;
// import java.awt.Graphics;
// import java.util.Calendar;

// public class AnalogClock {

//     public void run() {
//         System.out.println("Running AnalogClock experiment...");

//         // Applet setup code can go here if necessary
//     }

//     @SuppressWarnings("removal")
//     public static class ClockApplet extends Applet {

//         // Initialize the applet with a black background
//         @Override
//         public void init() {
//             setBackground(Color.BLACK);
//         }

//         // Start the clock in a separate thread to update every second
//         @Override
//         public void start() {
//             new Thread(() -> {
//                 while (true) {
//                     try {
//                         Thread.sleep(1000);
//                     } catch (InterruptedException e) {
//                         e.printStackTrace();
//                     }
//                     repaint(); // Refresh the display every second
//                 }
//             }).start();
//         }

//         // Paint method to draw the analog clock face and hands
//         @Override
//         public void paint(Graphics g) {
//             double angle;
//             int x, y;

//             // Draw clock numbers (1 to 12) around the face
//             g.setColor(Color.WHITE);
//             for (int i = 1; i <= 12; i++) {
//                 angle = i * Math.PI / 6;
//                 x = (int) (200 * Math.sin(angle));
//                 y = (int) (200 * Math.cos(angle));
//                 g.drawString(Integer.toString(i), 300 + x, 300 - y);
//             }

//             // Draw clock center
//             g.fillOval(295, 295, 10, 10);

//             // Get current time
//             Calendar calendar = Calendar.getInstance();
//             int hour = calendar.get(Calendar.HOUR_OF_DAY) % 12;
//             int minute = calendar.get(Calendar.MINUTE);
//             int second = calendar.get(Calendar.SECOND);

//             // Draw hour hand
//             angle = (hour * Math.PI / 6) + (minute * Math.PI / (6 * 60)) + (second * Math.PI / (360 * 60));
//             x = (int) (160 * Math.sin(angle));
//             y = (int) (160 * Math.cos(angle));
//             g.setColor(Color.WHITE);
//             g.drawLine(300, 300, 300 + x, 300 - y);

//             // Draw minute hand
//             angle = (minute * Math.PI / 30) + (second * Math.PI / (30 * 60));
//             x = (int) (190 * Math.sin(angle));
//             y = (int) (190 * Math.cos(angle));
//             g.drawLine(300, 300, 300 + x, 300 - y);

//             // Draw second hand in red
//             g.setColor(Color.RED);
//             angle = second * Math.PI / 30;
//             x = (int) (190 * Math.sin(angle));
//             y = (int) (190 * Math.cos(angle));
//             g.drawLine(300, 300, 300 + x, 300 - y);
//         }
//     }
// }

// ------------------------------------------------------------------
/* 
 * Using Swing to display the clock as java applets are depricated 
 */
// ------------------------------------------------------------------

package analogclock;

import javax.swing.*;
import java.awt.*;
import java.util.Calendar;

public class AnalogClock {

    public void run() {
        System.out.println("Running Analog Clock...");

        // Create a JFrame for displaying the clock
        JFrame frame = new JFrame("Analog Clock");
        ClockPanel clockPanel = new ClockPanel();

        frame.add(clockPanel);
        frame.setSize(600, 600);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);

        clockPanel.startClock();
    }

    public static class ClockPanel extends JPanel {
        public ClockPanel() {
            setPreferredSize(new Dimension(600, 600));
            setBackground(Color.BLACK);
        }

        public void startClock() {
            new Thread(() -> {
                while (true) {
                    try {
                        Thread.sleep(1000);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                    repaint(); // Repaint every second
                }
            }).start();
        }

        @Override
        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            double angle;
            int x, y;

            // Draw clock numbers (1 to 12) around the face
            g.setColor(Color.WHITE);
            for (int i = 1; i <= 12; i++) {
                angle = i * Math.PI / 6;
                x = (int) (200 * Math.sin(angle));
                y = (int) (200 * Math.cos(angle));
                g.drawString(Integer.toString(i), 300 + x, 300 - y);
            }

            // Draw clock center
            g.fillOval(295, 295, 10, 10);

            // Get current time
            Calendar calendar = Calendar.getInstance();
            int hour = calendar.get(Calendar.HOUR_OF_DAY) % 12;
            int minute = calendar.get(Calendar.MINUTE);
            int second = calendar.get(Calendar.SECOND);

            // Draw hour hand
            angle = (hour * Math.PI / 6) + (minute * Math.PI / (6 * 60)) + (second * Math.PI / (360 * 60));
            x = (int) (160 * Math.sin(angle));
            y = (int) (160 * Math.cos(angle));
            g.setColor(Color.WHITE);
            g.drawLine(300, 300, 300 + x, 300 - y);

            // Draw minute hand
            angle = (minute * Math.PI / 30) + (second * Math.PI / (30 * 60));
            x = (int) (190 * Math.sin(angle));
            y = (int) (190 * Math.cos(angle));
            g.drawLine(300, 300, 300 + x, 300 - y);

            // Draw second hand in red
            g.setColor(Color.RED);
            angle = second * Math.PI / 30;
            x = (int) (190 * Math.sin(angle));
            y = (int) (190 * Math.cos(angle));
            g.drawLine(300, 300, 300 + x, 300 - y);
        }
    }

    public static void main(String[] args) {
        new AnalogClock().run();
    }
}
