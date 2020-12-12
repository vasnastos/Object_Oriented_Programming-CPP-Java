/*
    Unit Test Catch Library
    Test's for program error check.
*/
#define CATCH_CONFIG_MAIN
#include <iostream>
#include "catch.hpp"
#include <stack>

class mathematic
{
   int number;
   public:
     mathematic(int n):number(n) {}
     int getnumber() {return number;}
     int square() {return number*number;}
     size_t paragontical()
     {
         size_t pr=1;
         for(int i=1;i<=number;i++)
         {
             pr*=i;
         }
         return pr;
     } 
     char to_char()
     {
         return 'A'+number;
     }
     void setnumber(int k) {number=k;}

     std::string to_binary()
     {
         int num=number;
        std::stack <char> digits;
        while(num!=0)
        {
            digits.push('0'+(num%2));
            num/=2;
        }
        std::string bin="";
        while(!digits.empty())
        {
            bin+=digits.top();
            digits.pop();
        }
        return bin;
     }
     int count_First_Numbers()
     {
         int cnt=0;
         for(int i=2;i<number;i++)
         {
             int count=2;
             for(int j=2;j<=number/2;j++)
             {
                 if(i==j) continue;
                 if(i%j==0)
                 {
                     count++;
                 }
             }
             if(count==2)
             {
                 cnt++;
             }
         }
         return cnt;
     }
};

TEST_CASE("square_test","[mathematic]")
{
    mathematic *m=new mathematic(6);
    REQUIRE(m->square()==36);
    m->setnumber(4);
    REQUIRE(m->getnumber()==4);
    REQUIRE(m->square()==16);
    delete m;
}

TEST_CASE("paragontical_test","[mathematic]")
{
    mathematic *m=new mathematic(6);
    REQUIRE(m->paragontical()==720);
    m->setnumber(4);
    REQUIRE(m->getnumber()==4);
    REQUIRE(m->paragontical()==24);
    delete m;
}

TEST_CASE("to_char test","[mathematic]")
{
    mathematic *m=new mathematic(6);
    REQUIRE(m->to_char()=='G');
    m->setnumber(4);
    REQUIRE(m->getnumber()==4);
    REQUIRE(m->to_char()=='E');
    delete m;
}

TEST_CASE("To-binary","[mathematic]")
{
    mathematic *m=new mathematic(6);
    REQUIRE(m->to_binary()=="110");
    m->setnumber(12);
    REQUIRE(m->getnumber()==12);
    REQUIRE_FALSE(m->to_binary()=="00110");
    REQUIRE(m->to_binary()=="1100");
    REQUIRE(m->square()==144);
    delete m;
}

TEST_CASE("First Numbers","[mathematic]")
{
    mathematic *m=new mathematic(10);
    REQUIRE(m->square()==100);
    REQUIRE(m->count_First_Numbers()==4);
    m->setnumber(20);
    REQUIRE(m->count_First_Numbers()==8);
    REQUIRE(m->getnumber()==20);
}