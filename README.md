# Test tasks C++ 
  
(C) Copyright 2012 Navmii Holdings plc.

Copying, distribution, or reproduction of this document or its part in any printed or electronic form is prohibited without an explicit written permission from Navmii Holdings plc., UK.

C++ Programming Test B-1 v1.7

Level: Mid/Senior C++ Developer.

Skills: C++ basics, structured programming, multithreading, low-level programming.

This file contains a class that a candidate should implement so that we can test their programming skills.

The class is a Copy-on-Write dynamic string consisting of US-ASCII characters, i.e. the usual ASCII characters with codes not exceeding 127. This limitation is introduced to exclude problems related to encodings and localization.

The Copy-on-Write (CoW) technique is described, for example, in Wikipedia: http://en.wikipedia.org/wiki/Copy-on-write, as well as in a number of books and articles.

The implementation must not use the STL or Boost libraries, or any other third-party libraries, or the C library memory or string functions such as memcpy, strcpy, strstr or strlen. This limitation means that you should write even the simplest code, for example, that copies a sequence of characters, by yourself.

The code should conform to the C++ 2003 standard (ISO/IEC 14882:2003) as much as possible. This particularly means you cannot use the new C++ 11 features and the standard library features such as std::atomic.

The string class must allow copying its instances between threads, but is not required to be thread safe by itself. Making a string copy and using it in another thread must be completely safe, while accessing the same string object from different threads is not required to be safe.

Multithreading support in a CoW string means that the string implementation requires the use of platform-specific synchronization or atomicity functions or intrinsics. You are only required to implement the class for a single platform, the one of your preference, for example, one of Windows x86, Linux x86, Mac OS X, iOS, or another popular platform. For the purpose of implementing thread safety, you are allowed to use platform-dependent functions, intrinsics or assembly.


### Environment and build

*  Build copyOnWrite:

    ```
    # cd CopyOnWrite/src/
    # make clean -s && make -s
    ./copyOnWrite

    ```

*  Attention to compile and run the tests will be necessary to download [POCO C++ Libraries](https://pocoproject.org/download.html)
and set the POCO_BASE
*  Build testSuite:

    ```
    # cd CopyOnWrite/testSuite/
    # make clean -s && make -s
    # ./testrunner -all

    ```

*  Build all:

    ```
    # cd CopyOnWrite/
    # make clean -s && make -s

    ```

## Authors-Collaborators

* **Nilo Jose de Andrade Neto**
