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

  pack_start(m_VPaned);
  m_VPaned.add1(m_ResolutionScrolledWindow);
  m_ResolutionScrolledWindow.add(m_ResolutionTreeView);
  m_ResolutionScrolledWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
  resolutionColumns m_resolutionColumns;
  m_ResolutionTreeView.append_column("Phrase", m_resolutionColumns.m_phrase);
  m_ResolutionTreeView.append_column("Text", m_resolutionColumns.m_text);
  m_refResolutionModel = Gtk::TreeStore::create(m_resolutionColumns);
  m_ResolutionTreeView.set_model(m_refResolutionModel);
  populate_model_from_resolution();
  m_VPaned.add2(m_ClauseVBox);
  m_ClauseAddButton.set_label("Add a new Clause");
  m_ClauseAddButton.signal_clicked().connect(sigc::mem_fun(*this, &GtkResolution::on_add_clause_clicked));
  m_SubClauseAddButton.set_label("Add a new Subclause");
  m_ClauseDeleteButton.set_label("Delete a Clause");
  m_ClauseVBox.pack_start(m_ClauseAddButton, Gtk::PACK_SHRINK);
  m_ClauseVBox.pack_start(m_SubClauseAddButton, Gtk::PACK_SHRINK);
  m_ClauseVBox.pack_start(m_ClauseDeleteButton, Gtk::PACK_SHRINK);
  m_ClauseVBox.pack_start(m_ClausePhraseHBox, Gtk::PACK_SHRINK);
  m_ClausePhraseHBox.pack_start(m_ClausePhraseLabel, Gtk::PACK_SHRINK);
  m_ClausePhraseLabel.set_label("Phrase");
  m_ClausePhraseHBox.pack_start(m_ClausePhraseEntry, Gtk::PACK_SHRINK);
  m_ClauseVBox.pack_start(m_ClauseTextScrolledWindow);
  m_ClauseTextScrolledWindow.add(m_ClauseText);
  m_ClauseTextScrolledWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

  show_all_children();
}

void GtkResolution::on_title_changed() {
  m_resolution->setIssue(m_title.get_text());
}

void GtkResolution::on_main_submitter_changed() {
  m_resolution->setMainSubmitter(m_submitter_entry.get_text());
}

void GtkResolution::on_add_clause_clicked() {
  Gtk::TreeModel::iterator iter = m_ResolutionTreeView.get_selection()->get_selected();
  Gtk::TreeModel::Row row = *iter;
  resolutionColumns resolutionColumns;
  Clause *clause;
  std::string phrase = row[resolutionColumns.m_phrase];
  if (phrase == "Preamble") clause = new PreambulatoryClause;
  else if (phrase == "Body") clause = new OperativeClause;
}

void GtkResolution::populate_model_from_resolution() {
  Gtk::TreeModel::iterator iter = m_refResolutionModel->prepend();
  Gtk::TreeModel::Row row;
  resolutionColumns m_resolutionColumns;
  row = *iter;
  //Populate the preamble first...
  ClauseComposition *preamble = m_resolution->getPreamble();
  row[m_resolutionColumns.m_phrase] = "Preamble";
  Gtk::TreeModel::iterator iter_child = m_refResolutionModel->append(row.children());
  Gtk::TreeModel::Row row_child = *iter_child;
  for(std::deque<Clause*>::iterator it = preamble->getBegin(); it != preamble->getEnd(); it++) {
    row_child[m_resolutionColumns.m_phrase] = (*it)->getPhrase();
    row_child[m_resolutionColumns.m_text] = (*it)->getText();
  }
  //Next populate the body
  iter = m_refResolutionModel->prepend();
  row = *iter;
  ClauseComposition *body = m_resolution->getBody();
  row[m_resolutionColumns.m_phrase] = "Body";
  iter_child = m_refResolutionModel->append(row.children());
  for(std::deque<Clause*>::iterator it = body->getBegin(); it != body->getEnd(); it++) {
    row_child[m_resolutionColumns.m_phrase] = (*it)->getPhrase();
    row_child[m_resolutionColumns.m_text] = (*it)->getText();
  }
}
