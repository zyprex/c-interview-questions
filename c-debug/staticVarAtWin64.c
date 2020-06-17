#define A 0

#ifdef _WIN64 ///////////// mingw64

// .bss = 2432
#if (A==1)
double a1;        // +8 .bss
// .bss = 2440
#elif (A==2)
static double a2; // +0 .bss
// .bss = 2432
#elif (A==3)
static double a3; // +0 .bss
static double a4; // +0 .bss
static double a5; // +32 .bss
// .bss = 2464
#endif

#else //////////////////// linux

// .bss = 4
#if (A==1)
double a1;        // +12 .bss
// .bss = 16
#elif (A==2)
static double a2; // +12 .bss
// .bss = 16
#elif (A==3)
static double a3; // +12 .bss
// .bss = 16
static double a4; // +8 .bss
// .bss = 24
static double a5; // +8 .bss
// .bss = 32
#endif

#endif

main(void) { }

