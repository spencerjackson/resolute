/* File: modelColumns.h
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

#ifndef MODELCOLUMNS_H
#define MODELCOLUMNS_H
#include <gtkmm/treemodel.h>
#include <string>

class sponsorColumns : public Gtk::TreeModel::ColumnRecord {
public:
  sponsorColumns() {add(m_sponsor);}
  ~sponsorColumns() {}
  Gtk::TreeModelColumn<std::string> m_sponsor;
};

class resolutionColumns : public Gtk::TreeModel::ColumnRecord {
public:
  resolutionColumns() {add(m_phrase); add(m_text);}
  ~resolutionColumns() {}
  Gtk::TreeModelColumn<std::string> m_phrase;
  Gtk::TreeModelColumn<std::string> m_text;
};

#endif // MODELCOLUMNS_H
