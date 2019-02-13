# printf

Because I’m tired of using putnbr and putstr.

### Contents
* [What is ft_printf?](#what-is-ft_printf)
* [Why would I use/try it?](#why-would-i-usetry-it)
* [How do I use it?](#how-do-i-use-it)
* [How do I test my own code?](#how-do-i-test-my-own-code)

### What is printf?

[ft_printf][1] is an individual project at [42][2] that teaches you how to structure a big project by implementing standard C printf function, and follow **DRY** (Don't Repeat Yourself) approach of software development.

### Why would I use/try it?

The goal is to get better at management of bigger projects.

You can use only functions from your [personal library][14].

### How do I use it?

I added a file called **main.c**, which simply prints out "Hello world" on the terminal.

Download/clone this repo
	
Get into it and build the library:
	
	cd printf
	make

Compile the executable:
	
	gcc -Wall -Wextra -Werror main.c -L. libftprintf.a -o ft_printf

Alright, the last command created a `ft_printf` executable in your directory. Now test it with:

	./ft_printf

It should print out "Hello world" on the terminal.


#### How do I test my own code?

1. Go back to the root directory and download @jgigault's [42FileChecker][17]:

		cd ..
		git clone https://github.com/jgigault/42FileChecker
		
2. Go into the test folder and run the test:

		cd 42FileChecker
		sh 42FileChecker.sh


Press `7` to select tests for ft_printf, press `1` to install [moulitest][5] as an external repo, then `1` to configure the tests, now you handle the path to your ft_printf and then choose which test to run on your project.

Have fun :)

[1]: https://github.com/Aliba777/42-School-Projects/blob/master/printf/ft_printf.en.pdf "printf PDF"
[2]: http://42.us.org "42 USA"
[5]: https://github.com/yyang42/moulitest
[14]: https://github.com/Aliba777/42-School-Projects/tree/master/libft
[17]: https://github.com/jgigault/42FileChecker
