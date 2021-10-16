/*
 * CowAsciiString.h
 *
 *  Created on: 13 de out de 2021
 *      Author: njaneto
 */

#ifndef INCLUDE_COWASCIISTRING_H_
#define INCLUDE_COWASCIISTRING_H_

#include <stddef.h>
#include <iostream>

namespace Navmii {
namespace ProgrammingTest {
/**
 * @brief A dynamic Copy-on-Write string with US-ASCII (up to character code 127) characters.
 */
class CowAsciiString {
public:

	/**
	 * @name Construction and Copying
	 */
	/**@{*/

	/**
	 * @brief Creates an empty string.
	 */
	CowAsciiString();

	/**@}*/

	/**
	 * @name Destructor
	 */
	/**@{*/

	virtual ~CowAsciiString();

	/**
	 * @name Construction and Copying
	 */
	/**@{*/

	/**
	 * @brief Creates a copy of string other.
	 */
	CowAsciiString(const CowAsciiString &other);

	/**@}*/

	/**
	 * @name Length
	 */
	/**@{*/

	/**
	 * @brief Returns a string length.
	 */
	int getLength() const;

	/**@}*/

	/**
	 * @name Characters
	 */
	/**@{*/

	/**
	 * @brief Sets a character at a specified index (starting from zero).
	 *
	 * @note The function does not validate the index, if the index is out
	 * of the bounds (0, GetLength() - 1), behavior is undefined.
	 */
	void setChar(int index, char character);

	/**
	 * @brief Returns the value of a character at a specified index (starting from zero).
	 *
	 * @note The function does not validate the index, if the index is out
	 * of the bounds (0, GetLength() - 1), behavior is undefined.
	 */
	char getChar(int index) const;

	/**
	 * @brief Returns the value of a character at a specified index (starting from zero).
	 *
	 * @note The function does not validate the index, if the index is out
	 * of the bounds (0, GetLength() - 1), behavior is undefined.
	 */
	char operator [](int index) const;

	/**@}*/

	/**
	 * @name Modification
	 */
	/**@{*/

	/**
	 * @brief Appends a character to a string.
	 *
	 * @note If the character is the null terminator ('\0'), behavior is undefined.
	 */
	void append(char character);

	/**
	 * @brief Appends another string to this string.
	 */
	void append(const CowAsciiString &other);

	/**
	 * @brief Appends another string to this string.
	 */
	CowAsciiString& operator +=(const CowAsciiString &other);

	/**
	 * @brief Splices two strings returning the result.
	 *
	 * @example <code>CowAsciiString splicedString = CowAsciiString("a") + CowAsciiString("b")</code>;
	 * Result: the value of the splicedString is "ab".
	 */
	CowAsciiString operator +(const CowAsciiString &other) const;

	/**
	 * @brief Inserts a string into a specified position (starting from zero).
	 *
	 * @example
	 * <code>
	 * CowAsciiString a = "1245";
	 * a.Insert("3", 2);
	 * </code>
	 * Result: the value of a is "12345";
	 *
	 * @note The function does not validate the index, if the index is out
	 * of the bounds (0, GetLength() - 1), behavior is undefined.
	 */
	void insert(const CowAsciiString &other, int index);

	/**
	 * @brief Removes a range of characters from the string.
	 *
	 * @param startingIndex The index of the first character to remove.
	 *
	 * @param removedCharactersCount The number of characters to remove.
	 * The zero value is acceptable, in this case the function should simply do nothing.
	 * If the value is negative, behavior is undefined.
	 *
	 * @note The function does not validate the indices. If the range
	 * to be removed is out of the bounds (0, GetLength() - 1),
	 * behavior is undefined.
	 */
	void remove(int startingIndex, int removedCharactersCount);

	/**@}*/

	/**
	 * @name Comparison
	 */
	/**@{*/

	/**
	 * @brief Returns true if strings are equal.
	 *
	 * @note This method should only implement simple bitwise comparison (i.e. byte-to-byte equality),
	 * no complex comparisons are required.
	 */
	bool equals(const CowAsciiString &other) const;

	/**
	 * @brief Returns true if strings are equal.
	 */
	bool operator ==(const CowAsciiString &other) const;

	/**
	 * @brief Returns true if strings are not equal.
	 */
	bool operator !=(const CowAsciiString &other) const;

	/**@}*/

	/**
	 * @name Search
	 */
	/**@{*/

	/**
	 * @brief Searches for the first matching character in a string.
	 *
	 * @param character The character to search for.
	 *
	 * @param[out] foundIndex The index of the found character.
	 * If the character is not found, the index value is undefined.
	 *
	 * @return True if the character was found, false otherwise.
	 */
	bool find(char character, /*out*/int &foundIndex) const;

	/**
	 * @brief Searches for the first matching substring in a string.
	 *
	 * @param substring The substring to search for.
	 *
	 * @param[out] foundIndex The index of the first character of the found substring.
	 * If the substring is not found, the index value is undefined.
	 *
	 * @return True if the substring was found, false otherwise.
	 */
	bool find(const CowAsciiString &substring, /*out*/int &foundIndex) const;

	/**@}*/

	/**
	 * @name Null-Terminated Strings
	 */
	/**@{*/

	/**
	 * @brief Constructs a string from a plain null-terminated C-style string.
	 */
	CowAsciiString(const char *source);

	/**
	 * @name Null-Terminated Strings
	 */
	/**@{*/

	/**
	 * @brief Constructs a string from an array of size characters.
	 */
	CowAsciiString(const char *source, int size);

	/**
	 * @brief Assigns a plain null-terminated C-style string.
	 */
	void assign(const char *source);
	void assign(const char *source, int size);
	void assign(const CowAsciiString& other);
	/**
	 * @brief Assigns a plain null-terminated C-style string.
	 */
	CowAsciiString& operator =(const char *source);

	/**
	 * @brief Copies a string into a given plain null-terminated C-style string buffer.
	 *
	 * @param[out] outputBuffer The buffer to write the string into.
	 * When the string is written into the buffer, it is always correctly terminated with the null character ('\0').
	 *
	 * @param maxOutputBufferSize The maximal size of the output buffer (including the null terminator).
	 * That is, if your buffer is <code>char buffer[32]</code>,
	 * the function call <code>ToPlainString(buffer, 32)</code> will assume
	 * that the maximal allowed number of characters to be copied is 31.
	 */
	void toPlainString(/*out*/char *outputBuffer,
			int maxOutputBufferSize) const;

	/**@}*/

	friend std::ostream& operator<<(std::ostream &os, const CowAsciiString &str);

protected:

	/**
	 * @name custom functions
	 */
	/**@{*/

	/**
	 * @brief my memcpy implementation
	 *
	 * @param dest pointer to the memory location where the contents are copied to. It is of void* type.
	 * @param src pointer to the memory location where the contents are copied from. It is of void* type.
	 * @param n number of bytes to copy from src to dest. It is of size_t type.
	 */
	void *mymemcpy(void *dest, const void *src, size_t n) const;

	/**
	 * @brief my strlen implementation
	 *
	 * @param src pointer to the C-string (null-terminated string) whose length is to be calculated
	 */
	size_t mystrlen(const char *str) const;

	/**
	 * @brief my memcmp implementation
	 *
	 * @param lhs and rhs Pointer to the memory objects to compare
	 * @param n Maximum numbers of bytes to compare.
	 *
	 */
	int mymemcmp(const void *lhs, const void *rhs, size_t n) const;

	/**
	 * @brief my memmove implementation
	 *
	 * @param dest Pointer to the memory location where the contents are copied to.
	 * @param src Pointer to the memory location where the contents are copied from.
	 * @param n Number of bytes to copy from src to dest.
	 *
	 */
	void *mymemmove(void *dest, const void *src, size_t n) const;

	/**
	 * @brief my strstr implementation
	 *
	 * @param str Pointer to the null terminated byte string to be searched for.
	 * @param target Pointer to the null terminated byte string to search for.
	 */
	char* mystrstr(const char *str, const char *target) const;

	/**@}*/


private:
	char *_buffer;
	int _length;

};
std::ostream& operator<<(std::ostream &os, const CowAsciiString &str);

} /* namespace ProgrammingTest */
} /* namespace Navmii */




#endif /* INCLUDE_COWASCIISTRING_H_ */
