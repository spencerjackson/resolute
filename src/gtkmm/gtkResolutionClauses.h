#ifndef GTKRESOLUTIONCLAUSES_H
#define GTKRESOLUTIONCLAUSES_H

#include <gtkmm/frame.h>
#include <gtkmm/paned.h>
#include <gtkmm/textview.h>
#include <gtkmm/buttonbox.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/treeview.h>

#include "resolutionModel.h"

#include "../resolution.h"
#include "../clause.h"

class GtkResolutionClauses : public Gtk::Frame {
public:
  GtkResolutionClauses();
  ~GtkResolutionClauses();
  Gtk::VPaned m_VPaned;
  Gtk::ScrolledWindow m_ResolutionScrolledWindow;
  Gtk::TreeView m_TreeView;
  Glib::RefPtr<ResolutionModel> m_refModel;
  Gtk::VBox m_ClauseVBox;
  Gtk::HButtonBox m_ButtonBox;
  Gtk::Button m_ClauseAddButton;
  Gtk::Button m_SubClauseAddButton;
  Gtk::Button m_ClauseDeleteButton;
  Gtk::HBox m_PhraseHBox;
  Gtk::Label m_PhraseLabel;
  Gtk::Entry m_PhraseEntry;
  Gtk::ScrolledWindow m_TextScrolledWindow;
  Gtk::TextView m_Text;

  void on_add_clause_clicked();
  void on_add_subclause_clicked();
  void on_delete_clause_clicked();
  void on_selection_changed();
  void on_phrase_changed();
  void on_text_changed();

  void generate_model_from_resolution(Resolution* resolution);
  void generate_model_operative_clause(ClauseComposition* section, std::deque<Clause*>::iterator iterator, Gtk::TreeNodeChildren clauses);
  Resolution generate_resolution_from_model();
  ClauseComposition generate_preamble();
  ClauseComposition generate_body();
  OperativeClause generate_operative_clause(Gtk::TreeIter iterator);
};

#endif //GTKRESOLUTIONCLAUSES_H
