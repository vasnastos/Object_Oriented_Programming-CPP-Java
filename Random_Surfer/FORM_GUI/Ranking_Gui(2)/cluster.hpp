#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <sstream>
#include <string>

struct info
{
    int number_of_pages;
    double Damping_factor;
    double max_grade;
    bool operator<(const info &in)const {return this->Damping_factor<in.Damping_factor;}
    std::string print()const {return std::to_string(this->number_of_pages)+","+std::to_string(this->Damping_factor)+","+std::to_string(this->max_grade);}
};

class cluster
{
    public:
       static std::string filename;
       static void Cluster(const std::string &filepath)
       {
           cluster::filename=filepath;
           std::fstream fs;
           fs.open(cluster::filename,std::ios::in);
           std::string line,word;
           std::vector <std::string> data;
           std::priority_queue <info> retrived_data;
           std::vector <std::string> clusterred;
           while(std::getline(fs,line))
           {
               data.clear();
              std::istringstream iss(line);
              while(std::getline(iss,word,','))
              {
                 data.push_back(word);
              }
              retrived_data.push(info{std::stoi(data[0]),std::stod(data[1]),std::stod(data[2])});
           }
           fs.close();
           while(!retrived_data.empty())
           {
               clusterred.push_back(retrived_data.top().print());
               retrived_data.pop();
           }
           fs.open(cluster::filename,std::ios::out);
           for(auto &x:clusterred)
           {
               fs<<x<<std::endl;
           }
           fs.close();
           std::cout<<"File Modified:"<<cluster::filename<<std::endl;
       }
};