#include "src/todolist.hpp"
#include <iostream>
#include <string>
#include <limits>

//NOTE: Add-ons 1 & 2 are implemented to improve code
int main() {
    TodoList list;
    std::string input;
    int choice = 0;

    std::cout << "=== Simple To-Do List ===\n";

    while (true) {
        std::cout << "\n1. Add Task\n";
        std::cout << "2. Mark Task Complete\n";
        std::cout << "3. Show All Tasks\n";
        std::cout << "4. Show Completed Tasks\n";
        std::cout << "5. Show Incomplete Tasks\n";
        std::cout << "6. Clear List\n";
        std::cout << "7. Exit\n";
        std::cout << "Choose an option: ";

        // Get line input as a string, then check if it’s a valid number
        std::string choiceStr;
        std::getline(std::cin, choiceStr);

        // Check that input is a single digit 1–7
        if (choiceStr.size() != 1 || choiceStr[0] < '1' || choiceStr[0] > '7') {
            std::cout << "Invalid choice, please enter a number between 1 and 7.\n";
            continue;
        }

        // Convert to integer
        choice = choiceStr[0] - '0';

        if (choice == 1) {
            std::cout << "Enter task name: ";
            std::getline(std::cin, input);
            list.add(input);
        }
        else if (choice == 2) {
            std::cout << "Enter task name to complete: ";
            std::getline(std::cin, input);
            list.complete(input);
        }
        else if (choice == 3) {
            list.all();
        }
        else if (choice == 4) {
            list.completeTasks();
        }
        else if (choice == 5) {
            list.incompleteTasks();
        }
        else if (choice == 6) {
            list.clear();
        }
        else if (choice == 7) {
            std::cout << "Goodbye!\n";
            break;
        }
    }

    return 0;
}