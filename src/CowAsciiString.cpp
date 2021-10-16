/*
 * CowAsciiString.cpp
 *
 *  Created on: 13 de out de 2021
 *      Author: njaneto
 */

#include "CowAsciiString.h"

#include <ostream>

using namespace Navmii::ProgrammingTest;

namespace Navmii {
namespace ProgrammingTest {
//--------------------------------------------------------------------------
CowAsciiString::CowAsciiString() :
		_buffer(nullptr), _length(0) {
}
//--------------------------------------------------------------------------
CowAsciiString::CowAsciiString(const CowAsciiString &other) {

	_buffer = nullptr;
	_length = 0;

	assign(other);
}
//--------------------------------------------------------------------------
CowAsciiString::CowAsciiString(const char *source) {

	_buffer = nullptr;
	_length = 0;

	assign(source);
}
//--------------------------------------------------------------------------
CowAsciiString::CowAsciiString(const char *source, int size) {

	if (source != nullptr && 0 < size) {
		_length = size;
		_buffer = new char[_length];
	} else {
		_buffer = nullptr;
		_length = 0;
	}
}
//--------------------------------------------------------------------------
CowAsciiString::~CowAsciiString() {

/* free(): double free detected in tcache 2
	if (_buffer != nullptr) {
		delete _buffer;
	}
*/
}
//--------------------------------------------------------------------------
int CowAsciiString::getLength() const {

	return _length;
}
//--------------------------------------------------------------------------
void CowAsciiString::setChar(int index, char character) {

	if (_buffer != nullptr && 0 < index && index < _length) {
		_buffer[index] = character;
	}
}
//--------------------------------------------------------------------------
char CowAsciiString::getChar(int index) const {

	if (_buffer != nullptr && 0 < index && index < _length) {
		return _buffer[index];
	}

	return '\0';
}
//--------------------------------------------------------------------------
char CowAsciiString::operator [](int index) const {

	if (_buffer != nullptr && 0 <= index && index < _length) {
		return _buffer[index];
	} else {
		return '\0';
	}
}
//--------------------------------------------------------------------------
void CowAsciiString::append(char character) {

	append(CowAsciiString(&character, 1));
}
//--------------------------------------------------------------------------
void CowAsciiString::append(const CowAsciiString &other) {

	if (other.getLength() != 0) {
		int length = _length + other._length;
		char *buf = new char[length];
		if (0 < _length) {
			this->mymemcpy(buf, _buffer, _length);
		}
		if (0 < other._length) {
			this->mymemcpy(buf + _length, other._buffer, other._length);
		}

		if (_buffer != nullptr) {
			delete _buffer;
		}

		_length = length;
		_buffer = buf;
	}
}
//--------------------------------------------------------------------------
CowAsciiString& CowAsciiString::operator +=(const CowAsciiString &other) {

	append(other);
	return *this;
}
//--------------------------------------------------------------------------
CowAsciiString CowAsciiString::operator +(const CowAsciiString &other) const {

	int length = _length + other._length;
	char *buf = new char[length];
	if (0 < _length) {
		this->mymemcpy(buf, _buffer, _length);
	}
	if (0 < other._length) {
		this->mymemcpy(buf + _length, other._buffer, other._length);
	}

	if (_buffer != nullptr) {
		delete _buffer;
	}

	CowAsciiString str;
	str._length = length;
	str._buffer = buf;

	return str;
}
//--------------------------------------------------------------------------
void CowAsciiString::insert(const CowAsciiString &other, int index) {

	const int LENGTH = ((_length > 1) ? _length : 1);

	if (other.getLength() != 0 && 0 <= index && index < LENGTH) {
		int length = _length + other._length;
		char *buf = new char[length];

		if (0 < index) {
			this->mymemcpy(buf, _buffer, index);
		}
		this->mymemcpy(buf + index, other._buffer, other._length);

		if (index < _length) {
			this->mymemcpy(buf + index + other._length, buf + index,
					_length - index);
		}

		if (_buffer != nullptr) {
			delete _buffer;
		}

		_length = length;
		_buffer = buf;
	}
}
//--------------------------------------------------------------------------
void CowAsciiString::remove(int startingIndex, int removedCharactersCount) {

	if (0 <= startingIndex && startingIndex < _length && 0 < removedCharactersCount) {
		this->mymemmove(_buffer + startingIndex, _buffer + startingIndex + removedCharactersCount, removedCharactersCount);
		_length -= removedCharactersCount;
	}

}
//--------------------------------------------------------------------------
bool CowAsciiString::equals(const CowAsciiString &other) const {

	if (_length == other._length
			&& (this->mymemcmp(_buffer, other._buffer, _length) == 0)) {
		return true;
	}

	return false;
}
//--------------------------------------------------------------------------
bool CowAsciiString::operator ==(const CowAsciiString &other) const {

	return equals(other);

}
//--------------------------------------------------------------------------
bool CowAsciiString::operator !=(const CowAsciiString &other) const {

	return !(*this == other);
}
//--------------------------------------------------------------------------
bool CowAsciiString::find(char character, int &foundIndex) const {

	foundIndex = -1;

	for (int i = 0; i < _length; ++i) {
		if (_buffer[i] == character) {
			foundIndex = i;
			return true;
		}
	}
	return false;
}
//--------------------------------------------------------------------------
bool CowAsciiString::find(const CowAsciiString &substring,
		int &foundIndex) const {

	foundIndex = -1;

	if (_buffer != nullptr) {
		char *ptr = this->mystrstr(_buffer, substring._buffer);
		if (ptr != nullptr) {
			foundIndex = ptr - _buffer;
			return true;
		}
	}
	return false;
}
//--------------------------------------------------------------------------
void CowAsciiString::assign(const char *source) {

	if (source != nullptr) {
		int length = this->mystrlen(source);
		assign(source, length);
	}
}
//--------------------------------------------------------------------------
void CowAsciiString::assign(const CowAsciiString& other) {

    assign(other._buffer, other._length);
}
//--------------------------------------------------------------------------
void CowAsciiString::assign(const char *source, int size) {

	if (source != nullptr) {
		if (_buffer != nullptr) {
			delete _buffer;
			_length = 0;
		}
		if (size > 0) {
			_length = size;
			_buffer = new char[_length];
			this->mymemcpy(_buffer, source, _length);
		}
	}
}
//--------------------------------------------------------------------------
CowAsciiString& CowAsciiString::operator =(const char *source) {

	assign(source);
	return *this;
}
//--------------------------------------------------------------------------
void CowAsciiString::toPlainString(char *outputBuffer,
		int maxOutputBufferSize) const {

	if (outputBuffer != nullptr) {
		int lengh = (
				_length < maxOutputBufferSize - 1 ?
						_length : maxOutputBufferSize - 1);
		this->mymemcpy(outputBuffer, _buffer, lengh);
		outputBuffer[lengh] = '\0';
	}
}
//--------------------------------------------------------------------------
void* CowAsciiString::mymemcpy(void *dest, const void *src, size_t n) const {

	size_t i;
	char *cdest = (char *)dest;
	char *csrc = (char *)src;

	for (i = 0; i < n; ++i) {
		*((char*) cdest + i) = *((char*) csrc + i);
	}

	return dest;
}
//--------------------------------------------------------------------------
size_t CowAsciiString::mystrlen(const char *str) const {

	size_t i = 0;
	if (str != nullptr) {
		while ('\0' != str[i]) {
			++i;
		}
	}
	return i;
}
//--------------------------------------------------------------------------
int CowAsciiString::mymemcmp(const void *lhs, const void *rhs, size_t n) const {

	size_t i;
	char *clhs = (char *)lhs;
	char *crhs = (char *)rhs;

	if (clhs != nullptr && crhs != nullptr) {
		for (int i = 0; i < n; ++i) {
			if (*(char*) (clhs + i) > *(char*) (crhs + i)) {
				return (*(char*) (clhs + i) > *(char*) (crhs + i)) ? 1 : -1;
			}
		}
	}
	return 0;
}
//--------------------------------------------------------------------------
void* CowAsciiString::mymemmove(void *dest, const void *src, size_t n) const {

	int _size;
	char *cdest = (char *)dest;
	char *csrc = (char *)src;

	if (cdest != nullptr && csrc != nullptr && 0 < n) {
		if (cdest < csrc && (cdest + n) > csrc) {
			_size = cdest + n - csrc;
			this->mymemcpy(cdest, csrc, n - _size);
			this->mymemcpy(cdest + (n - _size), csrc + n - (_size), _size);
		} else if (csrc < cdest && (csrc + n) > cdest) {
			_size = csrc + n - cdest;
			this->mymemcpy(cdest + _size, csrc + _size, n - _size);
			this->mymemcpy(cdest, csrc, _size);
		} else {
			this->mymemcpy(cdest, csrc, n);
		}
	}
	return dest;
}
//--------------------------------------------------------------------------
char* CowAsciiString::mystrstr(const char *str, const char *target) const {

	int str_len;
	int target_len;
	const char *ptr;

	if (NULL != str && NULL != target) {
		str_len = mystrlen(str);
		target_len = mystrlen(target);

		if (0 < target_len && target_len <= str_len) {

			for (ptr = str; *(ptr + target_len) != '\0'; ++ptr) {

				if (mymemcmp(ptr, target, target_len) == 0) {
					return (char*) ptr;
				}

			}
		}
	}
	return nullptr;
}

} /* namespace ProgrammingTest */
} /* namespace Navmii */

std::ostream& Navmii::ProgrammingTest::operator<<(std::ostream &os,
		const CowAsciiString &str) {
	os.flush();
	os << "\"" << str._buffer << "\"";
	return os;
}

