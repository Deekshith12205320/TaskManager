import java.sql.*;
import java.util.Scanner;

public class TaskManager {
    public static void main(String[] args) {
        String url = "jdbc:mysql://localhost:3306/tasks";
        String user = "root"; // Your MySQL username
        String pass = "";    // Your MySQL password
        Scanner sc = new Scanner(System.in);

        try (Connection con = DriverManager.getConnection(url, user, pass)) {
            while (true) {
                System.out.println("1. Add Task  2. List Tasks  3. Exit");
                int choice = sc.nextInt();
                sc.nextLine(); // Clear buffer

                if (choice == 1) {
                    System.out.print("Enter ID: ");
                    int id = sc.nextInt();
                    sc.nextLine();
                    System.out.print("Enter Title: ");
                    String title = sc.nextLine();
                    String sql = "INSERT INTO tasks (id, title) VALUES (?, ?)";
                    PreparedStatement ps = con.prepareStatement(sql);
                    ps.setInt(1, id);
                    ps.setString(2, title);
                    ps.executeUpdate();
                    System.out.println("Task added!");
                } else if (choice == 2) {
                    String sql = "SELECT * FROM tasks";
                    Statement st = con.createStatement();
                    ResultSet rs = st.executeQuery(sql);
                    while (rs.next()) {
                        System.out.println("ID: " + rs.getInt("id") + ", Title: " + rs.getString("title"));
                    }
                } else if (choice == 3) {
                    break;
                }
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}