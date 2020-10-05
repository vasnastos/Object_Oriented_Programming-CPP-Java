#ifndef CARGO_H
#define CARGO_H
#include <QString>

class cargo
{
private:
    int id;
    QString dest;
    double weight;
    double price;
public:
    cargo(int i,QString d,double w,double p);
    int get_id();
    QString get_destination();
    double get_weight();
    double get_price();
    QString to_String();
};

#endif // CARGO_H
