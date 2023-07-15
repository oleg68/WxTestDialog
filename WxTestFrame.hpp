#ifndef WXTESTFRAME_HPP
#define WXTESTFRAME_HPP

#include <wx/frame.h>

class WxTestFrame: public wxFrame
{
private:
  
public:
  WxTestFrame();

private:
  void OnCreate(wxWindowCreateEvent &);
  void OnShow(wxShowEvent &);
  void OnClose(wxCloseEvent &);
  void OnDestroy(wxWindowDestroyEvent &);
  
  void OnExit(wxCommandEvent& event);
  void OnModal(wxCommandEvent& event);
  void OnModalless(wxCommandEvent& event);

  DECLARE_EVENT_TABLE()
};

#endif /* WXTESTFRAME_HPP */
