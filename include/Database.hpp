#ifndef DATABASE_H
#define DATABASE_H

#include <unordered_map>
#include <string>
#include "IDatabase.hpp"

class Database: public IDatabase {
public:
    std::unordered_map<std::string, std::unordered_map<std::string, int> > m; // maps key to (attr, value) pairs
    std::unordered_map<std::string, int> stats; // maps key to how much operation changed

    int set_attr(const std::string& key, const std::string& attr, int val);

    // If key exists and attr exists, delete
    // Return true if delete operation carried out successfully
    bool delete_attr(const std::string& key, const std::string& attr);

    int get_attr(const std::string& key, const std::string& attr);

    void clear();
};

#endif // DATABASE_H
