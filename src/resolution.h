/* File: resolution.h
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

#ifndef RESOLUTION_H
#define RESOLUTION_H

#include <list>
#include <string>

#include "clause.h"

class Resolution {
public:
  Resolution();
  Resolution(std::string path);
  ~Resolution();
  void serialize(std::string path);
  void deserialize(std::string path);
  void addSignature(const std::string& signature);
  std::string getIssue() const;
  std::string getMainSubmitter() const;
  void setIssue(std::string issue);
  void setMainSubmitter(std::string mainSubmitter);
  void insertClause(Clause& clause, const int& pos=-1);
  void removeClause(Clause& clause);

  ClauseComposition* getPreamble();
  ClauseComposition* getBody();

  void set_preamble(const ClauseComposition& preamble);
  void set_body(const ClauseComposition& body);

protected:
  std::string m_issue;
  std::string m_mainSubmitter;
  std::string m_committee, m_committee_name;
  std::list<std::string> m_signatures;
  ClauseComposition *preamble;
  ClauseComposition *body;
};

#endif //RESOLUTION_H
