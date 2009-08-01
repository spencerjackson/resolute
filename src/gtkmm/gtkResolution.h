/* File: gtkResolution.h
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

#ifndef GTKRESOLUTION_H
#define GTKRESOLUTION_H

#include <gtkmm/box.h>
#include <gtkmm/entry.h>
#include <gtkmm/label.h>
#include <gtkmm/frame.h>
#include <gtkmm/scrolledwindow.h>
#include <glibmm/refptr.h>
#include <gtkmm/liststore.h>
#include <gtkmm/treestore.h>
#include <gtkmm/treeview.h>

#include "modelColumns.h"

#include "../resolution.h"

class GtkResolution : public Gtk::VBox {
public:
  GtkResolution();
  GtkResolution(Resolution* resolution);
  ~GtkResolution();
  void init();
protected:
  Gtk::HBox m_header_box;
  Gtk::Label m_title_label;
  Gtk::Entry m_title;
  Gtk::Label m_submitter_label;
  Gtk::Entry m_submitter_entry;
  Gtk::ScrolledWindow m_sponsor_scrolledwindow;
  Glib::RefPtr<Gtk::ListStore> m_refSponsorsModel;
  Gtk::TreeView m_sponsor_view;

  Gtk::Frame m_preamble_frame;
  Gtk::VBox m_preamble_box;
  Gtk::ScrolledWindow m_preamble_scrolledwindow;
  Glib::RefPtr<Gtk::ListStore> m_refPreambleModel;
  Gtk::TreeView m_preamble_view;

  Gtk::Frame m_body_frame;
  Gtk::VBox m_body_box;
  Gtk::ScrolledWindow m_body_scrolledwindow;
  Glib::RefPtr<Gtk::TreeStore> m_refBodyModel;
  Gtk::TreeView m_body_view;

  Resolution* m_resolution;

  void on_title_changed();
  void on_main_submitter_changed();
};

#endif //GTKRESOLUTION_H
