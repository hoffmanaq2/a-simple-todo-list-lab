#pragma once
#include <string>
#include <vector>

//NOTE: Add-ons 1 & 2 are implemented to improve code
class TodoList {
private:
    struct Task {
        std::string name;
        bool done;
    };

    std::vector<Task> tasks;

public:
    void add(const std::string& taskName);
    void complete(const std::string& taskName);
    void all() const;
    void completeTasks() const;
    void incompleteTasks() const;
    void clear();

    //Getter methods for testing
    std::vector<std::string> allList() const;
    std::vector<std::string> completeList() const;
    std::vector<std::string> incompleteList() const;
};

