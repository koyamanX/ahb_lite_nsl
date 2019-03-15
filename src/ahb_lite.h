#ifndef AHB_LITE_H
#define AHB_LITE_H

#define READ 1'b0
#define WRITE 1'b1
#define TRUE 1'b1
#define FALSE 1'b0
#define HIGH 1'b1
#define LOW 1'b0
#define SUCCESS LOW
#define FAILURE HIGH

#define IDLE 2'b00
#define BUSY 2'b01
#define NONSEQ 2'b10
#define SEQ 2'b11

#define SINGLE 3'b000
#define INCR 3'b001
#define WRAP4 3'b010
#define INCR4 3'b011
#define WRAP8 3'b100
#define INCR8 3'b101
#define WRAP16 3'b110
#define INCR16 3'b111

#define BYTE 3'b000
#define HALFWORD 3'b001
#define WORD 3'b010

#define OK 1'b0
#define ERROR 1'b1

#endif
