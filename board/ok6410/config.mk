sinclude $(OBJTREE)/board/$(BOARDDIR)/config.tmp

ifndef CONFIG_NAND_SPL
CONFIG_SYS_TEXT_BASE = $(RAM_TEXT)
else
CONFIG_SYS_TEXT_BASE = 0
endif
