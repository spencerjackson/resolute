/* File: clause_test.h
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

#ifndef CLAUSE_TEST_H
#define CLAUSE_TEST_H
#include <string>
#include <cppunit/extensions/HelperMacros.h>
#include "../clause.h"

class ClauseTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(ClauseTest);
  CPPUNIT_TEST(testEquivalency);
  CPPUNIT_TEST(testEquality);
  CPPUNIT_TEST_SUITE_END();
private:
  std::string phrase1, text1, phrase2, text2;
  clauseSection_t type1, type2;
  Clause *clause1a, *clause1b, *clause2;
public:
  void setUp();
  void tearDown();
  void testEquivalency();
  void testEquality();
};
#endif //CLAUSE_TEST_H
