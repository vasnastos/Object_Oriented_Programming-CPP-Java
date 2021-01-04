#include "matrix.hpp"
#include <thread>

class Surfer:public matrix{
    private:
       bool difference();
    public:
      static std::string info;  
      Surfer(int a);
      ~Surfer();
      void Random_Surfing(int visitors);
      void save_to_file();
};