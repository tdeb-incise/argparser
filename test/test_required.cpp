#include <catch.hpp>

#include <argparser.hpp>

TEST_CASE("Test required args 1", "[required]") {
    constexpr int argc = 1;
    const char* argv[argc] = {
        "test.exe"
    };

    ap::parser p(argc, const_cast<char**>(argv));
    REQUIRE(p.add("-n", "--name", "My name", ap::mode::REQUIRED));
    
    REQUIRE(!p.parse().parsed_successfully());
}

TEST_CASE("Test required args 2", "[required]") {
    constexpr int argc = 3;
    const char* argv[argc] = {
        "test.exe",
        "-f", "First",
    };

    ap::parser p(argc, const_cast<char**>(argv));
    REQUIRE(p.add("-f", "--first", "My first name", ap::mode::REQUIRED));
    REQUIRE(p.add("-l", "--last",  "My last name",  ap::mode::REQUIRED));
    
    REQUIRE(!p.parse().parsed_successfully());
}
