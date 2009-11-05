#include "gtkResolutionClauses.h"

GtkResolutionClauses::GtkResolutionClauses() {
  add(m_VPaned);
  m_VPaned.add1(m_ResolutionScrolledWindow);
  m_ResolutionScrolledWindow.add(m_TreeView);
  m_ResolutionScrolledWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
  m_refModel = ResolutionModel::create();
  m_TreeView.set_model(m_refModel);
  m_TreeView.append_column("Phrase", m_refModel->m_columns.m_phrase);
  Gtk::CellRendererText* text_renderer;
  int cols_count = m_TreeView.append_column("Text", m_refModel->m_columns.m_text);
  Gtk::TreeViewColumn* pColumn = m_TreeView.get_column(cols_count-1);
  text_renderer = dynamic_cast <Gtk::CellRendererText*>(pColumn->get_first_cell_renderer());
  text_renderer->property_wrap_mode() = Pango::WRAP_WORD_CHAR;
  text_renderer->property_wrap_width() = 500;
  m_TreeView.get_selection()->signal_changed().connect(sigc::mem_fun(*this, &GtkResolutionClauses::on_selection_changed));
  m_TreeView.set_reorderable();
  m_VPaned.add2(m_ClauseVBox);
  m_ClauseAddButton.set_label("Add a new Clause");
  m_ClauseAddButton.signal_clicked().connect(sigc::mem_fun(*this, &GtkResolutionClauses::on_add_clause_clicked));
  m_SubClauseAddButton.set_label("Add a new Subclause");
  m_SubClauseAddButton.signal_clicked().connect(sigc::mem_fun(*this, &GtkResolutionClauses::on_add_subclause_clicked));
  m_ClauseDeleteButton.set_label("Delete a Clause");
  m_ClauseDeleteButton.signal_clicked().connect(sigc::mem_fun(*this, &GtkResolutionClauses::on_delete_clause_clicked));
  m_ButtonBox.pack_start(m_ClauseAddButton, Gtk::PACK_SHRINK);
  m_ButtonBox.pack_start(m_SubClauseAddButton, Gtk::PACK_SHRINK);
  m_ButtonBox.pack_start(m_ClauseDeleteButton, Gtk::PACK_SHRINK);
  m_PhraseHBox.pack_start(m_PhraseLabel, Gtk::PACK_SHRINK);
  m_PhraseLabel.set_label("Phrase");
  m_PhraseEntry.signal_changed().connect(sigc::mem_fun(*this, &GtkResolutionClauses::on_phrase_changed));
  m_PhraseHBox.pack_start(m_PhraseEntry, Gtk::PACK_SHRINK);
  m_ClauseVBox.pack_start(m_ButtonBox, Gtk::PACK_SHRINK);
  m_ClauseVBox.pack_start(m_PhraseHBox, Gtk::PACK_SHRINK);
  m_ClauseVBox.pack_start(m_TextScrolledWindow);
  m_Text.get_buffer()->signal_changed().connect(sigc::mem_fun(*this, &GtkResolutionClauses::on_text_changed));
  m_TextScrolledWindow.add(m_Text);
  m_TextScrolledWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
  m_Text.set_wrap_mode(Gtk::WRAP_WORD);

  //Create the sections of the resolution
  Gtk::TreeModel::iterator iter = m_refModel->append();
  Gtk::TreeModel::Row row = *iter;
  row[m_refModel->m_columns.m_phrase] = "Preamble";
  iter = m_refModel->append();
  row = *iter;
  row[m_refModel->m_columns.m_phrase] = "Body";
}

GtkResolutionClauses::~GtkResolutionClauses() {
}

void GtkResolutionClauses::on_add_clause_clicked() {
  Gtk::TreeModel::iterator selection = m_TreeView.get_selection()->get_selected();
  Gtk::TreeModel::iterator iter;
  //If someone adds a clause to a section, handle that here
  if (selection->get_value(m_refModel->m_columns.m_phrase) == "Preamble" || selection->get_value(m_refModel->m_columns.m_phrase) == "Body") {
    iter = m_refModel->append(selection->children());
  }
  //If the selection isn't a section header, put it after the clause selected
  else {
    iter = m_refModel->insert_after(selection);
  }
}

void GtkResolutionClauses::on_add_subclause_clicked() {
  Gtk::TreeModel::iterator selection = m_TreeView.get_selection()->get_selected();
  m_refModel->append(selection->children());
}

void GtkResolutionClauses::on_delete_clause_clicked() {
  Gtk::TreeModel::iterator selection = m_TreeView.get_selection()->get_selected();
  if (!(selection->get_value(m_refModel->m_columns.m_phrase) == "Preamble" || selection->get_value(m_refModel->m_columns.m_phrase) == "Body")) {
  m_refModel->erase(selection);
  }
}

void GtkResolutionClauses::on_selection_changed() {
  Gtk::TreeModel::iterator selection = m_TreeView.get_selection()->get_selected();
  Gtk::TreeModel::Row row = *selection;
  m_PhraseEntry.set_text(row.get_value(m_refModel->m_columns.m_phrase));
  m_Text.get_buffer()->set_text(row.get_value(m_refModel->m_columns.m_text));

  //Disallow editing on section headers
  if(Gtk::TreePath(selection).to_string().find(":", 0) == Glib::ustring::npos) {
    m_PhraseEntry.property_editable() = false;
    m_Text.property_editable() = false;
  }
  else {
    m_PhraseEntry.property_editable() = true;
    m_Text.property_editable() = true;
  }
}

void GtkResolutionClauses::on_phrase_changed() {
  Gtk::TreeModel::iterator selection = m_TreeView.get_selection()->get_selected();
  Gtk::TreeModel::Row row = *selection;
  if (Gtk::TreePath(selection).to_string().find(":", 0) != Glib::ustring::npos) row.set_value(m_refModel->m_columns.m_phrase, std::string(m_PhraseEntry.get_text()));
}

void GtkResolutionClauses::on_text_changed() {
  Gtk::TreeModel::iterator selection = m_TreeView.get_selection()->get_selected();
  Gtk::TreeModel::Row row = *selection;
  if (Gtk::TreePath(selection).to_string().find(":", 0) != Glib::ustring::npos) row.set_value(m_refModel->m_columns.m_text, std::string(m_Text.get_buffer()->get_text()));
}

Resolution GtkResolutionClauses::generate_resolution_from_model() {
  Resolution resolution;

  ClauseComposition preamble = generate_preamble();
  ClauseComposition body = generate_body();

  resolution.set_preamble(preamble);
  resolution.set_body(body);

  return resolution;
}

ClauseComposition GtkResolutionClauses::generate_preamble() {
  ClauseComposition preamble;
  PreambulatoryClause clause;
  Gtk::TreeModel::iterator section = m_refModel->get_iter("0"); //get the iterator to the preamble header

  for(Gtk::TreeIter iterator = section->children().begin(); iterator != section->children().end(); iterator++) {
    clause = PreambulatoryClause(iterator->get_value(m_refModel->m_columns.m_phrase), iterator->get_value(m_refModel->m_columns.m_text));
    preamble.addClause(clause);
  }
  return preamble;
}

ClauseComposition GtkResolutionClauses::generate_body() {
  ClauseComposition body;
  OperativeClause clause;
  Gtk::TreeModel::iterator section = m_refModel->get_iter("1"); //get the iterator to the body header

  for(Gtk::TreeModel::Children::iterator iterator = section->children().begin(); iterator != section->children().end(); iterator++) {
      clause = generate_operative_clause(iterator);
      body.addClause(clause);
    }
    return body;
}

OperativeClause GtkResolutionClauses::generate_operative_clause(Gtk::TreeIter iterator) {
  OperativeClause clause(iterator->get_value(m_refModel->m_columns.m_phrase), iterator->get_value(m_refModel->m_columns.m_text));
  OperativeClause subclause;

  if (iterator->children().empty()) {return clause;}

  for(Gtk::TreeModel::Children::iterator child = iterator->children().begin(); child != iterator->children().end(); child++) {
    subclause = generate_operative_clause(child);
    clause.addClause(subclause);
  }
  return clause;
}

void GtkResolutionClauses::generate_model_from_resolution(Resolution* resolution) {
  Gtk::TreeModel::iterator iter = m_refModel->append();
  Gtk::TreeModel::Row row;
  row = *iter;
  //Populate the preamble first...
  ClauseComposition *preamble = resolution->getPreamble();
  row[m_refModel->m_columns.m_phrase] = "Preamble";
  Gtk::TreeModel::iterator iter_child = m_refModel->append(row.children());
  Gtk::TreeModel::Row row_child = *iter_child;
  for(std::deque<Clause*>::iterator it = preamble->getBegin(); it != preamble->getEnd(); it++) {
    row_child[m_refModel->m_columns.m_phrase] = (*it)->getPhrase();
    row_child[m_refModel->m_columns.m_text] = (*it)->getText();
    Gtk::TreeModel::iterator iter_child = m_refModel->append(row.children());
  }
  //Next populate the body
  iter = m_refModel->append();
  row = *iter;
  ClauseComposition *body = resolution->getBody();
  row[m_refModel->m_columns.m_phrase] = "Body";
  for(std::deque<Clause*>::iterator it = body->getBegin(); it != body->getEnd(); it++) {
    iter_child = m_refModel->append(row.children());
    row_child = *iter_child;
    row_child[m_refModel->m_columns.m_phrase] = (*it)->getPhrase();
    row_child[m_refModel->m_columns.m_text] = (*it)->getText();
    if(!row_child.children().empty()) {
      generate_model_operative_clause(body, it, row_child.children());
    }
  }
}

void GtkResolutionClauses::generate_model_operative_clause(ClauseComposition* section, std::deque<Clause*>::iterator iterator, Gtk::TreeNodeChildren clauses) {
  Gtk::TreeIter iter = clauses.begin();
  Gtk::TreeRow row = *iter;
  for(std::deque<Clause*>::iterator i = iterator; i != section->getEnd(); i++) {
    row[m_refModel->m_columns.m_phrase] = (*i)->getPhrase();
    row[m_refModel->m_columns.m_text] = (*i)->getText();
    if(!row.children().empty()) {
      generate_model_operative_clause(section, i, row.children());
    }
    row = *(++iter);
  }
}
