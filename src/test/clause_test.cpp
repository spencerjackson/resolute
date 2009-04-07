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
    type1 = BODY;
    phrase2 = "Applauding";
    text2 = "efforts already made";
    type2 = PREAMBLE;
    clause1a = new Clause;
    clause1a->setPhrase(phrase1);
    clause1a->setText(text1);
    clause1a->setSection(type1);
    clause1b = new Clause(phrase1, text1, type1);
    clause2 = new Clause(phrase2, text2, type2);
}

void ClauseTest::tearDown() {
  delete clause1a;
  delete clause1b;
  delete clause2;
}
void ClauseTest::testEquivalency() {
  CPPUNIT_ASSERT(clause1a->getPhrase() == clause1b->getPhrase());
  CPPUNIT_ASSERT(clause1a->getText() == clause1b->getText());
  CPPUNIT_ASSERT(clause1a->getSection() == clause1b->getSection());
}
void ClauseTest::testEquality() {
  CPPUNIT_ASSERT(*clause1a == *clause1b);
  CPPUNIT_ASSERT_ASSERTION_FAIL(CPPUNIT_ASSERT(*clause1a == *clause2));
}

CPPUNIT_TEST_SUITE_REGISTRATION(ClauseTest);
