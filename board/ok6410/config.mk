# On OK6410
# SDRAM begin from 0x50000000
# for 128 MB SDRAM, end at 0x57ffffff
# we load ourselves to
# to 0x57e00000 without MMU
# to 0xc7e00000 with MMU
# for 256 MB SDRAM, end at 0x5fffffff
# we load ourselves to
# to 0x5fe00000 without MMU
# to 0xcfe00000 with MMU
# download area is 0x5000c000
# Linux-Kernel is expected to be at 0x50008000, entry 0x50008000
sinclude $(OBJTREE)/board/$(BOARDDIR)/config.tmp

ifndef CONFIG_NAND_SPL
ifndef CONFIG_MMC_SPL
CONFIG_SYS_TEXT_BASE = $(RAM_TEXT)
else
CONFIG_SYS_TEXT_BASE = 0
endif
else
CONFIG_SYS_TEXT_BASE = 0
endif
