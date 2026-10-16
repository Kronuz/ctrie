# AGENTS.md — ctrie

A header-only, compile-time compressed trie for fixed-set string membership, extracted
from Xapiand. Correct but slower than a perfect hash; kept as a benchmark contender and
reference.

## Repo map

```
ctrie.hh         The whole library: detail::Trie/Insert/Build, ctrie::build(), operator""_cword.
CMakeLists.txt   INTERFACE target ctrie::ctrie (C++17). No tests yet; CI only builds.
```

## Known issues

- The header's final pragma is `push` where it should be `pop`, so the
  `-Wgnu-string-literal-operator-template` suppression leaks into includers.
- `operator""_cword` is a GNU extension (string literal operator template); MSVC
  rejects it.
- No tests: add a `static_assert` suite before changing `Insert` or `find`.
