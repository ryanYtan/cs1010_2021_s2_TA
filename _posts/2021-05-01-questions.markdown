---
layout: post
title:  "Supplementary Questions"
date:   2021-05-01 00:00:00 +0800
categories: jekyll update
---

These are a list of possibly thought-provoking questions that were intended to
enhance your learning for CS1010. This was prepared before/during the semester,
but I did not release it for fear of not being fair to the rest of the class. In
retrospect, it likely would not have mattered.  I've decided to release it here
for archival reasons.

## Numerical Length
We say that an algorithm is _efficient_ if the number of steps, $$S$$, it takes
to run is a _polynomial_ function of a size of the input, for all inputs.

For a polynomial-time algorithm with a single parameter $$n$$,

$$
S(n) = O(n^c)
$$

where $$c$$ is a constant. Examples would be functions such as $$O(n)$$,
$$O(n^2)$$, $$O(n \log n)$$, $$O(n^{10000})$$, etc. In contrast, an algorithm
is _inefficient_ if $$S$$ is _non-polynomial_ in the size of the input, for all
inputs. Examples include $$O(1.1^n)$$, $$O(2^n)$$, $$O(n!)$$, etc

* $$FindMax$$ is efficient, as $$S_{FindMax}(n) = O(n)$$
* $$Sudoku$$ is inefficient, as $$S_{Sudoku}(m,n) = O(m^n)$$

Consider the $$IsPrime$$ algorithm discussed frequently in class:

```c
algorithm IsPrime(n):
    if n <= 1:
        return FALSE
    for i in range[2,sqrt(n)]:
        if i divides n:
            return FALSE
    return TRUE
```

It seems that this function runs in a polynomial number of steps i.e
$$S_{IsPrime}(n) = O(\sqrt{n})$$. However, there is only one known polynomial-time prime-checking
algorithm, known as the [AKS Primality Test](https://en.wikipedia.org/wiki/AKS_primality_test), which runs in $$O(\log^6 n)$$.
So it seems that our $$IsPrime$$ must not be a polynomial-time algorithm.

Are you able to figure out why this is so?

_**Hint**: Think about the meaning of the "size of the input" in relation to an integer $$n$$_

## How does Free Know?
In C, when we pass arrays into functions, we _have_ to pass the size of the
array into the function, e.g

```c
int max(long *arr, long len)
{
    :
}

int main()
{
    long len = cs1010_read_long();
    long *arr = cs1010_read_long_array(len);
    long max = find_max(arr, len); // pass len here
    cs1010_println_long(max);
}
```

However, when we call `free` to free up memory that we have allocated on
the heap, we don't have to pass any length parameter. Take a guess why
this is so.

## Bug in Plain Sight
Consider the following C function that prints a string to the standard output,
but it does text wrapping (i.e continues printing on a new line) after every
79 characters in `data` printed. This is commonly done in console applications
to make text more readable.

```c
void print_as_text(char *data, int size)
{
    for (int i = 0; i < size; i++) {
        putchar(data[i]);
        // Use a standard 80 char width
        if (i + 1 % 80 == 0) {
            putchar('\n');
        }
    }
}
```

Compile the above function and run it with some input string with length greater
than 80, you should notice that it does not actually wrap text correctly.
Are you able to figure out why?

_**Note**: I was given this function in a skeleton in my Operating Systems class ;)_

## Read Word
Look at the code below for the definition of `cs1010_read_word()` [Source](https://github.com/nus-cs1010/libcs1010/blob/master/src/cs1010.c)

```c
char* cs1010_read_word()
{
    char buf[BUF_SIZE];
    char *ret = malloc(1);
    if (ret == NULL) {
        return NULL;
    }
    size_t total_len = 1;
    size_t len;

    int c = skip_space();
    if (c == EOF) {
        free(ret);
        printf("EOF encountered.    return NULL\n");
        return NULL;
    }
    *ret = (char)c;

    do {
        len = fill_buffer(buf, BUF_SIZE);
        char *temp = realloc(ret, (size_t)total_len + len + 1);
        if (temp == NULL) {
            free(ret);
            return NULL;
        }
        ret = temp;
        memcpy(ret + total_len, buf, (size_t)len); // concat the string
        total_len += len;
    } while (len == BUF_SIZE && buf[len-1] != 0);
    return ret;
}

int skip_space() {
    int c;
    do {
        c = fgetc(stdin);
    } while (isspace(c) && c != EOF);
    return c;
}

size_t fill_buffer(char *buf, size_t len) {
    int c;
    size_t i = 0;
    while (1) {
        c = fgetc(stdin);
        if (c == EOF || isspace(c)) {
            buf[i] = 0;
            return i + 1;
        }
        buf[i] = (char)c;
        i = i + 1;

        if (i == len) {
            return i;
        }
    }
}
```

* `memcpy(void *destination, void *source, size_t nbytes)` copies `nbytes` number of bytes starting from the pointer located at `source` to the pointer located at `destination`
* `int isspace(int arg)` returns a non-zero integer if `arg` is a space `' '` character with ASCII value 32, and zero otherwise
* `int fgetc(FILE *stream)` reads a single character from a specified `FILE` stream. In this case, calling `fgetc(stdin)` reads a single character from the standard input
* `EOF` (_end-of-file_) is a special character, with a value that is usually `-1`, that denotes the end of a file.

Write a rough description (in prose), how the `cs1010_read_word()` function works.

## Hopscotch
You are playing a special game of hopscotch on a special grid. We
represent the "squares" we are jumping in with a 1-dimensional array,
and we are initially positioned at index 0. At each square, we can either

* jump **1** square forward, or
* jump **2** squares forward

Fill up the brackets labeled with $$...$$ in the following recurrence relation:

$$
HopScotch(n) = H(n) =
\begin{cases}
1 & \text{ if } n = 1 \\
2 & \text{ if } n = 2 \\
H(...) + H(...) & \text{ otherwise}
\end{cases}
$$

_**Hint**: Work out the problem for small values of $$n$$ and guess the pattern._


## Set Equality
We define a _decision problem_ as a problem with a YES or NO answer. For example:
"_does there exist a element $$k$$ inside the list $$L$$?_" is a decision problem
as we can answer it with a YES or NO. In contrast, "_list out all indices $$i$$ for which $$L[i] = k$$_"
is not a decision problem.

We use the same definition of "efficient" as above i.e solvable in polynomial time.

Define the set of problems $$E$$, that contains all "easy" problems that can be solved
efficiently, and the set of "hard" problems $$H$$, that is the set of problems that
_may_ be able to be solved efficiently, but at least, a YES answer can be checked efficiently.

Do you think the above two sets are equivalent? i.e does $$E = H$$? Justify your answer.
