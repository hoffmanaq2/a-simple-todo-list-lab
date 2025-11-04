#include "todolist.hpp"
#include <iostream>

//NOTE: Add-ons 1 & 2 are implemented to improve code
#include <iostream>

void TodoList::add(const std::string& taskName) {
    if (taskName.empty()) {
        std::cout << "Task name cannot be empty.\n";
        return;
    }

    // Check for duplicates among incomplete tasks
    for (int i = 0; i < (int)tasks.size(); i++) {
        if (tasks[i].name == taskName && tasks[i].done == false) {
            std::cout << "Task \"" << taskName << "\" already exists and is incomplete.\n";
            return;
        }
    }

    Task t;
    t.name = taskName;
    t.done = false;
    tasks.push_back(t);
    std::cout << "Added task: " << taskName << "\n";
}

void TodoList::complete(const std::string& taskName) {
    bool found = false;
    for (int i = 0; i < (int)tasks.size(); i++) {
        if (tasks[i].name == taskName) {
            tasks[i].done = true;
            found = true;
            std::cout << "Marked as complete: " << taskName << "\n";
            break;
        }
    }
    if (!found) {
        std::cout << "Task not found: " << taskName << "\n";
    }
}

void TodoList::all() const {
    if (tasks.empty()) {
        std::cout << "The to-do list is empty.\n";
        return;
    }
    std::cout << "All Tasks:\n";
    for (int i = 0; i < (int)tasks.size(); i++) {
        std::cout << " - " << tasks[i].name;
        if (tasks[i].done)
            std::cout << " [Done]";
        else
            std::cout << " [Not Done]";
        std::cout << "\n";
    }
}

void TodoList::completeTasks() const {
    bool any = false;
    std::cout << "Completed Tasks:\n";
    for (int i = 0; i < (int)tasks.size(); i++) {
        if (tasks[i].done) {
            std::cout << " - " << tasks[i].name << "\n";
            any = true;
        }
    }
    if (!any) {
        std::cout << "(none)\n";
    }
}

void TodoList::incompleteTasks() const {
    bool any = false;
    std::cout << "Incomplete Tasks:\n";
    for (int i = 0; i < (int)tasks.size(); i++) {
        if (!tasks[i].done) {
            std::cout << " - " << tasks[i].name << "\n";
            any = true;
        }
    }
    if (!any) {
        std::cout << "(none)\n";
    }
}

void TodoList::clear() {
    tasks.clear();
    std::cout << "All tasks cleared.\n";
}

std::vector<std::string> TodoList::allList() const {
    std::vector<std::string> result;
    for (int i = 0; i < (int)tasks.size(); i++) {
        result.push_back(tasks[i].name);
    }
    return result;
}

std::vector<std::string> TodoList::completeList() const {
    std::vector<std::string> result;
    for (int i = 0; i < (int)tasks.size(); i++) {
        if (tasks[i].done)
            result.push_back(tasks[i].name);
    }
    return result;
}

std::vector<std::string> TodoList::incompleteList() const {
    std::vector<std::string> result;
    for (int i = 0; i < (int)tasks.size(); i++) {
        if (!tasks[i].done)
            result.push_back(tasks[i].name);
    }
    return result;
}