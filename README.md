# ctrie

[![CI](https://github.com/Kronuz/ctrie/actions/workflows/ci.yml/badge.svg)](https://github.com/Kronuz/ctrie/actions/workflows/ci.yml)
[![License: MIT](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)
![C++17](https://img.shields.io/badge/C%2B%2B-17-blue.svg)
![Header-only](https://img.shields.io/badge/header--only-yes-green.svg)

A compile-time trie for C++17: list a fixed set of words, and look any string up to
get its index or `ctrie::npos`. The whole trie is a type, so `constexpr` lookups
cost nothing at runtime.

## ✨ Highlights

- 🧮 **Built by the compiler**: `ctrie::build(...)` turns words into a nested
  template type; no tables at runtime.
- 🔢 **Index results**: each word maps to its position in the list.
- 🔤 **Any string type**: `const char*`, pointer and length, `std::string`, or
  `std::string_view`.

## 📦 Installation

Requires a C++17 compiler that accepts string literal operator templates (Clang and
GCC do). CI builds it on Linux, macOS, and FreeBSD.

```cmake
include(FetchContent)
FetchContent_Declare(ctrie
  GIT_REPOSITORY https://github.com/Kronuz/ctrie.git
  GIT_TAG        main)
FetchContent_MakeAvailable(ctrie)

target_link_libraries(my_app PRIVATE ctrie::ctrie)
```

Or copy `ctrie.hh` onto your include path.

## 🚀 Quick start

```cpp
#include "ctrie.hh"

constexpr auto methods = ctrie::build("GET"_cword, "POST"_cword, "PUT"_cword);

static_assert(methods.find("POST") == 1);
static_assert(methods.find("PATCH") == ctrie::npos);
```

## 🎯 When to use it

- ✅ A reference implementation, or a benchmark contender, for fixed-set string
  membership.
- ❌ Production keyword dispatch: a perfect hash is faster. Use
  [constexpr-phf](https://github.com/Kronuz/constexpr-phf).

## 📚 Documentation

- [AGENTS.md](AGENTS.md): repository map and known issues.

## 🤝 Contributing

Issues and pull requests are welcome. CI must pass on every platform.

## 📄 License

MIT, Copyright (c) 2019 Germán Méndez Bravo and Terrance Howard. See [LICENSE](LICENSE).
Based on [heyterrance/ctrie](https://github.com/heyterrance/ctrie).
