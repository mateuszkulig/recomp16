#include <stdio.h>
#include <inttypes.h>

#include <capstone/capstone.h>

// this is the example code from https://www.capstone-engine.org/lang_c.html 
int dissasemblerTest(void)
{
	char CODE[9] = "\x55\x48\x8b\x05\xb8\x13\x00\x00";
	csh handle;
	cs_insn *insn;
	size_t count;
	int a;

	if (cs_open(CS_ARCH_X86, CS_MODE_64, &handle) != CS_ERR_OK)
		return -1;
	count = cs_disasm(handle, CODE, sizeof(CODE)-1, 0x1000, 0, &insn);
	if (count > 0) {
		size_t j;
		for (j = 0; j < count; j++) {
			printf("0x%"PRIx64":\t%s\t\t%s\n", insn[j].address, insn[j].mnemonic,
					insn[j].op_str);
		}

		cs_free(insn, count);
	} else
		printf("ERROR: Failed to disassemble given code!\n");

	cs_close(&handle);

	return 0;
}