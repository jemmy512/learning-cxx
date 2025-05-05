#include "../utils/assert.h"

// What does this declaration mean? Finish the definition
int (*(*f[])()) () = {

};

// ---- Do Not Modify Following Code ----
int main(int argc, char **argv) {
    ASSERT(f[0]()() == 0);
    ASSERT(f[1]()() == 1);
    return 0;
}
