0x19. C - Stacks, Queues - LIFO, FIFO
# Monty Language Overview

Monty 0.98 is a scripting language that undergoes compilation into Monty byte codes, much like Python. It operates around a distinctive stack mechanism, incorporating specific instructions tailored to its manipulation. This project focuses on developing an interpreter for Monty ByteCodes files.

## Monty Byte Code Files

Files containing Monty byte codes are typically denoted with the .m extension. While adherence to this extension is commonplace within the industry, it is not strictly required by the language specification. Each line usually contains a single instruction. Op codes and their arguments can be preceded or followed by any number of spaces:

```plaintext
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
```

Monty byte code files can include blank lines, which can either be entirely empty or composed of spaces. Any extra text following the opcode or its mandatory argument is ignored:

```plaintext
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
```

# Usage

To compile all the files, use the following command:

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```

To execute the program:

```bash
./monty bytecode_file
```

Available op codes:

| Opcode | Description |
|------------------- | --------------|
|push   | Pushes an element onto the stack. (e.g., push 1 pushes 1 into the stack)|
|pall   | Prints all values on the stack, starting from the top.|
|pint   | Prints the value at the top of the stack.|
|pop    | Removes the top element from the stack. |
|swap   | Swaps the top two elements of the stack.|
|add    | Adds the top two elements of the stack, storing the result in the second node.|
|nop    | No operation; does nothing.|
|sub    | Subtracts the second top element from the top element, updating the second node.|
|div    | Divides the second top element by the top element, updating the second node.|
|mul | Multiplies the top two elements, updating the second node.|
|mod    | Computes the remainder of the top two elements divided by the second top element.|
|#      | Lines starting with # are treated as comments.|
|pchar  | Prints the integer at the top as its ASCII value representation.|
|pstr   | Prints the integers on the stack as ASCII characters until 0 or non-ASCII value is reached.|
|rotl   | Rotates the top element to the bottom of the stack.|
|rotr   | Rotates the bottom element to the top of the stack.|
|stack  | Sets the data format to stack (LIFO), the default behavior.|
|queue  | Sets the data format to queue (FIFO).|

### Author:

1. Brian Kimurgor
