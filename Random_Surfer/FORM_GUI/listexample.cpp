// Example uses fictive class "Item" and fictive getters to access them. Adapt for your needs
#include "wx/wx.h"
#include <wx/listctrl.h>
class MyFrame : public wxFrame
{
    wxListCtrl* m_item_list;

public:
    MyFrame() : wxFrame(NULL, wxID_ANY,"LIST EXAMPLE")
    {
        this->SetSize(400,400);
        wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
        
        m_item_list = new wxListCtrl(this, wxTEXT_ALIGNMENT_CENTER,wxDefaultPosition,wxSize(200,200),wxLC_REPORT);
        // Add first column       
        wxListItem col0;
        col0.SetId(0);
        col0.SetText( _("Foo") );
        col0.SetWidth(50);
        m_item_list->InsertColumn(0, col0);
        
        // Add second column
        wxListItem col1;
        col1.SetId(1);
        col1.SetText( _("Name") );
        col1.SetWidth(50);
        m_item_list->InsertColumn(1, col1);
        
        // Add third column     
        wxListItem col2;
        col2.SetId(2);
        col2.SetWidth(50);
        col2.SetText( _("Comments") );
        m_item_list->InsertColumn(2, col2);
        
        
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                wxListItem it;
                it.SetId(i+j);
                it.SetText(_(""));
                m_item_list->InsertItem(it);
            }
        }
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                m_item_list->SetItem(i,j,"row"+std::to_string(j+1));
            }
        }
        sizer->Add(m_item_list);
        this->SetSizer(sizer);
    }
};
class MyApp: public wxApp
{
    wxFrame* m_frame;
public:
    
    bool OnInit()
    {
        m_frame = new MyFrame();
        m_frame->Show();
        return true;
    } 
    
};

IMPLEMENT_APP(MyApp)