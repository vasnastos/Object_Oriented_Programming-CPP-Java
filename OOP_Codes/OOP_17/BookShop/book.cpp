#include "book.h"

Book::Book(std::string a,std::string t,double pr):author(a),title(t),price(pr) {}
std::string Book::get_author()const {return this->author;}
std::string Book::get_title()const {return this->title;}
double Book::get_price()const {return this->price;}
QString Book::get_author_qt()
{
    QString auth="";
    int size=author.length();
    for(int i=0;i<size;i++)
    {
        auth+=author.at(i);
    }
    return auth;
}

QString Book::get_title_qt()
{
    QString tit="";
    int size=title.length();
    for(int i=0;i<size;i++)
    {
        tit+=title.at(i);
    }
    return tit;
}
