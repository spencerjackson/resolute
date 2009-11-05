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

#include "resolutionModel.h"
#include "sponsorModel.h"

#include "gtkResolutionSponsors.h"
#include "gtkResolutionClauses.h"

#include "../resolution.h"
#include "../clause.h"

class GtkResolution : public Gtk::VBox {
public:
  GtkResolution();
  ~GtkResolution();
  void init();
  Resolution generate();
protected:
  Gtk::HBox m_header_box;
  Gtk::Label m_title_label;
  Gtk::Entry m_title;
  Gtk::Label m_submitter_label;
  Gtk::Entry m_submitter_entry;

  GtkResolutionSponsors m_sponsors;
  GtkResolutionClauses m_clauses;

  void generate_model_from_resolution(Resolution* resolution);
  void generate_model_operative_clause(ClauseComposition* section, std::deque<Clause*>::iterator iterator, Gtk::TreeNodeChildren clauses);
  Resolution generate_resolution_from_model();
};

#endif //GTKRESOLUTION_H
