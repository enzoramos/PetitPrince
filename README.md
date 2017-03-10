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

For each `idl` files there are three files existing: the `.hpp`, `_Stub.cpp` and `_DynStub.cpp` files.
If they do not exist, you have to pre-compile them:

```shell
$ cd %ROOT/idl/
$ omniidl -bcxx -Wba -Wbh=.hpp -Wbs=_Stub.cpp -Wbd=_DynStub.cpp -Wbuse_quotes ServiceDraw.idl
```
This command create three files: `ServiceDraw.hpp`, `ServiceDraw_Stub.cpp` and `ServiceDraw_DynStub.cpp`.
These files are located where you typed the `omniidl` command (i.e. `%ROOT/idl/` folder).
Next step is to move these files to a proper location:
> `.hpp` files go in `%ROOT/hdr/` folder 
> `.cpp` files go in `%ROOT/src/` folder

Finally, check if for each `idl` files there is a following lines in the file `%ROOT/nbproject/Makefile_Debug.mk`:
```Makefile
OBJECTFILE= \
    ${OBJECTDIR}/src/<idl_filename>_DynStub.o \
    ${OBJECTDIR}/src/<idl_filename>_Stub.o
```
*at line 37 (average)*

```Makefile
${OBJECTDIR}/src/<idl_filename>_DynStub.o: src/<idl_filename>_DynStub.cpp
        ${MKDIR} -p ${OBJECTDIR}/src
        ${RM} "$@.d"
        $(COMPILE.cc) -g -Ihdr -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/<idl_filename>_DynStub.o src/<idl_filename>_DynStub.cpp

${OBJECTDIR}/src/<idl_filename>_Stub.o: src/<idl_filename>_Stub.cpp
        ${MKDIR} -p ${OBJECTDIR}/src
        ${RM} "$@.d"
        $(COMPILE.cc) -g -Ihdr -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/<idl_filename>_Stub.o src/<idl_filename>_Stub.cpp
```
*at line 60 (average)*

If not, you have to manually add the files in Netbeans editor.
It will update all files properly.


### Build

There is a server and a client application.

```shell
$ cd %ROOT/server/
$ make

$ cd %ROOT/client/
$ make
```

These commands create two executables in %ROOT folder: `client` and `server`

### Run

First we need to invoke the server.
Open a new command prompt and type these commands:

```shell
$ cd %ROOT/
$ ./server -p %PORT
```

Then, we are able to invoke the client(s).
Open a new command prompt for each client, and type these commands:

```shell
$ cd %ROOT/
$ ./client -h %HOST -p %PORT
```
