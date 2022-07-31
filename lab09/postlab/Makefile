CXX	= clang++ -m64

# Defines the flags we'll be passing to the C++ compiler                       
CXXFLAGS	= -Wall -g

# Defines the assembler                                                        
AS	= nasm

# Defines the flags for the assembler                                          
ASFLAGS = -f elf64 -g

# All of the .o files for our program                                          
OFILES	= timer.o threexplusone.o threexinput.o
# This tells make to create a .o file from a .cpp file, using the              
# defaults above (i.e. the CXX and CXXFLAGS macros)                            
.SUFFIXES: .o .s

main:	$(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)

# This will clean up (remove) all our object files.  The -f option             
# tells rm to forcily remove the files (i.e. don't ask if they should          
# be removed or not).  This removes object files (*.o) and Emacs               
# backup files (*~)                                                            
clean:
	/bin/rm -f *.o *~
