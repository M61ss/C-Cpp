#include <stddef.h>

enum parse_error {
    PARSE_ERR_EXTRA_CHARACTER,
    PARSE_ERR_UNEXPECTED_END,
    PARSE_ERR_MISSING_CLOSING_PARENTHESIS,
    PARSE_ERR_MISSING_OPENING_PARENTHESIS,
    PARSE_ERR_MISSING_DOT_SEPARATOR,
};

enum expr_tag {
    EXPR_FUNC,
    EXPR_VAR,
    EXPR_LIST,
    EXPR_STMT,
    EXPR_ERROR,
};

typedef struct expr {
    enum expr_tag tag;
    union {
        struct {
            char *param_name;
            struct expr *body;
        } func;
        struct {
            char *name;
        } var;
        struct {
            size_t len;
            struct expr **args;
        } list;
        struct {
            char *name;
            struct expr *expr;
        } stmt;
        struct {
            enum parse_error kind;
            char *location;
        } error;
    };
} expr_t;

int main(void) {
    // It is useful to have a tagged union to represent the different kinds of expressions
    // that can be parsed from a string. After parsing, thanks this data structure, we can
    // save the type of expression detected.

    return 0;   
}