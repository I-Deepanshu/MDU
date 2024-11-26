package servletcookies;

import javax.servlet.*;
import javax.servlet.http.*;
import java.io.IOException;

public class VisitCounterServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        int visitCount = 0;

        // Retrieve cookies from the request
        Cookie[] cookies = request.getCookies();
        if (cookies != null) {
            for (Cookie cookie : cookies) {
                if ("visitCount".equals(cookie.getName())) {
                    visitCount = Integer.parseInt(cookie.getValue());
                }
            }
        }

        // Increment visit count
        visitCount++;

        // Create or update the cookie with the new visit count
        Cookie visitCookie = new Cookie("visitCount", String.valueOf(visitCount));
        visitCookie.setMaxAge(60 * 60 * 24); // 1 day
        response.addCookie(visitCookie);

        // Respond to the client
        response.setContentType("text/html");
        response.getWriter().println("<h1>Welcome to the Visit Counter Servlet</h1>");
        response.getWriter().println("<p>You have visited this page " + visitCount + " times.</p>");
    }
}
