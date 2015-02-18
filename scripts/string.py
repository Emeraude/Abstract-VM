#!/usr/bin/env python3

import sys

if len(sys.argv) < 2:
    print("Usage : " + sys.argv[0] + " <string>")
    exit(1)
sys.argv[1] += '\n'
for c in sys.argv[1]:
    print("push int8(" + str(ord(c)) + ")")
    print("print")
    print("pop")

print("exit");
print(";;");
exit(0)
