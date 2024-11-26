package servletcookies;

import org.eclipse.jetty.server.Server;
import org.eclipse.jetty.servlet.ServletContextHandler;
import org.eclipse.jetty.servlet.ServletHolder;

public class ServletCookies {
    public void run() {
        System.out.println("Starting ServletCookies experiment...");
        try {
            // Initialize Jetty server on port 8080
            Server server = new Server(8080);

            // Set up servlet context handler
            ServletContextHandler context = new ServletContextHandler(ServletContextHandler.SESSIONS);
            context.setContextPath("/");
            server.setHandler(context);

            // Add VisitCounterServlet to the server
            context.addServlet(new ServletHolder(new VisitCounterServlet()), "/visit");

            // Start the server
            server.start();
            System.out.println("Server started at http://localhost:8080/visit");
            server.join();
        } catch (Exception e) {
            System.out.println("Error starting server: " + e.getMessage());
        }
    }
}
