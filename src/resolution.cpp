/* File: resolution.cpp
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

#include "resolution.h"

Resolution::Resolution() {
}

Resolution::Resolution(std::string path) {
  deserialize(path);
}

Resolution::~Resolution() {
}

void Resolution::serialize(std::string path) {
}

void Resolution::deserialize(std::string path) {
}

void Resolution::insertClause(Clause clause) {
  std::list<Clause>* section;
  if(clause.getSection() == PREAMBLE) section = &m_preamble;
  else if(clause.getSection() == BODY) section = &m_body;
  section->push_back(clause);

}
void Resolution::insertClause(int pos, Clause clause) {
  std::list<Clause>* section;
  if(clause.getSection() == PREAMBLE) section = &m_preamble;
  else if(clause.getSection() == BODY) section = &m_body;
  std::list<Clause>::iterator iter = section->begin();
  for(int i = 0; i<pos; i++) {
    iter++;
  }
  section->insert(iter, clause);
}
void Resolution::replaceClause(const Clause& original, const Clause& updated) {
  std::list<Clause>* section;
  if (original.getSection() == PREAMBLE) section = &m_preamble;
  else if(original.getSection() == BODY) section = &m_body;
  for(std::list<Clause>::iterator i = section->begin(); i != section->end(); i++) {
    if (*i == original) {
      *i = updated;
    }
      //No clause found
  }
}
void Resolution::deleteClause(Clause &clause) {
  std::list<Clause>* section;
  if (clause.getSection() == PREAMBLE) section = &m_preamble;
  else if(clause.getSection() == BODY) section = &m_body;

  for(std::list<Clause>::iterator i = section->begin(); i != section->end(); i++) {
    if(*i == clause) {
      section->erase(i);
    }
  }
}

void Resolution::addSignature(const std::string& signature) {
  m_signatures.push_back(signature);
}

std::string Resolution::getIssue() const {
  return m_issue;
}

std::string Resolution::getMainSubmitter() const {
  return m_mainSubmitter;
}

void Resolution::setIssue(const std::string issue) {
  m_issue = issue;
}

void Resolution::setMainSubmitter(const std::string mainSubmitter) {
  m_mainSubmitter = mainSubmitter;
}
