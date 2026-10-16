# AGENTS.md — ctrie

A header-only, compile-time compressed trie for fixed-set string membership, extracted
from Xapiand. Correct but slower than a perfect hash; kept as a benchmark contender and
reference.

## Repo map

```
ctrie.hh         The whole library: detail::Trie/Insert/Build, ctrie::build(), operator""_cword.
test/test.cc     static_assert lookups plus every runtime find() overload.
CMakeLists.txt   INTERFACE target ctrie::ctrie (C++17); ctrie_test when top-level.
```

## Known issues

- `operator""_cword` is a GNU extension (string literal operator template); MSVC
  rejects it.
- The literal operator's warning suppression is scoped with push/pop; keep it
  scoped so it never leaks into includers.
