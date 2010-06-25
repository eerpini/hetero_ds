#include "stack_hetero.h"

int main(){

        struct hetero_stack *base = NULL;
        struct hetero_stack *top = NULL;
        int vari;
        double varf;
        char *vars;
        double varl;
        varl = 2132.38402;
        vari = 10;
        varf=10.234;
        vars = (char *)malloc(strlen("Ten"));
        strcpy(vars, "Ten");
        print(base);
        push("int", &vari, &base, &top);
        push("double", &varf, &base, &top);
        push("string", vars, &base, &top);
        print(base);
        vari = 11;
        push_by_type("string", vars, &base, &top);
        print(base);
        push_by_type("string", vars, &base, &top);
        print(base);
        print_by_type("int", base);
        push_by_type("double", &varl, &base, &top);
        varl=3.146;
        push("double", &varl, &base, &top);
        print(base);
        print_by_type("double", base);
        pop_by_type("int",&base);
        print(base);
        print_by_type("some", base);
        pop_by_type("sum",&base);
        print(base);
        return 0;
}


