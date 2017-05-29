//
// Created by GentlyGuitar on 5/23/2017.
//

#ifndef MINISPOT_OSTREAM_H
#define MINISPOT_OSTREAM_H

#include <fstream>
#include <vector>

class Strings {
public:
    static std::vector<std::string> split(const std::string &s, char delim);
};

class Loggers {
public:
    static bool init();


    static std::ofstream todo;
    static std::string todo_path;
};


#endif //MINISPOT_OSTREAM_H
