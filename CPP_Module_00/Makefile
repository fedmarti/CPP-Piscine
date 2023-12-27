C=c++

FLAGS=-Wall -Wextra -Werror -std=c++98 -g

INPUT:= $(shell bash -c read -pinput)

ex%:
	@# mkdir $@
	@# @echo -n executable name:
	@echo $(INPUT);
	@# @$(ifneq ($(strip $(INPUT)), ,)
	@# echo -n NAME= > $@/Makefile;
	@# @echo $(firstword $(INPUT)) >> $@/Makefile;
	@# endif);
	@# @cat maketemplate >> $@/Makefile

%.cpp: 
	$(C) $(FLAGS) $<


