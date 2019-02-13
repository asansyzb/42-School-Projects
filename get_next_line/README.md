# get_next_line

A C function that reads any valid file line by line until the end from a file descriptor.

### Contents
* [What is get_next_line?](#what-is-get_next_line)
* [Why would I use/try it?](#why-would-i-usetry-it)
* [How do I use it?](#how-do-i-use-it)
* [How do I test my own code?](#how-do-i-test-my-own-code)

### What is get_next_line?

[get_next_line][1] is an individual project at [42][2] that teaches you how to open/write data in a file, and how to manage memory (does not contain memory leaks).


### Why would I use/try it?

The goal is to get better at C, and understand memory management. You can only use those three standard library functions:

* read
* malloc
* free

, but you can also use functions from your [personal library][14].

To make code even better, I decided to implement the function in less than 25 lines (we have a norm of coding at 42 School, such as 1 function should have only 25 lines of code).

### How do I use it?

I added a file called **test.c**, it takes a file name as an argument, opens it and passes the file descriptor (fd) to get_next_line until get_next_line returns -1 or 0.

**Note:** get_next_line returns -1, 0, 1 depending on wether an error has occurred, the reading has been completed or a line has been read respectively.

Download/clone this repo.
	
Get into it and build the library:
	
	cd get_next_line
	make -C libft/

Build the executable:
	
	gcc -Wall -Wextra -Werror -I./libft/ -L./libft -lft -o gnl get_next_line.c test.c

-I tells the compiler where your library header files are. `./libft/` in this case

-L tells it where your library resides. `./libft` here

-l takes the name of your library. This is the set of characters that come after `lib` in your library name.

**NOTE:** -L and -l might look a little bit too much, you could replace those flags with `libft/libft.a` if you want.

Alright, the last command created a `gnl` executable in your directory. Now test it with:

	./gnl sample.txt

It should read the whole file to you. Kinda like a basic `cat` implementation.

**NOTE:** The poem in the text file is [Abai Qunanbaiv's][15] famous [Black Of My Eye][16] ;)

#### How do I test my own code?

You can do as [above](#how-do-i-use-it) and use the `test.c` file I added. This is a pretty rudimentary test, if you want to try some deep tests, let me introduce you to the amazing [42FileChecker][17] by [@jgigault][18].

Assuming you read the project instructions and coded your own get_next_line
		
1. Go back to the root directory and download @jgigault's 42FileChecker:

		cd ..
		git clone https://github.com/jgigault/42FileChecker
		
2. Go into the test folder and run the test:

		cd 42FileChecker
		sh 42FileChecker.sh

Press `5` to select tests for get_next_line, press `1` to install [moulitest][5] as an external repo, then `1` to configure the tests, now you handle the path to your get_next_line and then choose which test to run on your project.

All of the instructions I used was copied/paraphrased from [other 42 student][19].

Have fun :)

[1]: https://github.com/Aliba777/42-School-Projects/blob/master/get_next_line/get_next_line.en.pdf "get_next_line PDF"
[2]: http://42.us.org "42 USA"
[5]: https://github.com/yyang42/moulitest
[14]: https://github.com/Aliba777/42-School-Projects/tree/master/libft
[15]: https://en.wikipedia.org/wiki/Abai_Qunanbaiuly
[16]: https://www.poemhunter.com/poem/black-of-my-eye/
[17]: https://github.com/jgigault/42FileChecker
[19]: https://github.com/R4meau/
