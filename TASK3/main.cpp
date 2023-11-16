#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct Task {
    string description;
    bool completed;
};


void addTask(vector<Task>& tasks, const string& description) {
    Task newTask = {description, false};
    tasks.push_back(newTask);
    cout << "Task added: " << description << endl;
}

// Function to view all tasks
void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks in the list." << endl;
    } else {
        cout << "Tasks in the list:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description;
            if (tasks[i].completed) {
                cout << " - Completed";
            } else {
                cout << " - Pending";
            }
            cout << endl;
        }
    }
}

// Function to mark a task as completed
void markTaskCompleted(vector<Task>& tasks, size_t index) {
    if (index >= 0 && index < tasks.size()) {
        tasks[index].completed = true;
        cout << "Task marked as completed: " << tasks[index].description << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}


void removeTask(vector<Task>& tasks, size_t index) {
    if (index >= 0 && index < tasks.size()) {
        cout << "Task removed: " << tasks[index].description << endl;
        tasks.erase(tasks.begin() + index);
    } else {
        cout << "Invalid task index." << endl;
    }
}

int main() {
    vector<Task> tasks;

    while (true) {
        cout << "\n List Manager" << endl;
        cout << "1. Add Task\n2. View Tasks\n3. Mark Task as Completed Task\n4. Delete Task\n5. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string taskDescription;
                cout << "Enter the task description: ";
                cin.ignore();
                getline(cin, taskDescription);
                addTask(tasks, taskDescription);
                break;
            }
            case 2:
                viewTasks(tasks);
                break;
            case 3: {
                size_t taskIndex;
                cout << "Enter the task number to mark as completed: ";
                cin >> taskIndex;
                markTaskCompleted(tasks, taskIndex - 1);
                break;
            }
            case 4: {
                size_t taskIndex;
                cout << "Enter the task number to remove: ";
                cin >> taskIndex;
                removeTask(tasks, taskIndex - 1);
                break;
            }
            case 5:
                cout << "Exiting the List Manager" << endl;
                return 0;
            default:
                cout << "Invalid choice.Try again" << endl;
        }
    }

    return 0;
}
