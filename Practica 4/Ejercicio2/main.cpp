#include <tau/tau.h>
#include <array>
#include "Tupla.h"

TAU_MAIN()


TEST(TestTemplate, asdasd)
{
    Tupla<int,3> a;
    a[0] = 10;
    a[1] = 20;
    a[2] = 30;
    Tupla<char,2> b;
    b[0] = 'a';
    b[1] = 'b';
    CHECK(a[0] == 10);
    CHECK(a[1] == 20);
    CHECK(a[2] == 30);
    CHECK(b[0] == 'a');
    CHECK(b[1] == 'b');
}
