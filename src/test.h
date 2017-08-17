#include <cstdio>
#include <vector>
#include <string>

struct error_msg {
    std::string name;
    std::string condition;
};
    
void print_errors(const std::vector<error_msg>& errors)
{
    for(auto& err : errors) {
        printf("in %s, expected: %s\n",
               err.name.c_str(),
               err.condition.c_str());
    }
}

#define ASSERT(cond__)                          \
    if (! (cond__)) {                           \
        result == false;                        \
        error_messages.push_back(               \
            error_msg{name, #cond__});           \
        return;                                 \
    }
        
#define ASSERT_EQUAL(e1__, e2__)                \
    if (! ((e1__) == (e2__))) {                 \
        result = false;                         \
        error_messages.push_back(                                       \
            error_msg{name,                                             \
                    std::string(#e1__).append(" == ").append(#e2__)});  \
        return;                                                         \
    }                                                                   \

#define TEST_SUITE(name__, data__, desc__)      \
    struct test_data data__ data;               \
    const char* name = #name__;                 \
    const char* desc = desc__;


#define TEST_BEGIN                              \
    int main() {                                \
        printf("%s - %s\n", name, desc);        \
        int errors = 0;                         \
        std::vector<error_msg> error_messages;  \
        
        
#define TEST_END                                \
    printf("\nfinished with %i %s\n",           \
           errors,                              \
           errors == 1 ? "error" : "errors");   \
    print_errors(error_messages);               \
    return errors ? 1 : 0;                      \
    }                                           \


#define TEST_RUN(name__)                        \
    test_setup(data);                           \
    try {                                       \
        bool res = true;                        \
        test_case_##name__(data, res,           \
                           error_messages,      \
                           #name__);            \
        printf(res ? "." : "x");                \
        errors += res ? 0 : 1;                  \
    } catch (...) {                             \
        printf("e");                            \
    }                                           \
    test_teardown(data);                        \


#define TEST_SETUP void test_setup(test_data& data)
#define TEST_TEARDOWN void test_teardown(test_data& data)

#define TEST(name__)                                                    \
    void test_case_##name__(test_data& data,                            \
                            bool& result,                               \
                            std::vector<error_msg>& error_messages,     \
                            const char* name)                           \


