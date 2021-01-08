#include "matrix.hpp"
#include <thread>

class Surfer:public matrix{
    private:
       bool difference();
    public:  
      Surfer(int a);
      ~Surfer();
      std::string Random_Surfing(int visitors);
};