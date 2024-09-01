#ifndef IDATABASE_H
#define IDATABASE_H

#include <string>

class IDatabase {
public:
    virtual int set_attr(const std::string& key, const std::string& attr, int val) = 0;
    virtual bool delete_attr(const std::string& key, const std::string& attr) = 0;
    virtual int get_attr(const std::string& key, const std::string& attr) = 0;
};

#endif /* IDATABASE_H */