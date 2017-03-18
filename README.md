PetitPrince (UPEM C++/CORBA project)
=========================
## README

### Documentation

The documentation was auto-generated by Doxygen.
Each projects Server and Client own their documentation in the `doc` folder.
The documentation exists as `HTML` and `LaTex` format.
The `HTML` format can be opened by reaching the `index.html` file in a browser.

### Index

Symbols|Description
:----:|:----------
$|The command prompt.
~|Your home location
%ROOT|The project root location.
%HOST|The server hosting address (an ip or localhost).
%PORT|The server port listening (an integer between 1 and 32635). Should avoid known used port (i.e. 8080, TCP, SSH, etc...)

The project is divided in three parts: a master project, a client project and a server project.
The master project provide a global Makefile that call the Makefiles of sub projects and own the `idl`, this `README` files and the states of the project.
The two sub projects (_Client and _Server) are located into the master project.
The server own every sources needed to run properly the application (serve the client) and a `main_server.cpp`.
The client only own the sources generated by the `idl` (needed to know interfaces) and a `main_client.cpp`.

### Pre-Build

There is a unique `idl` file named `PetitPrince.idl`.
Compiling an `idl` file generate three files: `.hpp`, `_Stub.cpp` and `_DynStub.cpp` files.
In order to compile the `idl` file you have run OmniORB compiler:
```shell
$ cd %ROOT/idl/
$ omniidl -bcxx -Wba -Wbh=.hpp -Wbs=_Stub.cpp -Wbd=_DynStub.cpp -Wbuse_quotes PetitPrince.idl
```
This command create three files: `PetitPrince.hpp`, `PetitPricne_Stub.cpp` and `PetitPrince_DynStub.cpp`.
These files are located where you typed the `omniidl` command (i.e. `%ROOT/idl/` folder).
Next step is to move these files to a proper location (in client and server projects):
```shell
cp *.hpp %ROOT/PetitPrince_Client/hdr
cp *.cpp %ROOT/PetitPrince_Client/src
cp *.hpp %ROOT/PetitPrince_Server/hdr
cp *.cpp %ROOT/PetitPrince_Server/src
```

Finally, check if there are following lines:
```Makefile
OBJECTFILE= \
    ${OBJECTDIR}/src/<idl_filename>_DynStub.o \
    ${OBJECTDIR}/src/<idl_filename>_Stub.o
```
*at line 37 (average)*

in the files:
`%ROOT/PetitPrince_Client/nbproject/Makefile_Debug.mk`
`%ROOT/PetitPrince_Server/nbproject/Makefile_Debug.mk`

and

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

2 way to build the project:
either, you use the global Makefile in the master project:
```shell
$ cd %ROOT/
$ make
```
either, you manually compile each projects:
```shell
$ cd %ROOT/PetitPrince_Server/
$ make

$ cd %ROOT/PetitPrince_Client/
$ make
```
These commands create two executable:
> `%ROOT/PetitPrince_Client/dist/Debug/GNU-Linux/petitprince_client`
> `%ROOT/PetitPrince_Server/dist/Debug/GNU-Linux/petitprince_server`

### Run
First we need to start the Naming Service deamon.
Open a new command prompt and type these commands:
```shell
$ omniNames &
```
*this command may require `su` privileges.*

Then we need to invoke the server.
Open a new command prompt and type these commands:
```shell
$ cd %ROOT/PetitPrince_Server/dist/Debug/GNU-Linux
$ ./petitprince_server -ORBInitRef NameService=corbaloc:iiop:%HOST:%PORT/NameService
```

Finally, we are able to invoke the client(s).
Open a new command prompt for each client, and type these commands:

```shell
$ cd %ROOT/PetitPrince_Client/dist/Debug/GNU-Linux
$ ./petitprince_client -ORBInitRef NameService=corbaloc:iiop:%HOST:%PORT/NameService
```
