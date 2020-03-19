Andy Chia - 101111058

Source files submitted: encode.c decode.c corrupt.c fix.c

To test encode.c 
    gcc encode.c
    ./a.out
    <enter input any word>

To test decode.c 
    gcc decode.c -lm
    ./a.out
    <enter the hamming code sequence>

To test fix.c
    gcc fix.c 
    ./a.out
    <enter corrupted hamming code sequence to received the fixed version>