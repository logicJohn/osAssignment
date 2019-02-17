// Johnnie Hernandez
//  CSCI 3000

//Program sends "Hello there!" to server, where server responds with "Hello there!"
import java.net.*;
import java.io.*;

public class Client {
    // initialize socket and streams
    private Socket socket = null;
    private DataInputStream input = null;
    private DataOutputStream out = null;

    // construct ip:port
    public Client(String address, int port) {
        // open connection
        try {
            socket = new Socket(address, port);
            System.out.println("Socket open");

            // takes input from terminal
            input = new DataInputStream(System.in);

            // sends output to the socket
            out = new DataOutputStream(socket.getOutputStream());
        } catch (UnknownHostException u) {
            System.out.println(u);
        } catch (IOException i) {
            System.out.println(i);
        }

        // string to read message from input
        String line = "";

        // keep reading until "Over" is input
        while (!line.equals("Over")) {
            try {
                line = input.readLine();
                out.writeUTF(line);
            } catch (IOException i) {
                System.out.println(i);
            }
        }

        // close the connection
        try {
            input.close();
            out.close();
            socket.close();
        } catch (IOException i) {
            System.out.println(i);
        }
    }

    public static void main(String args[]) {
        Client client = new Client("127.0.0.1", 4000);
    }
}