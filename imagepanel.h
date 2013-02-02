// Panel for drawing an image, make an image component
// or paint on the background of a panel.
// Source: wxWiki

#ifndef IMAGEPANEL_H_INCLUDED
#define IMAGEPANEL_H_INCLUDED

#include <wx/bitmap.h>
#include <wx/panel.h>
#include <wx/dcclient.h>

class wxImagePanel : public wxPanel {
public:
    wxImagePanel(wxString file, wxBitmapType format, wxWindow* parent,
                 wxWindowID id=wxID_ANY, const wxPoint &pos=wxDefaultPosition,
                 const wxSize &size=wxDefaultSize, long style=wxTAB_TRAVERSAL,
                 const wxString &name=wxPanelNameStr);

    wxImagePanel(const wxImage &src, wxWindow* parent,
                 wxWindowID id=wxID_ANY, const wxPoint &pos=wxDefaultPosition,
                 const wxSize &size=wxDefaultSize, long style=wxTAB_TRAVERSAL,
                 const wxString &name=wxPanelNameStr);

    void paintNow(wxPaintEvent& evt);
    void render(wxDC& dc);
private:
    wxBitmap    image;
};



#endif // IMAGEPANEL_H_INCLUDED
