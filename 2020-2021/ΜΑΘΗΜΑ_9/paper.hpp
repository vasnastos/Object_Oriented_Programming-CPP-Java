#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <random>
#include "researcher.hpp"

class paper
{
    std::string title;
    std::string journal;
    std::vector <researcher> authors;
    public:
      paper(std::string title,std::string journal);
      std::string getTitle();
      std::vector <researcher> get_authors()const;
      void add_author(researcher &author);
      void info();
};