/* File: gtkResolution.cpp
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

#include "gtkResolution.h"

GtkResolution::GtkResolution() {
  init();
}

GtkResolution::~GtkResolution() {
}

void GtkResolution::init() {
  m_title_label.set_label("Issue");
  m_header_box.pack_start(m_title_label, Gtk::PACK_SHRINK);
  m_header_box.pack_start(m_title, Gtk::PACK_SHRINK);
  m_title.set_text("Issue");
  m_submitter_label.set_label("Main Submitter");
  m_header_box.pack_start(m_submitter_label, Gtk::PACK_SHRINK);
  m_header_box.pack_start(m_submitter_entry, Gtk::PACK_SHRINK);
  pack_start(m_header_box, Gtk::PACK_SHRINK);
  m_submitter_entry.set_text("Main Submitter");

  pack_start(m_sponsors);

  pack_start(m_clauses);

  show_all_children();
}

Resolution GtkResolution::generate() {
  return generate_resolution_from_model();
}

Resolution GtkResolution::generate_resolution_from_model() {
  return m_clauses.generate_resolution_from_model();
}
