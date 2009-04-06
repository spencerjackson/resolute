/* File: clause.cpp
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

#include "clause.h"

Clause::Clause() {
  m_phrase = "";
  m_text = "";
  m_section = NONE;
}
Clause::Clause(const std::string& phrase, const std::string& text, clauseSection_t section) {
  m_phrase = phrase;
  m_text = text;
  m_section = section;
}
Clause::~Clause() {}
std::string Clause::getPhrase() const {
  return m_phrase;
}
std::string Clause::getText() const {
  return m_text;
}
const clauseSection_t Clause::getSection() const {
  return m_section;
}
void Clause::setPhrase( const std::string& phrase ) {
  m_phrase = phrase;
}
void Clause::setText(const std::string& text) {
  m_text=text;
}
void Clause::setSection( const clauseSection_t& section) {
  m_section = section;
}
bool Clause::operator==(const Clause& other) {
  if(m_section == other.getSection() && m_phrase == other.getPhrase() && m_text == other.getText()) {
    return true;
  }
  else
    return false;
}
