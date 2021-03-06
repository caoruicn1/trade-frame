/************************************************************************
 * Copyright(c) 2011, One Unified. All rights reserved.                 *
 *                                                                      *
 * This file is provided as is WITHOUT ANY WARRANTY                     *
 *  without even the implied warranty of                                *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                *
 *                                                                      *
 * This software may not be used nor distributed without proper license *
 * agreement.                                                           *
 *                                                                      *
 * See the file LICENSE.txt for redistribution information.             *
 ************************************************************************/

#pragma once

#include <wx/dataview.h>

namespace ou { // One Unified
namespace tf { // TradeFrame

class VuBase: public wxDataViewCtrl {
public:
  VuBase(void);
  VuBase(wxWindow *parent, wxWindowID id, 
    const wxPoint &pos=wxDefaultPosition, const wxSize &size=wxDefaultSize, 
    long style=0, const wxValidator &validator=wxDefaultValidator);
  ~VuBase(void);

protected:

  struct structPopulateColumns {
    void operator()( const std::string& s ) {
      // will a wxObjectDataPtr<> be required here for leak prevention
      wxDataViewColumn* col = new wxDataViewColumn( s, new wxDataViewTextRenderer(), ixColumn++ );
      pdvc->AppendColumn( col );
    }
    explicit structPopulateColumns( wxDataViewCtrl* pdvc_ ): pdvc( pdvc_ ), ixColumn( 0 ) {
    }
    wxDataViewCtrl* pdvc;
    unsigned int ixColumn;
  };

private:

};

} // namespace tf
} // namespace ou
