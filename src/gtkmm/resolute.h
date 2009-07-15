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

#ifndef RESOLUTE_H
#define RESOLUTE_H

#include <gtkmm/window.h>
#include <gtkmm/actiongroup.h>
#include <gtkmm/action.h>
#include <gtkmm/uimanager.h>
#include <gtkmm/widget.h>
#include <gtkmm/box.h>
#include <gtkmm/stock.h>

class Resolute : public Gtk::Window {
 public:
  Resolute();
  ~Resolute();


 protected:
  Gtk::VBox m_vbox;

  Glib::RefPtr<Gtk::UIManager> m_uimanager;
  Glib::RefPtr<Gtk::ActionGroup> m_actiongroup;

  virtual void on_action_file_new();
  virtual void on_action_file_open();
  virtual void on_action_file_save();
  virtual void on_action_file_saveas();
  virtual void on_action_file_quit();
  virtual void on_action_help_about();
};

#endif //RESOLUTE_H
