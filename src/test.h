#include <cstdio>

#define ASSERT_EQUAL(e1__, e2__)   \
    if (! (e1__ == e2__)) {        \
        result = false;            \
        return;                    \
    }

#define TEST_SUITE(name__, data__, desc__)      \
    struct test_data data__ data;               \
    const char* name = #name__;                 \
    const char* desc = desc__;


#define TEST_BEGIN                              \
    int main() {                                \
        printf("%s - %s\n", name, desc);
        
#define TEST_END printf("\nfinished with %i errors\n", 0); }

#define TEST_RUN(name__)                        \
    test_setup(data);                           \
    try {                                       \
        bool res = true;                        \
        test_case_##name__(data, res);          \
        printf(res ? "." : "x");                \
    } catch (...) {                             \
        printf("e");                            \
    }                                           \
    test_teardown(data);

#define TEST_SETUP void test_setup(test_data& data)
#define TEST_TEARDOWN void test_teardown(test_data& data)

#define TEST(name__) void test_case_##name__(test_data& data, bool& result)
