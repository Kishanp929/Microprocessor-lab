ORG 0H
LJMP MAIN
ORG 100H
MAIN:
ACALL MUL168
ACALL FINDM
HERE:SJMP HERE
ORG 130H

FINDM:

MOV R4 , #127 //VALUE OF D
MOV 73H , #06H
MOV 74H , #06H
JUMP0:

ACALL MUL168
MOV A , 75H
MOV B , #247
DIV AB
MOV 76H , B
MOV 73H , B
DJNZ R4 , JUMP0
RET

MUL168:
MOV A , 73H
MOV B , 75H
MUL AB
MOV 73H , A
MOV B , 75H
MOV A , 74H
MUL AB
MOV 74H , A
MOV A , B
ADD A , 73H
MOV 73H , A
RET

RET
END
