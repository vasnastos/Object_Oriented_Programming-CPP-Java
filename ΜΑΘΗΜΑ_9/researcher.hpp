#include "paper.hpp"
class researcher
{
   std::string name;
   std::string affilation;
   std::vector <paper> papers;
   public:
     researcher(std::string name,std::string affilation);
     std::string get_affilation();
     std::vector <paper> get_papers();
     void add_paper(paper &a_paper);
     void display_info();
};