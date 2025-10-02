import java.io.*;
import java.net.*;
import java.util.*;

public class ChatServer {
    private static Set<Socket> clients = Collections.synchronizedSet(new HashSet<>());

    public static void main(String[] args) throws IOException {
        ServerSocket server = new ServerSocket(5000);
        System.out.println("Chat server started...");
        while (true) {
            Socket client = server.accept();
            clients.add(client);
            new Thread(() -> handleClient(client)).start();
        }
    }

    private static void handleClient(Socket socket) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(socket.getInputStream()))) {
            String msg;
            while ((msg = br.readLine()) != null) {
                broadcast(msg, socket);
            }
        } catch (IOException e) { e.printStackTrace(); }
    }

    private static void broadcast(String msg, Socket sender) {
        clients.forEach(client -> {
            if (client != sender) {
                try {
                    new PrintWriter(client.getOutputStream(), true).println(msg);
                } catch (IOException ignored) {}
            }
        });
    }
}
