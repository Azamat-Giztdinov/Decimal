#include "unit_test.h"

void srunner_test(Suite *s, int *no_failed) {
  SRunner *srunner = srunner_create(s);
  srunner_run_all(srunner, CK_NORMAL);
  *no_failed = srunner_ntests_failed(srunner);
  srunner_free(srunner);
}

int main(void) {
  setlocale(LC_ALL, "RU");
  int no_failed = 0;
  srunner_test(add_suite(), &no_failed);             //++++
  srunner_test(sub_suite(), &no_failed);             //++++
  srunner_test(int_to_dec_suite(), &no_failed);      //++++
  srunner_test(float_to_dec_suite(), &no_failed);    //++++
  srunner_test(dec_to_float_suite(), &no_failed);    //++++
  srunner_test(decimal_to_int_suite(), &no_failed);  //++++
  srunner_test(negate_suite(), &no_failed);          //++++
  srunner_test(mul_suite(), &no_failed);             //++++
  srunner_test(truncate_suite(), &no_failed);        //++++
  srunner_test(comparing_suite(), &no_failed);       //++++
  srunner_test(floor_suite(), &no_failed);           //++++
  srunner_test(round_suite(), &no_failed);
  srunner_test(div_suite(), &no_failed);  //++++
  srunner_test(mod_suite(), &no_failed);  //++++

  return (no_failed == 0) ? 0 : 1;
}
