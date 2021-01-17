#include <wx/wx.h>
#include <fstream>
#include "../Surfer.hpp"

class Frame:public wxFrame
{
    private:
      Surfer *s;
      ~Frame();
      wxTextCtrl *visitors,*pages,*damping_factor,*results;
      wxBoxSizer *gs;
      void panel1();
      void panel2();
      void panel3();
      void panel4();
      void make_menu();
    public:
      Frame();
      void Export(wxCommandEvent &ev);
      void Close(wxCommandEvent &ev);
      void surfing(wxCommandEvent &ev);
      void ranking(wxCommandEvent &ev);
};