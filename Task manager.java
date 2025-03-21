import java.util.Scanner;

public class TaskManager {
    static class Task {
        int id;
        String title;
        boolean isUsed; 

        Task() {
            id = 0;
            title = "";
            isUsed = false;
        }
    }

    public static void main(String[] args) {
        Task[] tasks = new Task[10]; 
        for (int i = 0; i < tasks.length; i++) {
            tasks[i] = new Task(); 
        }
        Scanner scanner = new Scanner(System.in);
        int taskCount = 0; 

        while (true) {
            System.out.println("1. Add Task  2. List Tasks  3. Exit");
            int choice = scanner.nextInt();
            scanner.nextLine(); // Clear buffer

            if (choice == 1) {
                if (taskCount < tasks.length) {
                    System.out.print("Enter ID: ");
                    int id = scanner.nextInt();
                    scanner.nextLine();
                    System.out.print("Enter Title: ");
                    String title = scanner.nextLine();

                    tasks[taskCount].id = id;
                    tasks[taskCount].title = title;
                    tasks[taskCount].isUsed = true;
                    taskCount++;
                    System.out.println("Task added!");
                } else {
                    System.out.println("Task list is full!");
                }
            } else if (choice == 2) {
                if (taskCount == 0) {
                    System.out.println("No tasks found.");
                } else {
                    for (int i = 0; i < taskCount; i++) {
                        System.out.println("ID: " + tasks[i].id + ", Title: " + tasks[i].title);
                    }
                }
            } else if (choice == 3) {
                System.out.println("Exiting...");
                break;
            }
        }
        scanner.close();
    }
}
