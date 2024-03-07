#pragma once
#include <exception>
#include <string>
using namespace std;

class SongException : public std::exception {
public:
    virtual const char* what() const noexcept {
        return message.c_str();
    }
    SongException(const string& m) : message{ m } {}

private:
    string message;
};

