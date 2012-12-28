This code represents the Knuth Morris Pratt string searching algorithm (called KMP algorithm). It searches for occurences of a word (W) in a long string (S). 
You can find in the input.txt a long string.

To use it: 

         - g++ main.cpp -o kmp

         - ./kmp "the" < input.txt

         -  to verify the correctness of a word: word="in";  ./kmp $word < input.txt ; cat input.txt |grep $word -o|wc -l

This algorithm is in O(n + k) with n, length of the big string and k the length of the pattern we are looking for.
