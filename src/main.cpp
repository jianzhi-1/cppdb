#include <iostream>
#include "Database.hpp"

void test_suite_1(){
    Database db;
    db.set_attr("a", "a", 98);
    assert(db.get_attr("a", "a") == 98);

    db.set_attr("a", "b", 2);
    assert(db.get_attr("a", "b") == 2);

    db.set_attr("a", "a", 100);
    assert(db.get_attr("a", "a") == 198);

    db.delete_attr("a", "a");
    db.set_attr("a", "a", 10);
    assert(db.get_attr("a", "a") == 10);
}

int main() {
    test_suite_1();
    std::cout << "PASSED test suite 1" << '\n';
}