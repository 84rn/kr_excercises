#ifndef _TESTS_H_
#define _TESTS_H_

#include "getline.h"
#include "itoa_.h"
#include "atoi_.h"
#include "reverse.h"
#include "strindex_.h"
#include "getopt.h"

#define print_test_name(x) printf("\n\n=> Testing " #x "() function <=\n\n")

void tests_init(void);
void test_getline(void);
void test_itoa_(void);
void test_atoi_(void);
void test_reverse(void);
void test_strindex_(void);
void test_getopt(void);

#endif