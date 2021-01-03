#include "Matrix.hpp"

struct navigate
{
    int id;
    std::string from;
    std::string to;
};

class Surfer:public matrix
{
    private:
      int go_to(int r);
    public:
        static std::string info;
        Surfer();
        Surfer(int rows,int columns);
        ~Surfer();
        std::vector <navigate> random_surfer(int visitors,int iterations);
        static std::priority_queue <grank> Page_rank();
};

