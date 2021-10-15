#include "CowAsciiString_test.h"

#include "CppUnit/TestCaller.h"
#include "CppUnit/TestSuite.h"

#include "CowAsciiString.h"

using namespace Navmii::ProgrammingTest;

CowAsciiString_test::CowAsciiString_test(const std::string &name) :
		CppUnit::TestCase(name) {
}
//---------------------------------------------------------------------------
CowAsciiString_test::~CowAsciiString_test() {
}
//---------------------------------------------------------------------------
void CowAsciiString_test::test_SimpleAsciiString_other(void) {

	CowAsciiString str("Hello, world!!!");
	std::cout << std::endl;
    std::cout << "str: " << str << std::endl;
	CowAsciiString str2(str);
    std::cout << "str2: " << str2 << std::endl;

	bool equals = (str == str2);

	assert(equals);
}
//---------------------------------------------------------------------------
void CowAsciiString_test::test_GetLength(void) {

	CowAsciiString str("world!!!");
	std::cout << std::endl;
	std::cout << "str: " << str << std::endl;
	std::cout << "getLength: " << str.GetLength() << std::endl;

	assert(str.GetLength() > 1);
}
//---------------------------------------------------------------------------
void CowAsciiString_test::test_SetChar_GetChar(void) {

	CowAsciiString str("Hello");
	std::cout << std::endl;
    std::cout << "str: " << str << std::endl;
    str.SetChar(4,'-');
    std::cout << "str: " << str << std::endl;
    std::cout << "str.GetChar(4): " << str.GetChar(4) << std::endl;

	assert(str.GetChar(4) == '-');

}
//---------------------------------------------------------------------------
void CowAsciiString_test::test_Append_other(void) {

	CowAsciiString str("A");
	std::cout << std::endl;
	std::cout << "str: " << str << std::endl;
	CowAsciiString str2("B");
	std::cout << "str2: " << str2 << std::endl;
    str.Append(str2);
	std::cout << "str: " << str << std::endl;

	int pos;
	assert(str.Find('B', pos));

}
//---------------------------------------------------------------------------
void CowAsciiString_test::test_Insert_other_index(void) {

	CowAsciiString str("w");
	std::cout << std::endl;
    std::cout << "str: " << str << std::endl;
	CowAsciiString str2("Hello");
    std::cout << "str2: " << str2 << std::endl;
    str2.Insert(str,1);
    std::cout << "str2: " << str2 << std::endl;

	assert(str2.GetLength() > 4);
}
//---------------------------------------------------------------------------
void CowAsciiString_test::test_Remove_startingIndex_removedCharactersCount(void) {

	CowAsciiString str("Hello, world!!!");
	std::cout << std::endl;
    std::cout << "str: " << str << std::endl;
	str.Remove(1, 5);
    std::cout << "str: " << str << std::endl;

	int pos;
	assert(!str.Find('d', pos));

}
//---------------------------------------------------------------------------
void CowAsciiString_test::test_Equals_other(void) {

	CowAsciiString str("Hello, world!!!");
	std::cout << std::endl;
    std::cout << "str: " << str << std::endl;
	CowAsciiString str2(str);
    std::cout << "str2: " << str2 << std::endl;

	bool equals = (str == str2);

	assert(equals);

}
//---------------------------------------------------------------------------
void CowAsciiString_test::test_Find_substring_foundIndex(void) {

	CowAsciiString str("Hello, world!!!");
	std::cout << std::endl;
    std::cout << "str: " << str << std::endl;

    int pos;
    str.Find(" ", pos);
    str.Insert(str, pos);
    std::cout << "str: " << str << std::endl;

    assert(str.GetLength() > 14);

}
//---------------------------------------------------------------------------
void CowAsciiString_test::test_Assign_other(void) {

	CowAsciiString str("world!!!");
	std::cout << std::endl;
    std::cout << "str: " << str << std::endl;
	CowAsciiString str2("Hello, ");
	str2.Assign(str+str2);

    std::cout << "str2: " << str2 << std::endl;

	assert(true);

}
//---------------------------------------------------------------------------
void CowAsciiString_test::test_ToPlainString_outputBuffer_maxOutputBufferSize(void) {

	CowAsciiString str("Hello, world!!!");
	std::cout << std::endl;

	char buffer[13];
    str.ToPlainString(buffer, 13);

    std::cout << "str: " <<  str << std::endl;
    std::cout << "buffer: " <<  buffer << std::endl;

	assert(str.GetLength());

}
//---------------------------------------------------------------------------
void CowAsciiString_test::setUp() {
}
//---------------------------------------------------------------------------
void CowAsciiString_test::tearDown() {
}
//---------------------------------------------------------------------------
CppUnit::Test* CowAsciiString_test::suite() {

	CppUnit::TestSuite *pSuite = new CppUnit::TestSuite("CowAsciiString_test");

	CppUnit_addTest(pSuite, CowAsciiString_test, test_SimpleAsciiString_other);
	CppUnit_addTest(pSuite, CowAsciiString_test, test_GetLength);
	CppUnit_addTest(pSuite, CowAsciiString_test, test_SetChar_GetChar);
	CppUnit_addTest(pSuite, CowAsciiString_test, test_Append_other);
	CppUnit_addTest(pSuite, CowAsciiString_test, test_Insert_other_index);
	CppUnit_addTest(pSuite, CowAsciiString_test, test_Remove_startingIndex_removedCharactersCount);
	CppUnit_addTest(pSuite, CowAsciiString_test, test_Equals_other);
	CppUnit_addTest(pSuite, CowAsciiString_test, test_Find_substring_foundIndex);
	CppUnit_addTest(pSuite, CowAsciiString_test, test_Assign_other);
	CppUnit_addTest(pSuite, CowAsciiString_test, test_ToPlainString_outputBuffer_maxOutputBufferSize);

	return pSuite;
}
