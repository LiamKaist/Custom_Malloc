
arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -c -o malloc.o malloc.c

arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -c -o main.o main.c

arm-none-eabi-ld -T malloc.ld -o malloc.elf malloc.o main.o

arm-none-eabi-objcopy -O binary malloc.elf malloc.bin

hexdump -vC malloc.bin

st-flash write malloc.bin 0x08000000