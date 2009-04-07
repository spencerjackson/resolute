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
#include <deque>

class ClauseComponent {
};

class Clause : public virtual ClauseComponent {
 public:
  Clause();
  Clause(const std::string& phrase, const std::string& text);
  virtual ~Clause();

  virtual std::string getPhrase() const;
  virtual std::string getText() const;
  virtual void setPhrase(const std::string& phrase);
  virtual void setText(const std::string& text);

  virtual bool operator==(const Clause& other);
  virtual bool isOperative() const = 0;
 protected:
  std::string m_phrase, m_text;
};

class PreambulatoryClause : public Clause {
 public:
  PreambulatoryClause();
  PreambulatoryClause(const std::string& phrase, const std::string& text);
  ~PreambulatoryClause();
  virtual bool isOperative() const {return false;}
 };

class ClauseComposition : public virtual ClauseComponent {
  //This class is a list of clauses
 public:
  ClauseComposition();
  ~ClauseComposition();

  void addClause(Clause& clause);
  void removeClause(Clause& clause);

  std::deque<Clause*>::iterator getBegin();
  std::deque<Clause*>::iterator getEnd();
  unsigned int size();

 protected:
  std::deque<Clause*> m_clauses;
 };

class OperativeClause : public Clause, public ClauseComposition {
 public:
  OperativeClause();
  OperativeClause(const std::string& phrase, const std::string& text);
  ~OperativeClause();
  virtual bool isOperative() const {return true;}
 };


#endif //CLAUSE_H
