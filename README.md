# PIPEX

# Project

The goal of the Pipex project is to recreate the pipe system present in the bash.
- Exemple : ls | grep foo

Bonuses offer the possibility to recreate an infinity of pipes as well as the here_document function.

## Usage

- Clone Repository
```bash
git clone https://github.com/vvaucoul/Pipex && cd Pipex
```

- Compilation
```bash
make
```

- Start
```bash
./pipex infile cmd1 cmd2 outfile
```

## Example

```bash
touch foo && ./pipex foo "echo bar" cat foo && cat foo
```

Result: "bar"

# Ressources

- [Pipes](http://www.zeitoun.net/articles/communication-par-tuyau/start)
- [HereDoc](https://linuxize.com/post/bash-heredoc/)
