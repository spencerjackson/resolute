/* File: resolute.cpp
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

#include <iostream>
#include "resolute.h"

Resolute::Resolute() {
  set_title("Resolute");
  set_default_size(800, 600);

  add(m_vbox);

    //Create menu
    m_actiongroup = Gtk::ActionGroup::create();
    //Create File menu
    m_actiongroup->add(Gtk::Action::create("MenuFile", "_File"));
    m_actiongroup->add(Gtk::Action::create("New", Gtk::Stock::NEW), sigc::mem_fun(*this, &Resolute::on_action_file_new));
    m_actiongroup->add(Gtk::Action::create("Open", Gtk::Stock::OPEN), sigc::mem_fun(*this, &Resolute::on_action_file_open));
    m_actiongroup->add(Gtk::Action::create("Save", Gtk::Stock::SAVE), sigc::mem_fun(*this, &Resolute::on_action_file_save));
    m_actiongroup->add(Gtk::Action::create("SaveAs", Gtk::Stock::SAVE_AS), sigc::mem_fun(*this, &Resolute::on_action_file_saveas));
    m_actiongroup->add(Gtk::Action::create("Quit", Gtk::Stock::QUIT), sigc::mem_fun(*this, &Resolute::on_action_file_quit));
    //Create Help menu
    m_actiongroup->add(Gtk::Action::create("MenuHelp", "_Help"));
    m_actiongroup->add(Gtk::Action::create("About", Gtk::Stock::ABOUT), sigc::mem_fun(*this, &Resolute::on_action_help_about));
    //Create UIManager
    m_uimanager = Gtk::UIManager::create();
    m_uimanager->insert_action_group(m_actiongroup);

    Glib::ustring ui_info =
      "<ui>"
      " <menubar name='Menubar'>"
      "  <menu action='MenuFile'>"
      "   <menuitem action='New'/>"
      "   <menuitem action='Open'/>"
      "   <menuitem action='Save'/>"
      "   <menuitem action='SaveAs'/>"
      "   <menuitem action='Quit'/>"
      "  </menu>"
      "  <menu action='MenuHelp'>"
      "   <menuitem action='About'/>"
      "  </menu>"
      " </menubar>"
      "</ui>";

    m_uimanager->add_ui_from_string(ui_info);

    Gtk::Widget* pMenubar = m_uimanager->get_widget("/Menubar");
    m_vbox.pack_start(*pMenubar, Gtk::PACK_SHRINK);
    pMenubar->show();

    show_all_children();
}

Resolute::~Resolute() {
}

void Resolute::on_action_file_new() {
  std::cout << "New Resolution. Functionality not yet implemented." << std::endl;
}

void Resolute::on_action_file_open() {
  std::cout << "Open an existing Resolution. Functionality not yet implemented." << std::endl;
}

void Resolute::on_action_file_save() {
  std::cout << "Save Resolution. Functionality not yet implemented." << std::endl;
}

void Resolute::on_action_file_saveas() {
  std::cout << "Save as Resolution. Functionality not yet implemented." << std::endl;
}

void Resolute::on_action_file_quit() {
  hide();
}

void Resolute::on_action_help_about() {
  std::cout << "About Resolute. Functionality not yet implemented." << std::endl;
}
