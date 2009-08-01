/* File: about.cpp
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

#include "about.h"

#include "licence.h"
#include "img/resoluteLogo.xpm"

About::About() {
  set_program_name("Resolute");
  set_version("0.1-preAlpha");
  set_copyright("Spencer Jackson \xC2\xA9 2009");
  set_license(licence);
  set_wrap_license(true);
  set_logo(Gdk::Pixbuf::create_from_xpm_data(resoluteLogo_xpm));
}

About::~About() {
}
