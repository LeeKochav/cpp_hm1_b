#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;

TEST_CASE("Test replacement of v and w")
{
    string text = "Dont Vorry about a thing cause every little thing is goona be aWesome";
    CHECK(find(text, "worry") == string("Vorry"));
    CHECK(find(text, "Worry") == string("Vorry"));
    CHECK(find(text, "vorry") == string("Vorry"));
    CHECK(find(text, "every") == string("every"));
    CHECK(find(text, "ewery") == string("every"));
    CHECK(find(text, "eWery") == string("every"));
    CHECK(find(text, "eVery") == string("every"));
    CHECK(find(text, "awesome") == string("aWesome"));
    CHECK(find(text, "aVesome") == string("aWesome"));
    CHECK(find(text, "avesome") == string("aWesome"));
    CHECK(find(text, "aWesome") == string("aWesome"));

}
TEST_CASE("Test replacement of p,b and f") {
    string text = "The colors of the rainbow so Pretty in the sky and also on the baces of Feoble passing by";
    CHECK(find(text, "rainFow") == string("rainbow"));
    CHECK(find(text, "rainPow") == string("rainbow"));
    CHECK(find(text, "pretty") == string("Pretty"));
    CHECK(find(text, "bretty") == string("Pretty"));
    CHECK(find(text, "fretty") == string("Pretty"));
    CHECK(find(text, "faces") == string("baces"));
    CHECK(find(text, "paces") == string("baces"));
    CHECK(find(text, "people") == string("Feoble"));
    CHECK(find(text, "Feople") == string("Feoble"));
    CHECK(find(text, "passing") == string("passing"));
    CHECK(find(text, "Fassing") == string("passing"));
}

TEST_CASE("Test replacement of g and j") {
    string text = "Dont stop me now im having such a jood time gust Jive me a call";
    CHECK(find(text, "having") == string("having"));
    CHECK(find(text, "havinG") == string("having"));
    CHECK(find(text, "havinJ") == string("having"));
    CHECK(find(text, "good") == string("jood"));
    CHECK(find(text, "Good") == string("jood"));
    CHECK(find(text, "just") == string("gust"));
    CHECK(find(text, "Gust") == string("gust"));
    CHECK(find(text, "Just") == string("gust"));
    CHECK(find(text, "give") == string("Jive"));
    CHECK(find(text, "jive") == string("Jive"));
    CHECK(find(text, "Give") == string("Jive"));
}

TEST_CASE("Test replacement of c,k and q") {
    string text = "QicQing your qan all over the plaCe singing we will we will rock you";
    CHECK(find(text, "kicking") == string("QicQing"));
    CHECK(find(text, "Kicking") == string("QicQing"));
    CHECK(find(text, "Kiqking") == string("QicQing"));
    CHECK(find(text, "can") == string("qan"));
    CHECK(find(text, "kan") == string("qan"));
    CHECK(find(text, "Can") == string("qan"));
    CHECK(find(text, "place") == string("plaCe"));
    CHECK(find(text, "plaqe") == string("plaCe"));
    CHECK(find(text, "rokk") == string("rock"));
    CHECK(find(text, "rokc") == string("rock"));
    CHECK(find(text, "rock") == string("rock"));
}

TEST_CASE("Test replacement of s and z") {
    string text = "BirdS flying high you know how i feel Sun in the zky you know how i feel breese drifthing on by";
    CHECK(find(text, "birds") == string("BirdS"));
    CHECK(find(text, "Birds") == string("BirdS"));
    CHECK(find(text, "BirdZ") == string("BirdS"));
    CHECK(find(text, "zun") == string("Sun"));
    CHECK(find(text, "sun") == string("Sun"));
    CHECK(find(text, "Sun") == string("Sun"));
    CHECK(find(text, "sky") == string("zky"));
    CHECK(find(text, "Zky") == string("zky"));
    CHECK(find(text, "breeze") == string("breese"));
    CHECK(find(text, "breeZe") == string("breese"));
    CHECK(find(text, "breeSe") == string("breese"));
}

TEST_CASE("Test replacement of d and t") {
    string text = "im noT one of Dhose who can easily hite I DonT have much money bud if i TiT";
    CHECK(find(text, "not") == string("noT"));
    CHECK(find(text, "nod") == string("noT"));
    CHECK(find(text, "those") == string("Dhose"));
    CHECK(find(text, "Those") == string("Dhose"));
    CHECK(find(text, "hide") == string("hite"));
    CHECK(find(text, "hiDe") == string("hite"));
    CHECK(find(text, "dont") == string("DonT"));
    CHECK(find(text, "Dont") == string("DonT"));
    CHECK(find(text, "but") == string("bud"));
    CHECK(find(text, "did") == string("TiT"));
    CHECK(find(text, "dit") == string("TiT"));
}

TEST_CASE("Test replacement of o and u") {
    string text = "beacOse im happy clang along if yoo feel like a rUUm withoOt a roof";
    CHECK(find(text, "beacuse") == string("beacOse"));
    CHECK(find(text, "along") == string("along"));
    CHECK(find(text, "alUng") == string("along"));
    CHECK(find(text, "you") == string("yoo"));
    CHECK(find(text, "yoU") == string("yoo"));
    CHECK(find(text, "room") == string("rUUm"));
    CHECK(find(text, "rOOm") == string("rUUm"));
    CHECK(find(text, "without") == string("withoOt"));
    CHECK(find(text, "withuot") == string("withoOt"));
    CHECK(find(text, "rOOf") == string("roof"));
    CHECK(find(text, "roof") == string("roof"));
}

TEST_CASE("Test replacement of i and y") {
    string text = "You brought me fame and fortune and everything that goes wIth it Y thank you all";
    CHECK(find(text, "You") == string("You"));
    CHECK(find(text, "iou") == string("You"));
    CHECK(find(text, "everYthIng") == string("everything"));
    CHECK(find(text, "everithyng") == string("everything"));
    CHECK(find(text, "everithyng") == string("everything"));
    CHECK(find(text, "with") == string("wIth"));
    CHECK(find(text, "wyth") == string("wIth"));
    CHECK(find(text, "it") == string("it"));
    CHECK(find(text, "It") == string("it"));
    CHECK(find(text, "I") == string("Y"));
    CHECK(find(text, "i") == string("Y"));
}

TEST_CASE("Test exception thrown") {
    string text = "We are the champions my friends";
    CHECK_THROWS_AS(find(text,""),std::exception);
    CHECK_THROWS_AS(find(text, "Test") ,std::exception);
    CHECK_THROWS_AS(find(text, "Test2"), std::exception);
    CHECK_THROWS_AS(find(text, "Test3"),std::exception); 
    CHECK_THROWS_AS(find(text,"90"),std::exception);
    CHECK_THROWS_AS(find(text,","),std::exception);
    CHECK_THROWS_AS(find(text,"."),std::exception);
    CHECK_THROWS_AS(find(text,"-"),std::exception);
    CHECK_THROWS_AS(find(text,"Weeeeee"),std::exception);
    CHECK_THROWS_AS(find(text,"friend"),std::exception);
    CHECK_THROWS_AS(find(text,"champ"),std::exception);
    CHECK_THROWS_AS(find("","are"),std::exception);
}
