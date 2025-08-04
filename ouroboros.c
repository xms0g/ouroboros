#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>

int changePermAddr(void* addr);
void foo();
void bar();
void baz();

int main() {
    void* fooPtr = (void*)foo;
    void* mainPtr = (void*)main;

    if(changePermAddr(mainPtr) == -1) {
        fprintf(stderr, "Error changing page permission: %s\n", strerror(errno));
        return 1;
    }

    memset(mainPtr, 0, fooPtr - mainPtr - 0x16);
    
    foo();
    bar();
    baz();

    printf("%s", "Eaten myself!\n");
    return 0;
}

void foo() {
    printf("%s", "This will be eaten!\n");
}

void bar() {
    printf("%s", "This will be eaten!\n");
}

void baz() {
    printf("%s", "This will be eaten!\n");
}

int changePermAddr(void* addr) {
    int pageSize = getpagesize();
    addr -= (unsigned long)addr % pageSize;

    return mprotect(addr, pageSize, PROT_READ | PROT_WRITE | PROT_EXEC);
}