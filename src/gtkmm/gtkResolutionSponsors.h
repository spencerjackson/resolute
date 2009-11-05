/* File: gtkResolutionSponsors.h
Copyright 2009 Spencer Jackson

This file is part of Resolute
is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Resolute is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Resolute.  If not, see <http://www.gnu.org/licenses/>.*/

#ifndef GTKRESOLUTIONSPONSORS_H
#define GTKRESOLUTIONSPONSORS_H

#include <gtkmm/frame.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/treeview.h>

#include "sponsorModel.h"

class GtkResolutionSponsors : public Gtk::Frame {
public:
  GtkResolutionSponsors();
  ~GtkResolutionSponsors();
  Gtk::ScrolledWindow m_scrolledwindow;
  Glib::RefPtr<SponsorModel> m_refModel;
  Gtk::TreeView m_view;
};

#endif //GTKRESOLUTIONSPONSORS_H
