/* File: resolutionModel.cpp
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

#include "resolutionModel.h"

ResolutionModel::ResolutionModel() {
  set_column_types(m_columns);
}

ResolutionModel::~ResolutionModel() {
}

Glib::RefPtr<ResolutionModel> ResolutionModel::create() {
  return Glib::RefPtr<ResolutionModel> (new ResolutionModel);
}

bool ResolutionModel::row_draggable_vfunc(const Gtk::TreeModel::Path& path) const {
  if (path.to_string().find(":", 0) == Glib::ustring::npos) return false;
  return true;
}

bool ResolutionModel::row_drop_possible_vfunc(const Gtk::TreeModel::Path& dest, const Gtk::SelectionData& selection_data) const {
  if (dest.to_string().find(":", 0) == Glib::ustring::npos) return false;
  return true;
}
