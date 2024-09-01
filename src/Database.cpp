#include "Database.hpp"
#include <string>
#include <unordered_map>

int Database::set_attr(const std::string& key, const std::string& attr, int val){
    if (m.find(key) == m.end()){
        std::unordered_map<std::string, int> inner;
        inner[attr] = val;
        m[key] = std::move(inner); // CHECK (does it call copy constructor or move constructor)
    } else if (m[key].find(attr) == m[key].end()){
        m[key][attr] = val;
    } else {
        m[key][attr] += val;
    }
    return m[key][attr];
}

// If key exists and attr exists, delete
// Return true if delete operation carried out successfully
bool Database::delete_attr(const std::string& key, const std::string& attr){
    if (m.find(key) == m.end()) return false;
    if (m[key].find(attr) == m[key].end()) return false;
    m[key].erase(attr);
    if (m[key].empty()) m.erase(key);
    return true;
}

int Database::get_attr(const std::string& key, const std::string& attr){
    if (m.find(key) == m.end()) return -1;
    if (m[key].find(attr) == m[key].end()) return -1;
    return m[key][attr];
}

void Database::clear(){
    m.clear();
    stats.clear();
}
