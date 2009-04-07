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
  preamble = new ClauseComposition;
  body = new ClauseComposition;
}

Resolution::Resolution(std::string path) {
  deserialize(path);
}

Resolution::~Resolution() {
  delete preamble;
  delete body;
}

void Resolution::serialize(std::string path) {
}

void Resolution::deserialize(std::string path) {
}

void Resolution::addSignature(const std::string& signature) {
  m_signatures.push_back(signature);
}

void Resolution::insertClause(Clause& clause, const int& pos) {
  if(clause.isOperative()) body->addClause(clause);
  else preamble->addClause(clause);
}

void Resolution::removeClause(Clause& clause) {
  if(clause.isOperative()) body->removeClause(clause);
  else preamble->removeClause(clause);
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

ClauseComposition* Resolution::getPreamble() {
  return preamble;
}

ClauseComposition* Resolution::getBody() {
  return body;
}

void Resolution::set_preamble(const ClauseComposition& preamble) {
  *(this->preamble) = preamble;
}

void Resolution::set_body(const ClauseComposition& body) {
  *(this->body) = body;
}

