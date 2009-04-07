/* File: clause_test.cpp
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

#include "clause_test.h"

void ClauseTest::setUp() {
    phrase1 = "Proclaims";
    text1 = "there exists a need for immediate action";
    phrase2 = "Applauding";
    text2 = "efforts already made";
    clause1a = new PreambulatoryClause;
    clause1a->setPhrase(phrase1);
    clause1a->setText(text1);
    clause1b = new PreambulatoryClause(phrase1, text1);
    clause2 = new OperativeClause(phrase2, text2);
}

void ClauseTest::tearDown() {
  delete clause1a;
  delete clause1b;
  delete clause2;
}
void ClauseTest::testEquivalency() {
  CPPUNIT_ASSERT(clause1a->getPhrase() == clause1b->getPhrase());
  CPPUNIT_ASSERT(clause1a->getText() == clause1b->getText());
}
void ClauseTest::testEquality() {
  CPPUNIT_ASSERT(*clause1a == *clause1b);
  CPPUNIT_ASSERT_ASSERTION_FAIL(CPPUNIT_ASSERT(*clause1a == *clause2));
}

CPPUNIT_TEST_SUITE_REGISTRATION(ClauseTest);
