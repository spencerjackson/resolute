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
  m_refResolutionModel = Gtk::TreeStore::create(m_resolutionColumns);
  m_ResolutionTreeView.set_model(m_refResolutionModel);
  m_ResolutionTreeView.append_column("Phrase", m_resolutionColumns.m_phrase);
  Gtk::CellRendererText* text_renderer;
  int cols_count = m_ResolutionTreeView.append_column("Text", m_resolutionColumns.m_text);
  Gtk::TreeViewColumn* pColumn = m_ResolutionTreeView.get_column(cols_count-1);
  text_renderer = dynamic_cast <Gtk::CellRendererText*>(pColumn->get_first_cell_renderer());
  text_renderer->property_wrap_mode() = Pango::WRAP_WORD_CHAR;
  text_renderer->property_wrap_width() = 500;
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
  m_ClauseText.set_wrap_mode(Gtk::WRAP_WORD);

  //Create the sections of the resolution
  Gtk::TreeModel::iterator iter = m_refResolutionModel->append();
  Gtk::TreeModel::Row row = *iter;
  row[m_resolutionColumns.m_phrase] = "Preamble";
  iter = m_refResolutionModel->append();
  row = *iter;
  row[m_resolutionColumns.m_phrase] = "Body";

  show_all_children();
}

Resolution* GtkResolution::generate() {
  return generate_resolution_from_model();
}

void GtkResolution::on_add_clause_clicked() {
  resolutionColumns m_resolutionColumns;
  Gtk::TreeModel::iterator selection = m_ResolutionTreeView.get_selection()->get_selected();
  Gtk::TreeModel::iterator iter = m_refResolutionModel->insert_after(selection);
  Gtk::TreeModel::Row row = *iter;
  row[m_resolutionColumns.m_phrase] = m_title.get_text();
  row[m_resolutionColumns.m_text] = m_ClauseText.get_buffer()->get_text();
}

void GtkResolution::populate_model_from_resolution(Resolution* resolution) {
  Gtk::TreeModel::iterator iter = m_refResolutionModel->prepend();
  Gtk::TreeModel::Row row;
  resolutionColumns m_resolutionColumns;
  row = *iter;
  //Populate the preamble first...
  ClauseComposition *preamble = resolution->getPreamble();
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
  ClauseComposition *body = resolution->getBody();
  row[m_resolutionColumns.m_phrase] = "Body";
  iter_child = m_refResolutionModel->append(row.children());
  for(std::deque<Clause*>::iterator it = body->getBegin(); it != body->getEnd(); it++) {
    row_child[m_resolutionColumns.m_phrase] = (*it)->getPhrase();
    row_child[m_resolutionColumns.m_text] = (*it)->getText();
  }
}

Resolution* GtkResolution::generate_resolution_from_model() {
  resolutionColumns m_resolutionColumns;
  Resolution* resolution = new Resolution;
  Clause* clause;
  Glib::ustring string;
  Gtk::TreeModel::Children children = m_refResolutionModel->children();
  for(Gtk::TreeModel::Children::iterator iter = children.begin(); iter != children.end(); ++iter) {
    Gtk::TreeModel::Row row = *iter;
    string = row[m_resolutionColumns.m_phrase];
    if (string == "Preamble") {
      for(Gtk::TreeModel::Children::iterator child_iter = row.children().begin(); iter != row.children().end(); ++child_iter) {
	    Gtk::TreeModel::Row child_row = *child_iter;
	    clause = new PreambulatoryClause(child_row[m_resolutionColumns.m_phrase], child_row[m_resolutionColumns.m_text]);
	  }
      }
    if (string == "Body") {
	for(Gtk::TreeModel::Children::iterator child_iter = row.children().begin(); child_iter != row.children().end(); ++child_iter) {
	    Gtk::TreeModel::Row child_row = *child_iter;
	    clause = new OperativeClause(child_row[m_resolutionColumns.m_phrase], child_row[m_resolutionColumns.m_text]);
	  }
      }
  }
}
