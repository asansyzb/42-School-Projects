# Libft
Implementation of some of the Standard C Library functions including some additional ones.

### Contents
* [What is libft?](#what-is-libft)
* [What's in it?](#whats-in-it)
* [How does it work?](#how-does-it-work)
* [How do I use the library?](#how-do-i-use-the-library)
* [How do I test it? How do I test my own implementations?](#how-do-i-test-it-how-do-i-test-my-own-implementations)

### What is libft?
[Libft][1] is an individual project at [42][2] that requires us to re-create some standard C library functions including some additional ones.

Disclaimer: *Reinventing the wheel is bad, 42 makes us do this just so we can have a deeper understanding of data structures and basic algorithms. At 42 we're not allowed to use some standard libraries on our projects, so we have to keep growing this library with our own functions as we go farther in the program.*

### What's in it?

As you can see from the [Project instructions][1], there are 4 sections:

1.  **Libc Functions:** Standard C functions
2.  **Additional functions:** Useful functions
3.  **Bonus Functions:** Linked list functions
4.  **Personal Functions:** Functions I use frequently in other projects.

Libc functions | Additional functions | Bonus Functions | Personal Functions
:----------- | :-----------: | :-----------: | -----------:
memset		| ft_memalloc	| ft_lstnew		| btree_apply_infix 
bzero		| ft_memdel		| ft_lstdelone	| btree_apply_prefix 
memcpy		| ft_strnew		| ft_lstdel		| btree_apply_suffix    
memccpy		| ft_strdel		| ft_lstadd		| btree_create_node    
memmove		| ft_strclr		| ft_lstiter	| btree_insert_data    
memchr		| ft_striter	| ft_lstmap		| btree_level_count
memcmp		| ft_striteri	|				| btree_search_item
strlen		| ft_strmap		|				| ft_strndup
strdup		| ft_strmapi	|				| ft_max
strcpy		| ft_strequ		|				| ft_min
strncpy		| ft_strnequ	|			| ft_strupd
strcat		| ft_strsub		| | ft_swap
strlcat		| ft_strjoin	| | 
strchr		| ft_strtrim	| | 
strrchr		| ft_strsplit	| | 
strstr		| ft_itoa		| | 
strnstr		| ft_putchar	| | 
strcmp		| ft_putstr		| | 
strncmp		| ft_putendl	| | 
atoi		| ft_putnbr		| | 
isalpha		| ft_putchar_fd	| | 
isdigit		| ft_putstr_fd	| | 
isalnum		| ft_putendl_fd	| | 
isascii		| ft_putnbr_fd	| | 
isprint		|| | 
toupper		| | | 
tolower		| | | 


Notes:

- Most of the the files and function names are namespaced with an **ft** in front. It stands for Fourty Two (name of the school).

### How does it work?

The goal is to create a library called libft.a from the source files so I can later use that library from other projects at 42.

To create that library, after downloading/cloning this project, **cd** into the project, copy all the files from the sub folders to the root directory and finally, call make:

	cd libft
	make

You should see a *libft.a* file and some object files (.o).


To clean up:
1. call `make clean` (removing the .o files from the root).
2. call `make fclean` (removing the .o and .a files from the root).

### How do I use the library?

You have to tell the file where your library resides and which library it is using:

`gcc example.c -L. -lft -o example`

-L takes the path to your library. `.` in this case<br>
-l takes the name of your library. This is the set of characters that come after `lib` in your library name.

That's it. Now run it using `./example.out`

### How do I test it? How do I test my own implementations?

To test the code we're going to be using @alelievr's [Libft Unit Test][4]. There are [some][5] [good][6] [others][7] but I'll only be covering this one.

All of the instructions I used was copied/paraphrased from [other 42 student][19].

Have fun :)

[1]: https://github.com/Aliba777/42-School-Projects/blob/master/libft/libft.en.pdf "Libft PDF"
[2]: http://42.us.org "42 USA"
[3]: https://github.com/R4meau/libft/wiki/Personal-Functions-Documentation
[4]: https://github.com/alelievr/libft-unit-test
[5]: https://github.com/yyang42/moulitest
[6]: https://github.com/QuentinPerez/Maintest/tree/master/libft
[7]: https://github.com/Kant1-0/libft-test
[19]: https://github.com/R4meau/
