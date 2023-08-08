MEMORY {
    flash (RX) : ORIGIN = 0x08000000 , LENGTH = 128K
    sram (! RX) : ORIGIN = 0x20000000, LENGTH = 16K 
}

SECTIONS {
    .vectors : { *(.vectors) } >flash
    .text : { *(.text) } >flash
    .rodata : { *(.rodata) } >flash
    .bss : { *(.bss) } >sram
}
