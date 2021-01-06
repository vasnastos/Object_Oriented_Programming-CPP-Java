#include "matrix.hpp"
#include <thread>

class Surfer:public matrix{
    private:
       bool difference();
    public:  
      static double lastdifference;
      Surfer(int a);
      ~Surfer();
      void Random_Surfing(int visitors);
};