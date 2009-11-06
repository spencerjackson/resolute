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
  pack_start(m_scrolledwindow);
  m_scrolledwindow.add(m_view);
  m_scrolledwindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

  m_refModel = SponsorModel::create();
  m_view.append_column("Sponsors", m_refModel->m_columns.m_sponsor);
  m_view.set_model(m_refModel);

  pack_start(m_editbox, Gtk::PACK_SHRINK);
  m_editbox.pack_start(m_buttonbox, Gtk::PACK_SHRINK);
  m_add_sponsor.set_label("Add Sponsor");
  m_add_sponsor.signal_clicked().connect(sigc::mem_fun(*this, &GtkResolutionSponsors::on_add_sponsor));
  m_buttonbox.pack_start(m_add_sponsor, Gtk::PACK_SHRINK);
  m_remove_sponsor.set_label("Remove Sponsor");
  m_remove_sponsor.signal_clicked().connect(sigc::mem_fun(*this, &GtkResolutionSponsors::on_remove_sponsor));
  m_buttonbox.pack_start(m_remove_sponsor, Gtk::PACK_SHRINK);
  m_sponsor_label.set_label("Sponsor: ");
  m_editbox.pack_end(m_sponsor_entry);
  m_editbox.pack_end(m_sponsor_label, Gtk::PACK_SHRINK);
}

GtkResolutionSponsors::~GtkResolutionSponsors() {
}

void GtkResolutionSponsors::on_add_sponsor() {
  Gtk::TreeRow row = *(m_refModel->append());
  row.set_value(m_refModel->m_columns.m_sponsor, std::string(m_sponsor_entry.get_text()));
}

void GtkResolutionSponsors::on_remove_sponsor() {
  m_refModel->erase(m_view.get_selection()->get_selected());
}
