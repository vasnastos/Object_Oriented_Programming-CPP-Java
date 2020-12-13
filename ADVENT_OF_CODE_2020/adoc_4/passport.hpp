#include <iostream>
#include <string>
#include <map>

class passport
{
    std::map <std::string,std::string> checksums;
    std::string codes[8]={"byr","iyr","eyr","hgt","hcl","ecl","pid","cid"};
    public:
      passport();
      ~passport() {}
      void add_data(std::string id,std::string value);
      bool validance();
      bool present();
      friend std::ostream &operator<<(std::ostream &os,const passport &p);
};