#include <iostream>
#include <fstream>
#include <algorithm>
template <class T>
class filenums
{
    std::string filename;
    std::vector <T> numbers;
    public: 
     filenums(std::string fn):filename(fn) {}
     void fill_Vector()
     {
         std::fstream fs;
         fs.open(this->filename,std::ios::in);
         std::string line;
         while(std::getline(fs,line))
         {
             numbers.push_back(std::stoi(line));
         }
         fs.close();
     }
     std::string getFileName() {return this->filename;}
     T getMaxNumber()
     {
       return *std::max_element(this->numbers.begin(),this->numbers.end());
     }
};

int main()
{
    filenums <int> file1("integers.txt");
    filenums <double> file2("floats.txt");
    file1.fill_Vector();
    file2.fill_Vector();
    std::cout<<file1.getFileName()<<"-"<<file1.getMaxNumber()<<std::endl;
    std::cout<<file2.getFileName()<<"-"<<file2.getMaxNumber()<<std::endl;
    return 0;
}