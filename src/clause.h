/* File: clause.h
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

#ifndef CLAUSE_H
#define CLAUSE_H
#include <string>
#include <list>

enum clauseSection_t{NONE, PREAMBLE, BODY};

class Clause {
public:
  Clause();
  Clause(const std::string& phrase, const std::string& text, clauseSection_t section);
  ~Clause();
  std::string getPhrase() const;
  std::string getText() const;
  const clauseSection_t getSection() const;
  void setPhrase(const std::string& phrase);
  void setText(const std::string& text);
  void setSection( const clauseSection_t& section);
  bool operator==(const Clause& other);
private:
  std::string m_phrase, m_text;
  clauseSection_t m_section;
};
#endif //CLAUSE_H
