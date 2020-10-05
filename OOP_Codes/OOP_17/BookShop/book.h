#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <QString>

class Book
{
private:
    std::string author;
    std::string title;
    double price;
public:
    Book(std::string a,std::string t,double pr);
    std::string get_author()const;
    std::string get_title()const;
    double get_price()const;
    QString get_author_qt();
    QString get_title_qt();
};
#endif // BOOK_H
