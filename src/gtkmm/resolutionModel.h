/* File: resolutionModel.h
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

#ifndef RESOLUTION_MODEL_H
#define RESOLUTION_MODEL_H

#include "gtkmm/treestore.h"

class ResolutionModel : public Gtk::TreeStore {
public:
  static Glib::RefPtr<ResolutionModel> create();

  class resolutionColumns : public Gtk::TreeModelColumnRecord {
  public:
    resolutionColumns() {add(m_phrase); add(m_text);}
    ~resolutionColumns() {}
    Gtk::TreeModelColumn<std::string> m_phrase;
    Gtk::TreeModelColumn<std::string> m_text;
  } m_columns;

protected:
  ResolutionModel();
  ~ResolutionModel();
  virtual bool row_draggable_vfunc(const Gtk::TreeModel::Path& path) const;
  virtual bool row_drop_possible_vfunc(const Gtk::TreeModel::Path& dest, const Gtk::SelectionData& selection_data) const;
};

#endif //RESOLUTION_MODEL_H
