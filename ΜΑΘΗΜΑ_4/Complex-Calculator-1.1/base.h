#include <wx/wx.h>
#include <iostream>
#include <vector>
#include <string>
#include <complex>

class Frame:public wxFrame
{
   private:
     wxTextCtrl *input1,*input2,*input3,*input4,*result;
     wxComboBox *operations;
     wxButton *cal;
     wxGridSizer *mainsizer;
     void panel1();
     void panel2();
     void panel3();  
   public:
     Frame();
     void calculate(wxCommandEvent &WXUNUSED(ev));
};