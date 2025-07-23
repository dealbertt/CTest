# 📘 `CTest` — C Unit Testing Library Inspired by JUnit

A lightweight unit testing framework for C inspired by JUnit, supporting grouped tests, assertions, source tracking, and formatted output.

---

## Table of Contents

- [Getting Started](#getting-started)
- [Test Groups & Running Tests](#test-groups--running-tests)
- [Assertions](#assertions)
  - [Equality Assertions](#equality-assertions)
  - [Inequality Assertions](#inequality-assertions)
  - [Boolean Assertions](#boolean-assertions)
  - [Null Assertions](#null-assertions)
- [Configuration](#configuration)
- [Colors and Output](#colors-and-output)
- [License](#license)

---

## Getting Started
First, build the library on the root folder of the repo using the next command:  

```make
make
```
Once the library has been build, in order to install it in your system you can do the next command:  

```make
sudo make install
```
If you want to completely remove the library from your system, just execute the follwing command:  

```make
sudo make uninstall
```
You can also delete the object files created using the command:  

```make
make clean
```

Include `ctest.h` in your project and link against the implementation file (not shown here). 

```c
#include "ctest.h"
```

Create tests as functions, group them, and run the suite.

When compiling, make sure to include the following flag:

```cmd
gcc main.c -o whatevername -lctest
```
By default, passed asserts are not displayed, meaning only the asserts that failed will showup at run time, if you wish to see both the passed and failed asserts, you can compile the program with the following flag:  

```cmd
gcc main.c -o whatevername -lctest -DVERBOSE_ASSERT_RESULT
```
When using this option, you can expect an output like this:  

```cmd
✓[PASSED]: assertEqualsFloat
Time Taken: 0 ms
----------------------
✗[FAILED]: assertEqualsDouble
On file: test/main.c | Line: 54 | Function: main
Time Taken: 0 ms
Expected: 2 vs Actual: 4
----------------------
```

---

## Test Groups & Running Tests

```c
int initGroup(TestGroup *group);
int addTest(TestGroup *group, const char *name, CTest *test);
int runTests(TestGroup *group);
```

### Example

```c
void sampleTest(TestResult *res) {
    assertEqualsInt(5, 2 + 3);
}

int main() {
    TestGroup group;
    initGroup(&group);

    CTest test = { .func = sampleTest };
    addTest(&group, "Addition Test", &test);

    runTests(&group);
    return 0;
}
```

---

## Assertions

All assertions track the source file, line number, and function using `__FILE__`, `__LINE__`, and `__func__` via the `CUR_SOURCE_LOCATION` macro.

---

### Equality Assertions

```c
assertEqualsInt(expected, actual);
assertEqualsShort(expected, actual);
assertEqualsLong(expected, actual);
assertEqualsFloat(expected, actual);
assertEqualsDelta(expected, actual, delta);
assertEqualsDouble(expected, actual);
assertEqualsChar(expected, actual);
assertEqualsStr(expected, actual);
```

#### Array Versions

```c
assertEqualsArrayInt(expected, actual);
assertEqualsArrayShort(expected, actual);
assertEqualsArrayLong(expected, actual);
assertEqualsArrayFloat(expected, actual);
assertEqualsArrayDouble(expected, actual);
```

---

### Inequality Assertions

```c
assertNotEqualsInt(expected, actual);
assertNotEqualsShort(expected, actual);
assertNotEqualsLong(expected, actual);
assertNotEqualsFloat(expected, actual);
assertNotEqualsDouble(expected, actual);
assertNotEqualsChar(expected, actual);
assertNotEqualsStr(expected, actual);
```

#### Array Versions

```c
assertNotEqualsArrayInt(expected, actual);
assertNotEqualsArrayShort(expected, actual);
assertNotEqualsArrayLong(expected, actual);
assertNotEqualsArrayFloat(expected, actual);
assertNotEqualsArrayDouble(expected, actual);
```

---

### Boolean Assertions

```c
assertTrue(actual);
assertFalse(actual);
```

---

### Null Assertions

```c
assertNotNull(pointer);
assertNull(pointer);
```

---

## Configuration

You can enable extra debug and verbosity at compile-time using:

```c
#define DEBUG_ASSERT_ENABLED 1
#define VERBOSE_ASSERT_RESULT 1
```

When enabled, `DEBUG_ASSERT()` will track and display failed expressions with source metadata.

---

## Colors and Output

The framework uses ANSI color codes:

- `red()` – Failures
- `green()` – Successes

These macros can be used in user code for custom formatting as well.

---

## Examples folder  

To know how to use the library, you can find an example folder with some examples on how to use the library properly

---
