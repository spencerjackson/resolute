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

class Clause {
public:
  Clause();
  Clause(const std::string& phrase, const std::string& text);
  virtual ~Clause();
  std::string getPhrase() const;
  std::string getText() const;
  void setPhrase(const std::string& phrase);
  void setText(const std::string& text);
  bool operator==(const Clause& other);
  virtual bool isOperative() const = 0;
private:
  std::string m_phrase, m_text;
};

class PreambulatoryClause : public Clause {
public:
  PreambulatoryClause();
  PreambulatoryClause(const std::string& phrase, const std::string& text);
  ~PreambulatoryClause();
  virtual bool isOperative() const {return false;}
};

class OperativeClause : public Clause {
public:
  OperativeClause();
  OperativeClause(const std::string& phrase, const std::string& text);
  ~OperativeClause();
  virtual bool isOperative() const {return true;}
};

#endif //CLAUSE_H
