
INCLUDES  := execution.tex low-level-sys-info.tex development.tex      \
	     introduction.tex sw-installation.tex dl.tex libraries.tex \
	     macros.tex conventions.tex abi-index.tex

ALL_FILES := abi.tex $(INCLUDES)

.PHONY: all abi clean ps pdf update

# default
abi: abi.ps

all: abi.ps abi.pdf


abi.dvi: $(ALL_FILES)
	latex abi
	makeindex abi
	latex abi

pdf abi.pdf: $(ALL_FILES)
	pdflatex abi

ps abi.ps: abi.dvi
	dvips abi.dvi -o abi.ps
