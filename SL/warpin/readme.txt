
  SystemLoad
  ==========

SystemLoad can monitor the status of various system components on OS/2 and eCS.
It is a modular platform to display different data sets. The goal of this 
project is to provide a simple monitor tool for displaying dynamic information.
The feature set can be expanded with the help of dynamically loaded modules. 
To create your own modules take a look at the available source codes of 
already present modules and the examples.

The information is presented as a list of items and a details pane. Each
module defines itself how the items and the details pane interior will be
drawn. Note that you can drag and drop fonts and colors onto the list, items
and details pane.

The SL package includes several useful utilities:

cpuid.exe

  Generates the cpuid instruction that is available on x86 and x64 CPUs. This
  instruction queries the processor for information about the supported
  features and CPU type.

getver.exe

  Prints the version signature (BLDLEVEL) of the file which name is passed 
 in the parameters.

rxgetver.dll

  Reading version signatures (BLDLEVEL) in REXX scripts.
  rxgetver.cmd is an example for the REXX-library rxgetver.dll to read a 
  signature in REXX scripts.

sysstate.exe

  Query the system information about running processes, open files and dynamic
  loaded libraries.


Autor
-----

Special thanks to: AlexT, Slavik Gnatenko, fighter4.

Donations are most welcome!
https://www.arcanoae.com/shop/os2-ports-and-applications-by-andrey-vasilkin/
PayPal: digi@os2.snc.ru

Andrey Vasilkin, 2017
E-mail: digi@os2.snc.ru
Jabber: digi@frs.snc.ru
