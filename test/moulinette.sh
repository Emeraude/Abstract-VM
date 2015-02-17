#!/bin/sh

THROW_SYNTAX="Syntax Error : Unknown type"
THROW_OVERFLOW="Syntax Error : Unknown type"
THROW_UNDERFLOW=""
THROW_DIV0="Mathematique Error : Division by 0"

.././avm < small_test > .avm_small_test 
diff small_test_diff .avm_small_test > /dev/null

if [ $? -eq 0 ]
then
    echo "Small test Successfull :)"
    rm -f .avm_small_test >&-
else
    echo "Small test Unsuccessfull :("
    rm -f .avm_small_test >&-
    exit 1
fi

.././avm < medium_test > .avm_medium_test
diff medium_test_diff .avm_medium_test > /dev/null

if [ $? -eq 0 ]
then
    echo "Medium test Successfull :)"
    rm -f .avm_medium_test >&-
else
    echo "Medium test Unsuccessfull :("
    rm -f .avm_medium_test >&-
    exit 1
fi

# .././avm < big_test > .avm_big_test
# diff big_test_diff .vm_big_test

# if [ $? -eq 0 ]
# then
#     echo "Big test Successfull :)"
#     rm -f .avm_big_test >&-
# else
#     echo "Big test Unsuccessfull :("
#     rm -f .avm_big_test >&-
#     exit 1
# fi
