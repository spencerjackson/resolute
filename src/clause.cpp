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
}
Clause::Clause(const std::string& phrase, const std::string& text) {
  m_phrase = phrase;
  m_text = text;
}
Clause::~Clause() {}
std::string Clause::getPhrase() const {
  return m_phrase;
}
std::string Clause::getText() const {
  return m_text;
}
void Clause::setPhrase( const std::string& phrase ) {
  m_phrase = phrase;
}
void Clause::setText(const std::string& text) {
  m_text=text;
}
bool Clause::operator==(const Clause& other) {
  if(m_phrase == other.getPhrase() && m_text == other.getText()) {
    return true;
  }
  else
    return false;
}

PreambulatoryClause::PreambulatoryClause() {}
PreambulatoryClause::PreambulatoryClause(const std::string& phrase, const std::string& text)
  :Clause(phrase, text) {
}
PreambulatoryClause::~PreambulatoryClause() {}
OperativeClause::OperativeClause() {}
OperativeClause::OperativeClause(const std::string& phrase, const std::string& text)
  :Clause(phrase, text) {
}
OperativeClause::~OperativeClause() {
}
