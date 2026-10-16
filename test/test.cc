// ctrie: compile-time lookups and runtime lookups through every find() overload.
#include "ctrie.hh"

#include <cassert>
#include <cstdio>
#include <string>
#include <string_view>

constexpr auto methods = ctrie::build("GET"_cword, "POST"_cword, "PUT"_cword, "PATCH"_cword, "DELETE"_cword);

static_assert(methods.find("GET") == 0);
static_assert(methods.find("POST") == 1);
static_assert(methods.find("PUT") == 2);
static_assert(methods.find("PATCH") == 3);
static_assert(methods.find("DELETE") == 4);
static_assert(methods.find("PO") == ctrie::npos);      // a prefix is not a word
static_assert(methods.find("POSTS") == ctrie::npos);   // nor is an extension
static_assert(methods.find("") == ctrie::npos);
static_assert(methods.find("get") == ctrie::npos);     // exact, case included

int main() {
	std::string put = "PUT";
	std::string_view patch = "PATCH-and-more";
	assert(methods.find(put) == 2);
	assert(methods.find(patch.substr(0, 5)) == 3);
	assert(methods.find(patch.data(), 5) == 3);
	assert(methods.find(patch.data(), patch.data() + 5) == 3);
	assert(methods.find(std::string_view("PATC")) == ctrie::npos);
	std::puts("ctrie: ok");
}
