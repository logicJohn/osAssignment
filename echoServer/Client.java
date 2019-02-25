// Johnnie Hernandez & Malik Hill
//  CSCI 3000

//Program sends "Hello there!" to server, where server responds with "Hello there!"
import java.net.*;
import java.io.*;

public class Client {
    // initialize socket and streams
    private Socket socket = null;
    private DataInputStream input = null;
    private DataOutputStream out = null;
    private DataInputStream in = null;

    // construct ip:port
    public Client(String address, int port) {
        // open connection
        try {
            socket = new Socket(address, port);
            System.out.println("Socket open");

            // takes input from terminal
            input = new DataInputStream(System.in);

            // sends output to the socket
            in = new DataInputStream(new BufferedInputStream(socket.getInputStream()));
            out = new DataOutputStream(socket.getOutputStream());

        } catch (UnknownHostException u) {
            System.out.println(u);
        } catch (IOException i) {
            System.out.println(i);
        }

        // temp storage for read
        String temp = "";

        // keep reading until "-1" is input
        while (!temp.equals(".exit")) {
            try {
                temp = input.readLine();
                out.writeUTF(temp);
            } catch (IOException i) {
                System.out.println(i);
            }
            try {
                temp = in.readUTF();
                System.out.println(temp);
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