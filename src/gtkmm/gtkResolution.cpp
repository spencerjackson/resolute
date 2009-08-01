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
  m_resolution = new Resolution;
  init();
}

GtkResolution::GtkResolution(Resolution* resolution) {
  m_resolution = resolution;
  init();
}

GtkResolution::~GtkResolution() {
}

void GtkResolution::init() {
  m_title_label.set_label("Issue");
  m_header_box.pack_start(m_title_label, Gtk::PACK_SHRINK);
  m_header_box.pack_start(m_title, Gtk::PACK_SHRINK);
  m_title.signal_changed().connect(sigc::mem_fun(*this, &GtkResolution::on_title_changed));
  m_title.set_text(m_resolution->getIssue());
  m_submitter_label.set_label("Main Submitter");
  m_header_box.pack_start(m_submitter_label, Gtk::PACK_SHRINK);
  m_header_box.pack_start(m_submitter_entry, Gtk::PACK_SHRINK);
  pack_start(m_header_box, Gtk::PACK_SHRINK);
  m_submitter_entry.signal_changed().connect(sigc::mem_fun(*this, &GtkResolution::on_main_submitter_changed));
  m_submitter_entry.set_text(m_resolution->getMainSubmitter());
  pack_start(m_sponsor_scrolledwindow);
  m_sponsor_scrolledwindow.add(m_sponsor_view);
  m_sponsor_scrolledwindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
  sponsorColumns m_sponsorColumns;
  m_sponsor_view.append_column("Sponsors", m_sponsorColumns.m_sponsor);
  m_refSponsorsModel = Gtk::ListStore::create(m_sponsorColumns);
  m_sponsor_view.set_model(m_refSponsorsModel);
  for(int i = 0; i < 50; i++) {
    Gtk::TreeModel::Row row = *(m_refSponsorsModel->append());
    row[m_sponsorColumns.m_sponsor] = "China";
  }


  pack_start(m_preamble_frame);
  m_preamble_frame.set_label("Preamble");
  m_preamble_frame.add(m_preamble_box);
  m_preamble_box.add(m_preamble_scrolledwindow);
  m_preamble_scrolledwindow.add(m_preamble_view);
  m_preamble_scrolledwindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
  resolutionColumns m_resolutionColumns;
  m_preamble_view.append_column("Phrase", m_resolutionColumns.m_phrase);
  m_preamble_view.append_column("Text", m_resolutionColumns.m_text);
  m_refPreambleModel = Gtk::ListStore::create(m_resolutionColumns);
  m_preamble_view.set_model(m_refPreambleModel);
  for(int i = 0; i < 50; i++) {
    Gtk::TreeModel::Row row = *(m_refPreambleModel->append());
    row[m_resolutionColumns.m_phrase] = "Understanding";
    row[m_resolutionColumns.m_text] = "the issue";
  }

  pack_start(m_body_frame);
  m_body_frame.set_label("Body");
  m_body_frame.add(m_body_box);
  m_body_box.add(m_body_scrolledwindow);
  m_body_scrolledwindow.add(m_body_view);
  m_body_scrolledwindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
  m_body_view.append_column("Phrase", m_resolutionColumns.m_phrase);
  m_body_view.append_column("Text", m_resolutionColumns.m_text);
  m_refBodyModel = Gtk::TreeStore::create(m_resolutionColumns);
  m_body_view.set_model(m_refBodyModel);
  for(int i = 0; i < 50; i++) {
    Gtk::TreeModel::Row row = *(m_refBodyModel->append());
    row[m_resolutionColumns.m_phrase] = "Resolves";
    row[m_resolutionColumns.m_text] = "to remain aware of the issue";
  }


  show_all_children();
}

void GtkResolution::on_title_changed() {
  m_resolution->setIssue(m_title.get_text());
}

void GtkResolution::on_main_submitter_changed() {
  m_resolution->setMainSubmitter(m_submitter_entry.get_text());
}
