#pragma once
#include <string>
using std::string;
class Weapon
{
private:
    static int magic;
    string name;
    int level;
    static void print_magic();

protected:
    string get_name() const;
    int get_level() const;
    void upgrade();

public:
    static void set_magic(int _magic);
    ~Weapon();
    Weapon(string name);
};
