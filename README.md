# minishell
A shell with basic builtins, pipes, env variables, redirections among other things.

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)

## Usage

In the root of the repo, run:
```bash
make
```

Once the binary is created, run:
```bash
./minishell
```

Then you can use it as a basic minishell, try these commands:
```bash
./minishell
echo 'hello world'
cat Makefile
ls | grep file
cd src
echo 'hello' > myfile.txt | echo "world" >> myfile.txt | cat myfile.txt
bao
sophie 4
exit
```


## Subject
[minishell.pdf](https://github.com/pnielly/minishell/files/8933903/minishell.pdf)
