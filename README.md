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

Include `ctest.h` in your project and link against the implementation file (not shown here). 

```c
#include "ctest.h"
```

Create tests as functions, group them, and run the suite.

---

## Test Groups & Running Tests

```c
int initGroup(CTestGroup *group);
int addTest(CTestGroup *group, const char *name, CTest *test);
int runTests(CTestGroup *group);
```

### Example

```c
void sampleTest(CTest *test) {
    assertEqualsInt(5, 2 + 3);
}

int main() {
    CTestGroup group;
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
- `yellow()`, `blue()`, `white()` – Neutral/informational
- `clear()` – Clears terminal output

These macros can be used in user code for custom formatting as well.

---

## License

*Include your license here if applicable.*
