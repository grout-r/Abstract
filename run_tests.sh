#!/usr/bin/env bash

make re
make clean
rm -f  log.txt

echo "TEST 1" | tee -a log.txt
echo "============" | tee -a log.txt
cat ./bin/test | tee -a log.txt
echo "============" | tee -a log.txt
./avm ./bin/test | tee -a log.txt


echo -e "\n============\n" | tee -a log.txt


echo "TEST 2" | tee -a log.txt
echo "============" | tee -a log.txt
cat ./bin/test2 | tee -a log.txt
echo "============" | tee -a log.txt
./avm ./bin/test2 | tee -a log.txt


echo -e "\n============\n" | tee -a log.txt


echo "TEST ASSERT" | tee -a log.txt
echo "============" | tee -a log.txt
cat ./bin/test_assert | tee -a log.txt
echo "============" | tee -a log.txt
./avm ./bin/test_assert &> tmp ; cat tmp  | tee -a log.txt


echo -e "\n============\n" | tee -a log.txt


echo "TEST DIV BY ZERO" | tee -a log.txt
echo "============" | tee -a log.txt
cat ./bin/test_divby0 | tee -a log.txt
echo "============" | tee -a log.txt
./avm ./bin/test_divby0 &> tmp ; cat tmp  | tee -a log.txt


echo -e "\n============\n" | tee -a log.txt


echo "TEST OPERATOR" | tee -a log.txt
echo "============" | tee -a log.txt
cat ./bin/test_operator | tee -a log.txt
echo "============" | tee -a log.txt
./avm ./bin/test_operator &> tmp ; cat tmp  | tee -a log.txt


echo -e "\n============\n" | tee -a log.txt


echo "TEST POP" | tee -a log.txt
echo "============" | tee -a log.txt
cat ./bin/test_pop | tee -a log.txt
echo "============" | tee -a log.txt
./avm ./bin/test_pop  &> tmp ; cat tmp  | tee -a log.txt


echo -e "\n============\n" | tee -a log.txt


echo "TEST EXIT" | tee -a log.txt
echo "============" | tee -a log.txt
cat ./bin/test_exit | tee -a log.txt
echo "============" | tee -a log.txt
./avm ./bin/test_exit  &> tmp ; cat tmp  | tee -a log.txt


echo -e "\n============\n" | tee -a log.txt


echo "TEST OVERFLOW 1" | tee -a log.txt
echo "============" | tee -a log.txt
cat ./bin/test_overflow1 | tee -a log.txt
echo "============" | tee -a log.txt
./avm ./bin/test_overflow1  &> tmp ; cat tmp  | tee -a log.txt



echo -e "\n============\n" | tee -a log.txt


echo "TEST OVERFLOW 2" | tee -a log.txt
echo "============" | tee -a log.txt
cat ./bin/test_overflow2 | tee -a log.txt
echo "============" | tee -a log.txt
./avm ./bin/test_overflow2  &> tmp ; cat tmp  | tee -a log.txt


echo -e "\n============\n" | tee -a log.txt


echo "TEST SYNTAX ERROR" | tee -a log.txt
echo "============" | tee -a log.txt
cat ./bin/test_syntax_error | tee -a log.txt
echo "============" | tee -a log.txt
./avm ./bin/test_syntax_error  &> tmp ; cat tmp  | tee -a log.txt


echo -e "\n============\n" | tee -a log.txt


echo "TEST UNKNOWN INSTRUCTION" | tee -a log.txt
echo "============" | tee -a log.txt
cat ./bin/test_unknown_instruction | tee -a log.txt
echo "============" | tee -a log.txt
./avm ./bin/test_unknown_instruction  &> tmp ; cat tmp  | tee -a log.txt

rm -f tmp
