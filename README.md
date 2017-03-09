PetitPrince (UPEM C++ project)
=========================
## README

### Index

Symbols|Description
:----:|:----------
$|The command prompt.
~|Your home location
%ROOT|The project root location.
%HOST|The server hosting address (an ip or localhost)
%PORT|The server port listening (an integer between 1 and 32635). Should avoid known used port (i.e. 8080, TCP, SSH, etc...)


### Pre-Build

For each `idl` files there are two files existing: the `hh` and `cc` files.
If they do not exist, you have to pre-compile them:

```shell
$ cd %ROOT
$ omiidl -bcxx ServiceDraw.idl
```
This command create two files: `ServiceDraw.hh` and `ServiceDraw.cc`

### Build

There is a server and a client application.

```shell
$ cd %ROOT/server
$ make

$ cd %ROOT/client
$ make
```

These commands create two executables in %ROOT folder: `client` and `server`

### Run

First we need to invoke the server.
Open a new command prompt and type these commands:

```shell
$ cd %ROOT
$ ./server -h %HOST -p %PORT
```

Then, we are able to invoke the client(s).
Open a new command prompt for each client, and type these commands:

```shell
$ cd %ROOT
$ ./client -s %HOST
```
