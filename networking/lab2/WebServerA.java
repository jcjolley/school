
/** ***********************************************************************
 * Program:
 *    Lab Webserver, Computer Communication and Networking
 *    Brother Jones, CS 460
 * Author:
 *    Your Name
 * Summary:
 *    This program ...
 ************************************************************************** */
import java.io.*;
import java.net.*;
import java.util.*;

public final class WebServer {

   /**
    *
    * @param argv
    * @throws Exception
    */
   public static void main(String argv[]) throws Exception {
      // sets the port number to be used (default: 6789; optional: argv[0])
      int port = argv.length > 0 ? Integer.parseInt(argv[0]) : 6789;

      // Establish the listen socket.
      ServerSocket listenSocket = new ServerSocket(port);
      
		// Process HTTP service requests in an infinite loop
      while (true) {
         // Listen for a TCP connection request.
      	final Socket connectionSocket = listenSocket.accept();   
           // Construct an object to process the HTTP request message.
               HttpRequest request = new HttpRequest(connectionSocket);

         // Create a new thread to process the request.
         Thread thread = new Thread(request);

         // Start the thread.
         thread.start();
      }
   }
}

final class HttpRequest implements Runnable {

   final static String CRLF = "\r\n";
   Socket socket;

   // Constructor
   public HttpRequest(Socket socket) throws Exception {
      this.socket = socket;
   }

   // Implement the run() method of the Runnable interface.
   @Override
   public void run() {
      try {
         processRequest();
      } catch (Exception e) {
         System.out.println(e);
      }
   }

   private void processRequest() throws Exception {
      // Get a reference to the socket's input and output streams.
      try (
         InputStream is =  socket.getInputStream();
      	DataOutputStream os = new DataOutputStream(socket.getOutputStream());
         BufferedReader br =  new BufferedReader(new InputStreamReader(is));
      ) {
         // Get the request line of the HTTP request message.
         String requestLine =  br.readLine();
         // Display the request line.
         System.out.println();
         System.out.println(requestLine);
         // Get and display the header lines.
         String headerLine = br.readLine();
       	System.out.println(headerLine);
         while ((headerLine = br.readLine()).length() != 0) {
            System.out.println(headerLine + headerLine.length());
         }
      }
      socket.close();
   }
}
