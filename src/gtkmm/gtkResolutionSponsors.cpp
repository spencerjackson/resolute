/* File: gtkResolutionSponsors.cpp
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

#include "gtkResolutionSponsors.h"

GtkResolutionSponsors::GtkResolutionSponsors() {
  add(m_scrolledwindow);
  m_scrolledwindow.add(m_view);
  m_scrolledwindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

  m_refModel = SponsorModel::create();
  m_view.append_column("Sponsors", m_refModel->m_columns.m_sponsor);
  m_view.set_model(m_refModel);

  show();
}
GtkResolutionSponsors::~GtkResolutionSponsors() {
}
