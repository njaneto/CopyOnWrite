/*
 * CowAsciiString_test.h
 *
 *  Created on: 14 de out de 2021
 *      Author: njaneto
 */

#ifndef TESTSUITE_COWASCIISTRING_TEST_H_
#define TESTSUITE_COWASCIISTRING_TEST_H_

#include <string>

#include "CppUnit/TestCase.h"

class CowAsciiString_test: public CppUnit::TestCase {
public:
	CowAsciiString_test(const std::string &name);
	~CowAsciiString_test();

	void test_SimpleAsciiString_other(void);
	void test_GetLength(void);
	void test_SetChar_GetChar(void);
	void test_Append_other(void);
	void test_Insert_other_index(void);
	void test_Remove_startingIndex_removedCharactersCount(void);
	void test_Equals_other(void);
	void test_Find_substring_foundIndex(void);
	void test_Assign_other(void);
	void test_ToPlainString_outputBuffer_maxOutputBufferSize(void);

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:

};

#endif /* TESTSUITE_COWASCIISTRING_TEST_H_ */
