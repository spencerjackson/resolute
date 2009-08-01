/* File: about.h
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

#ifndef ABOUT_H
#define ABOUT_H

#include <gtkmm/aboutdialog.h>
#include <gdkmm/pixbuf.h>

class About : public Gtk::AboutDialog {
public:
  About();
  ~About();
};

#endif //ABOUT_H
