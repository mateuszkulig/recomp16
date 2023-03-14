#include <stdio.h>
// #include <inttypes.h>
#include <capstone/capstone.h>

void disassembleCode(uint8_t *code, size_t bytesLen)
{
	csh handle;
	cs_insn *insn;
	size_t count;

	cs_open(CS_ARCH_X86, CS_MODE_16, &handle);
	count = cs_disasm(handle, code, bytesLen, 0x0000, 0, &insn);
	
	for (size_t i = 0; i < count; ++i) {
		printf("0x%llx:\t%s\t\t%s\n", insn[i].address, insn[i].mnemonic, insn[i].op_str);
	}
	cs_free(insn, count);
	cs_close(&handle);
}