#pragma once
class SmithingStone
{
private:
    static int magic;
    int level, number;
    static void print_magic();

protected:
    void add_amount(int amount);
    bool greater_equal(int need) const;
    int get_level() const;

public:
    SmithingStone(int level);
    ~SmithingStone();
    static void set_magic(int _magic);
};
