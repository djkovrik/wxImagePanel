#include "imagepanel.h"

wxImagePanel::wxImagePanel(wxString file, wxBitmapType format, wxWindow* parent,
                 wxWindowID id, const wxPoint &pos, const wxSize &size, long style,
                 const wxString &name) :
    wxPanel(parent, id, pos, size, style, name) {

    image.LoadFile(file, format);

    Bind(wxEVT_PAINT, &wxImagePanel::paintNow, this);
}

wxImagePanel::wxImagePanel(const wxImage &src, wxWindow* parent,
                 wxWindowID id, const wxPoint &pos, const wxSize &size, long style,
                 const wxString &name) :
    wxPanel(parent, id, pos, size, style, name), image(src) {

    Bind(wxEVT_PAINT, &wxImagePanel::paintNow, this);
}

void wxImagePanel::paintNow(wxPaintEvent& evt) {

    wxClientDC dc(this);
    render(dc);
    evt.Skip();
}

void wxImagePanel::render(wxDC&  dc) {
    dc.DrawBitmap( image, 0, 0, false );
}
