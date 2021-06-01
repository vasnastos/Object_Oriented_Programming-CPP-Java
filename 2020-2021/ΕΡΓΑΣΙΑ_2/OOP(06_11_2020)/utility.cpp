#define CATCH_CONFIG_MAIN
#include <iostream>
#include <utility>
#include "catch.hpp"

using namespace std;
using namespace std::rel_ops;

class book
{
private:
    string author;
    string title;
    double price;

public:
    //constructor που θα αρχικοποιεί τα δεδομένα με τιμες που θα δέχεται ως ορίσματα
    book(string a = "", string t = "", double p = 0.0) : author(a), title(t), price(p) {}
    ~book() {}
    string get_author()const {return this->author;}
    string get_title()const {return this->title;}
    double get_price()const {return this->price;}
    //υπερφορτώστε τον τελεστή < με βάση την τιμή των βιβλίων
    bool operator<(const book &b) const
    {
        return this->price < b.price;
    }
    bool operator==(const book &b) const
    {
        //return this->author==b.author && this->title==b.title && this->price==b.price;
        return this->price == b.price;
    }
    //<< εμφάνιση όλων των δεδομένων
    friend ostream &operator<<(ostream &os, const book &b);
};

ostream &operator<<(ostream &os, const book &b)
{
    os << b.author << " " << b.title << " " << b.price;
    return os;
}

TEST_CASE("book_test","test getters")
{
   book testbook("author1","title1",50.0);
   REQUIRE(testbook.get_author()=="author1");
   REQUIRE(testbook.get_title()=="title1");
   REQUIRE(testbook.get_price()==50.0);
}

TEST_CASE("book_test_1","Test an operator")
{
   //Σύγκριση του τελεστή <
   book b1("author1","book1",50.0);
   book b2("author2","book2",60.0);
   REQUIRE(b1<b2);
  //REQUIRE(b1!=b2);
   REQUIRE(b2>b1);
   book b3("author3","title3",70.0);
   REQUIRE(b3>b2);
   REQUIRE(b3<b2);
   REQUIRE_FALSE(b2==b3);
}

/*int main()
{
    book nb();
    book nb1("book_1", "title_1", 78.9);
    book bk("", "");
    book b{"", "", 0.0};
    if (nb1 < b && nb1 > bk)
    {
        cout << "Lower" << endl;
    }
    else
    {
        cout << "Upper or same" << endl;
    }
}*/