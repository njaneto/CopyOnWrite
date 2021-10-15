ifndef PROJECT_BASE
	export PROJECT_BASE=${shell pwd}
endif

.DEFAULT: all

clean : all
all :
	$(MAKE) -C src/			$(MAKECMDGOALS)
	$(MAKE) -C testSuite/	$(MAKECMDGOALS)
	