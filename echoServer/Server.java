// Johnnie Hernandez & Malik Hill
//  CSCI 3000

//Program receives "Hello there!" to server, then responds with "Hello there!"
import java.net.*;
import java.io.*;

public class Server {
    // initialize socket and input stream
    private Socket socket = null;
    private ServerSocket server = null;
    private DataInputStream in = null;
    private DataOutputStream out = null;

    // constructor with port
    public Server(int port) {
        // starts server and waits for a connection
        try {
            server = new ServerSocket(port);
            System.out.println("Server lisenting");

            socket = server.accept();
            System.out.println("Client accepted");

            // takes input from the client socket
            in = new DataInputStream(new BufferedInputStream(socket.getInputStream()));
            out = new DataOutputStream(socket.getOutputStream());
            String temp = "";

            // reads message from client until "Over" is sent
            while (!temp.equals(".exit")) {
                try {
                    temp = in.readUTF();
                    System.out.println(temp);

                } catch (IOException i) {
                    System.out.println(i);

                }
                try {
                    out.writeUTF(temp);
                } catch (IOException i) {
                    System.out.println(i);
                }
            }
            System.out.println("Closing connection");

            // close connection
            socket.close();
            in.close();
            out.close();
        } catch (IOException i) {
            System.out.println(i);
        }
    }

    public static void main(String args[]) {
        Server server = new Server(4000);
    }
}