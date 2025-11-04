#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/todolist.hpp"

//NOTE: Add-ons 1 & 2 are implemented to improve code
// Z — Zero
TEST_CASE("Zero: Empty TodoList has no tasks") {
    TodoList list;
    REQUIRE(list.allList().empty());
    REQUIRE(list.completeList().empty());
    REQUIRE(list.incompleteList().empty());
}

// O — One
TEST_CASE("One: Add a single task and mark it complete") {
    TodoList list;
    list.add("Buy milk");
    list.complete("Buy milk");
    REQUIRE(list.completeList().size() == 1);
    REQUIRE(list.incompleteList().empty());
}

// M — Many
TEST_CASE("Many: Add multiple tasks and mark some complete") {
    TodoList list;
    list.add("Task 1");
    list.add("Task 2");
    list.add("Task 3");
    list.complete("Task 2");

    REQUIRE(list.allList().size() == 3);
    REQUIRE(list.completeList().size() == 1);
    REQUIRE(list.incompleteList().size() == 2);
}

// B — Boundaries
TEST_CASE("Boundaries: Reject duplicate incomplete tasks") {
    TodoList list;
    list.add("Clean room");
    list.add("Clean room"); // rejected
    REQUIRE(list.allList().size() == 1);
}

TEST_CASE("Boundaries: Allow duplicate completed task") {
    TodoList list;
    list.add("Wash dishes");
    list.complete("Wash dishes");
    list.add("Wash dishes"); // allowed
    REQUIRE(list.allList().size() == 2);
}

// I — Interface
TEST_CASE("Interface: Can re-add task after completion") {
    TodoList list;
    list.add("Do homework");
    list.complete("Do homework");
    list.add("Do homework");
    REQUIRE(list.allList().size() == 2);
}

// E — Exceptions
TEST_CASE("Exceptions: Empty task name is handled") {
    TodoList list;
    list.add("");
    REQUIRE(list.allList().empty());
}

// S — Simple
TEST_CASE("Simple: Clear removes all tasks") {
    TodoList list;
    list.add("Task A");
    list.add("Task B");
    list.clear();
    REQUIRE(list.allList().empty());
}
