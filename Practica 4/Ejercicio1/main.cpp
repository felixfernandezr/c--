#include <tau/tau.h>
#include <array>
#include "Dupla.h"

TAU_MAIN()


TEST(TestTemplate, asdasd)
{
    Dupla<int> a(10,20);
    Dupla<char> b ('a', 'b');
    CHECK(a[0] == 10);
    CHECK(a[1] == 20);
    CHECK(b[0] == 'a');
    CHECK(b[1] == 'b');
}
