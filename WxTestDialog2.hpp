#ifndef WXTESTDIALOG2_HPP
#define WXTESTDIALOG2_HPP

#include <wx/panel.h>
#include <wx/string.h>

#include "GOTabbedDialog.h"

class wxTreeCtrl;

class WxTestDialog2 : public GOTabbedDialog {
private:

  class Page1 : public wxPanel {
  private:
    wxTreeCtrl *m_Tmp;
    wxTreeCtrl *m_AudioOutput;

  public:
    Page1(wxWindow *parent);


    virtual bool TransferDataToWindow() override;
  };

  class Page2 : public wxPanel {
  public:
    Page2(wxWindow *parent);
  };

  Page1* m_page1;
  Page2* m_page2;

public:
  WxTestDialog2(wxWindow *parent, const wxString &title);
  virtual ~WxTestDialog2();
};

#endif /* WXTESTDIALOG2_HPP */

