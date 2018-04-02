#ifndef _OPCODE_H
#define _OPCODE_H

#include <stdint.h>

#define OPCODE_EXTENDED (0xCB)

// Opcode type enumeration
enum OPCODE_TYPE{
	NONE,
	IMMEDIATE,
	INDIRECT,
	ABSOLUTE,
	RELATIVE,
	EXTENDED, // Go to page1 for rest of opcode
	ILLEGAL // Illegal opcode
};

// Opcode structure
typedef struct{
	uint8_t opcode;
	const char *mnemonic;
	uint8_t size;
	uint8_t clock_cycles;
	enum OPCODE_TYPE type;
	const char *description;
}Opcode;

const Opcode page0[0x100] = {
	{0x00, "NOP", 1, 4, NONE, "No Operation"},
	{0x01, "LD BC, #%04X", 3, 12, IMMEDIATE, "Load #%04X to BC"},
	{0x02, "LD (BC), A", 1, 8, IMMEDIATE, "Load A to (BC)"},
	{0x03, "INC BC", 1, 8, IMMEDIATE, "Increment BC"},
	{0x04, "INC B", 1, 4, IMMEDIATE, "Increment B"},
	{0x05, "DEC B", 1, 4, IMMEDIATE, "Decrement B"},
	{0x06, "LD B, #%02X", 2, 8, IMMEDIATE, "Load #%02X to B"},
	{0x07, "RLCA", 1, 4, IMMEDIATE, "Rotate A Left to Carry"},
	{0x08, "LD $%04X, SP", 3, 20, INDIRECT, "Load SP to $%04X"},
	{0x09, "ADD HL, BC", 1, 8, IMMEDIATE, "Add BC to HL"},
	{0x0A, "LD A, (BC)", 1, 8, INDIRECT, "Load (BC) to A"},
	{0x0B, "DEC BC", 1, 8, IMMEDIATE, "Decrement BC"},
	{0x0C, "INC C", 1, 4, IMMEDIATE, "Increment C"},
	{0x0D, "DEC C", 1, 4, IMMEDIATE, "Decrement C"},
	{0x0E, "LD C, #%02X", 2, 8, IMMEDIATE, "Load #%02X to C"},
	{0x0F, "RRCA", 1, 4, IMMEDIATE, "Rotate A Right to Carry"},

	{0x10, "STOP", 1, 4, NONE, "Stop CPU & LCD until button press"},
	{0x11, "LD DE, #%04X", 3, 12, IMMEDIATE, "Load #%04X to DE"},
	{0x12, "LD (DE), A", 1, 8, INDIRECT, "Load A to (DE)"},
	{0x13, "INC DE", 1, 8, IMMEDIATE, "Increment DE"},
	{0x14, "INC D", 1, 4, IMMEDIATE, "Increment D"},
	{0x15, "DEC D", 1, 4, IMMEDIATE, "Decrement D"},
	{0x16, "LD D, #%02X", 2, 8, IMMEDIATE, "Load #%02X to D"},
	{0x17, "RLA", 1, 4, IMMEDIATE, "Rotate A Left"},
	{0x18, "JR #%02X", 2, 8, RELATIVE, "Jump Relative #%02X"},
	{0x19, "ADD HL, DE", 1, 8, IMMEDIATE, "Add DE to HL"},
	{0x1A, "LD A, (DE)", 1, 8, INDIRECT, "Load (DE) to A"},
	{0x1B, "DEC DE", 1, 8, IMMEDIATE, "Decrement DE"},
	{0x1C, "INC E", 1, 4, IMMEDIATE, "Increment E"},
	{0x1D, "DEC E", 1, 4, IMMEDIATE, "Decrement E"},
	{0x1E, "LD E, #%02X", 2, 8, IMMEDIATE, "Load #%02X to E"},
	{0x1F, "RRA", 1, 4, IMMEDIATE, "Rotate A Right"},

	{0x20, "JR NZ, #%02X", 2, 8, RELATIVE, "Jump Relative #%02X if non-Zero"},
	{0x21, "LD HL, #%04X", 3, 12, IMMEDIATE, "Load #%04X to HL"},
	{0x22, "LD (HL+), A", 1, 8, IMMEDIATE, "Load A to (HL), increment (HL)"},
	{0x23, "INC HL", 1, 8, IMMEDIATE, "Increment HL"},
	{0x24, "INC H", 1, 4, IMMEDIATE, "Increment H"},
	{0x25, "DEC H", 1, 4, IMMEDIATE, "Decrement H"},
	{0x26, "LD H, #%02X", 2, 8, IMMEDIATE, "Load #%02X to H"},
	{0x27, "DAA", 1, 4, IMMEDIATE, "Decimal Adjust A"},
	{0x28, "JR Z, #%02X", 2, 8, RELATIVE, "Jump Relative #%02X if Zero"},
	{0x29, "ADD HL, HL", 1, 8, IMMEDIATE, "Add HL to HL"},
	{0x2A, "LD A, (HL+)", 1, 8, INDIRECT, "Load (HL) to A, increment (HL)"},
	{0x2B, "DEC HL", 1, 8, IMMEDIATE, "Decrement HL"},
	{0x2C, "INC L", 1, 4, IMMEDIATE, "Increment L"},
	{0x2D, "DEC L", 1, 4, IMMEDIATE, "Decrement L"},
	{0x2E, "LD L, #%02X", 2, 8, IMMEDIATE, "Load #%02X to L"},
	{0x2F, "CPL", 1, 4, IMMEDIATE, "Complement A"},

	{0x30, "JR NC, #%02X", 2, 8, RELATIVE, "Jump Relative #%02X if no-Carry"},
	{0x31, "LD SP, #%04X", 3, 12, IMMEDIATE, "Load #%04X to SP"},
	{0x32, "LD (HL-), A", 1, 8, IMMEDIATE, "Load A to (HL), decrement (HL)"},
	{0x33, "INC SP", 1, 8, IMMEDIATE, "Increment SP"},
	{0x34, "INC (HL)", 1, 12, INDIRECT, "Increment (HL)"},
	{0x35, "DEC (HL)", 1, 12, INDIRECT, "Decrement (HL)"},
	{0x36, "LD (HL), #%02X", 2, 12, IMMEDIATE, "Load #%02X to (HL)"},
	{0x37, "SCF", 1, 4, IMMEDIATE, "Set Carry Flag"},
	{0x38, "JR C, #%02X", 2, 8, RELATIVE, "Jump Relative #%02X if Carry"},
	{0x39, "ADD HL, SP", 1, 8, IMMEDIATE, "Add SP to HL"},
	{0x3A, "LD A, (HL-)", 1, 8, INDIRECT, "Load #(HL) to A, decrement (HL)"},
	{0x3B, "DEC SP", 1, 8, IMMEDIATE, "Decrement SP"},
	{0x3C, "INC A", 1, 4, IMMEDIATE, "Increment A"},
	{0x3D, "DEC A", 1, 4, IMMEDIATE, "Decrement A"},
	{0x3E, "LD A, #%02X", 2, 8, IMMEDIATE, "Load #%02X to A"},
	{0x3F, "CCF", 1, 4, IMMEDIATE, "Complement Carry Flag"},

	{0x40, "LD B, B", 1, 4, IMMEDIATE, "Load B to B"},
	{0x41, "LD B, C", 1, 4, IMMEDIATE, "Load C to B"},
	{0x42, "LD B, D", 1, 4, IMMEDIATE, "Load D to B"},
	{0x43, "LD B, E", 1, 4, IMMEDIATE, "Load E to B"},
	{0x44, "LD B, H", 1, 4, IMMEDIATE, "Load H to B"},
	{0x45, "LD B, L", 1, 4, IMMEDIATE, "Load L to B"},
	{0x46, "LD B, (HL)", 1, 8, INDIRECT, "Load (HL) to B"},
	{0x47, "LD B, A", 1, 4, IMMEDIATE, "Load A to B"},
	{0x48, "LD C, B", 1, 4, IMMEDIATE, "Load B to C"},
	{0x49, "LD C, C", 1, 4, IMMEDIATE, "Load C to C"},
	{0x4A, "LD C, D", 1, 4, IMMEDIATE, "Load D to C"},
	{0x4B, "LD C, E", 1, 4, IMMEDIATE, "Load E to C"},
	{0x4C, "LD C, H", 1, 4, IMMEDIATE, "Load H to C"},
	{0x4D, "LD C, L", 1, 4, IMMEDIATE, "Load L to C"},
	{0x4E, "LD C, (HL)", 1, 8, INDIRECT, "Load (HL) to C"},
	{0x4F, "LD C, A", 1, 4, IMMEDIATE, "Load A to C"},

	{0x50, "LD D, B", 1, 4, IMMEDIATE, "Load B to D"},
	{0x51, "LD D, C", 1, 4, IMMEDIATE, "Load C to D"},
	{0x52, "LD D, D", 1, 4, IMMEDIATE, "Load D to D"},
	{0x53, "LD D, E", 1, 4, IMMEDIATE, "Load E to D"},
	{0x54, "LD D, H", 1, 4, IMMEDIATE, "Load H to D"},
	{0x55, "LD D, L", 1, 4, IMMEDIATE, "Load L to D"},
	{0x56, "LD D, (HL)", 1, 8, INDIRECT, "Load (HL) to D"},
	{0x57, "LD D, A", 1, 4, IMMEDIATE, "Load A to D"},
	{0x58, "LD E, B", 1, 4, IMMEDIATE, "Load B to E"},
	{0x59, "LD E, C", 1, 4, IMMEDIATE, "Load C to E"},
	{0x5A, "LD E, D", 1, 4, IMMEDIATE, "Load D to E"},
	{0x5B, "LD E, E", 1, 4, IMMEDIATE, "Load E to E"},
	{0x5C, "LD E, H", 1, 4, IMMEDIATE, "Load H to E"},
	{0x5D, "LD E, L", 1, 4, IMMEDIATE, "Load L to E"},
	{0x5E, "LD E, (HL)", 1, 8, INDIRECT, "Load (HL) to E"},
	{0x5F, "LD E, A", 1, 4, IMMEDIATE, "Load A to E"},

	{0x60, "LD H, B", 1, 4, IMMEDIATE, "Load B to H"},
	{0x61, "LD H, C", 1, 4, IMMEDIATE, "Load C to H"},
	{0x62, "LD H, D", 1, 4, IMMEDIATE, "Load D to H"},
	{0x63, "LD H, E", 1, 4, IMMEDIATE, "Load E to H"},
	{0x64, "LD H, H", 1, 4, IMMEDIATE, "Load H to H"},
	{0x65, "LD H, L", 1, 4, IMMEDIATE, "Load L to H"},
	{0x66, "LD H, (HL)", 1, 8, INDIRECT, "Load (HL) to H"},
	{0x67, "LD H, A", 1, 4, IMMEDIATE, "Load A to H"},
	{0x68, "LD L, B", 1, 4, IMMEDIATE, "Load B to L"},
	{0x69, "LD L, C", 1, 4, IMMEDIATE, "Load C to L"},
	{0x6A, "LD L, D", 1, 4, IMMEDIATE, "Load D to L"},
	{0x6B, "LD L, E", 1, 4, IMMEDIATE, "Load E to L"},
	{0x6C, "LD L, H", 1, 4, IMMEDIATE, "Load H to L"},
	{0x6D, "LD L, L", 1, 4, IMMEDIATE, "Load L to L"},
	{0x6E, "LD L, (HL)", 1, 8, INDIRECT, "Load (HL) to L"},
	{0x6F, "LD L, A", 1, 4, IMMEDIATE, "Load A to L"},

	{0x70, "LD (HL), B", 1, 8, IMMEDIATE, "Load B to (HL)"},
	{0x71, "LD (HL), C", 1, 8, IMMEDIATE, "Load C to (HL)"},
	{0x72, "LD (HL), D", 1, 8, IMMEDIATE, "Load D to (HL)"},
	{0x73, "LD (HL), E", 1, 8, IMMEDIATE, "Load E to (HL)"},
	{0x74, "LD (HL), H", 1, 8, IMMEDIATE, "Load H to (HL)"},
	{0x75, "LD (HL), L", 1, 8, IMMEDIATE, "Load L to (HL)"},
	{0x76, "HALT", 1, 4, NONE, "Halt CPU until intterupt"},
	{0x77, "LD (HL), A", 1, 8, INDIRECT, "Load A to (HL)"},
	{0x78, "LD A, B", 1, 4, IMMEDIATE, "Load B to A"},
	{0x79, "LD A, C", 1, 4, IMMEDIATE, "Load C to A"},
	{0x7A, "LD A, D", 1, 4, IMMEDIATE, "Load D to A"},
	{0x7B, "LD A, E", 1, 4, IMMEDIATE, "Load E to A"},
	{0x7C, "LD A, H", 1, 4, IMMEDIATE, "Load H to A"},
	{0x7D, "LD A, L", 1, 4, IMMEDIATE, "Load L to A"},
	{0x7E, "LD A, (HL)", 1, 8, INDIRECT, "Load (HL) to A"},
	{0x7F, "LD A, A", 1, 4, IMMEDIATE, "Load A to A"},

	{0x80, "ADD A, B", 1, 4, IMMEDIATE, "Add B to A"},
	{0x81, "ADD A, C", 1, 4, IMMEDIATE, "Add C to A"},
	{0x82, "ADD A, D", 1, 4, IMMEDIATE, "Add D to A"},
	{0x83, "ADD A, E", 1, 4, IMMEDIATE, "Add E to A"},
	{0x84, "ADD A, H", 1, 4, IMMEDIATE, "Add H to A"},
	{0x85, "ADD A, L", 1, 4, IMMEDIATE, "Add L to A"},
	{0x86, "ADD A, (HL)", 1, 8, INDIRECT, "Add (HL) to A"},
	{0x87, "ADD A, A", 1, 4, IMMEDIATE, "Add A to A"},
	{0x88, "ADC A, B", 1, 4, IMMEDIATE, "Add B to A with Carry"},
	{0x89, "ADC A, C", 1, 4, IMMEDIATE, "Add C to A with Carry"},
	{0x8A, "ADC A, D", 1, 4, IMMEDIATE, "Add D to A with Carry"},
	{0x8B, "ADC A, E", 1, 4, IMMEDIATE, "Add E to A with Carry"},
	{0x8C, "ADC A, H", 1, 4, IMMEDIATE, "Add H to A with Carry"},
	{0x8D, "ADC A, L", 1, 4, IMMEDIATE, "Add L to A with Carry"},
	{0x8E, "ADC A, (HL)", 1, 8, INDIRECT, "Add (HL) to A with Carry"},
	{0x8F, "ADC A, A", 1, 4, IMMEDIATE, "Add A to A with Carry"},

	{0x90, "SUB B", 1, 4, IMMEDIATE, "Subtract B from A"},
	{0x91, "SUB C", 1, 4, IMMEDIATE, "Subtract C from A"},
	{0x92, "SUB D", 1, 4, IMMEDIATE, "Subtract D from A"},
	{0x93, "SUB E", 1, 4, IMMEDIATE, "Subtract E from A"},
	{0x94, "SUB H", 1, 4, IMMEDIATE, "Subtract H from A"},
	{0x95, "SUB L", 1, 4, IMMEDIATE, "Subtract L from A"},
	{0x96, "SUB (HL)", 1, 8, INDIRECT, "Subtract (HL) from A"},
	{0x97, "SUB A", 1, 4, IMMEDIATE, "Subtract A from A"},
	{0x98, "SBC A, B", 1, 4, IMMEDIATE, "Subtract B from A with Carry"},
	{0x99, "SBC A, C", 1, 4, IMMEDIATE, "Subtract C from A with Carry"},
	{0x9A, "SBC A, D", 1, 4, IMMEDIATE, "Subtract D from A with Carry"},
	{0x9B, "SBC A, E", 1, 4, IMMEDIATE, "Subtract E from A with Carry"},
	{0x9C, "SBC A, H", 1, 4, IMMEDIATE, "Subtract H from A with Carry"},
	{0x9D, "SBC A, L", 1, 4, IMMEDIATE, "Subtract L from A with Carry"},
	{0x9E, "SBC A, (HL)", 1, 8, INDIRECT, "Subtract (HL) from A with Carry"},
	{0x9F, "SBC A, A", 1, 4, IMMEDIATE, "Subtract A from A with Carry"},

	{0xA0, "AND B", 1, 4, IMMEDIATE, "And B with A"},
	{0xA1, "AND C", 1, 4, IMMEDIATE, "And C with A"},
	{0xA2, "AND D", 1, 4, IMMEDIATE, "And D with A"},
	{0xA3, "AND E", 1, 4, IMMEDIATE, "And E with A"},
	{0xA4, "AND H", 1, 4, IMMEDIATE, "And H with A"},
	{0xA5, "AND L", 1, 4, IMMEDIATE, "And L with A"},
	{0xA6, "AND (HL)", 1, 8, INDIRECT, "And (HL) with A"},
	{0xA7, "AND A", 1, 4, IMMEDIATE, "And A with A"},
	{0xA8, "XOR B", 1, 4, IMMEDIATE, "Xor B with A"},
	{0xA9, "XOR C", 1, 4, IMMEDIATE, "Xor C with A"},
	{0xAA, "XOR D", 1, 4, IMMEDIATE, "Xor D with A"},
	{0xAB, "XOR E", 1, 4, IMMEDIATE, "Xor E with A"},
	{0xAC, "XOR H", 1, 4, IMMEDIATE, "Xor H with A"},
	{0xAD, "XOR L", 1, 4, IMMEDIATE, "Xor L with A"},
	{0xAE, "XOR (HL)", 1, 8, INDIRECT, "Xor (HL) with A"},
	{0xAF, "XOR A", 1, 4, IMMEDIATE, "Xor A with A"},

	{0xB0, "OR B", 1, 4, IMMEDIATE, "Or B with A"},
	{0xB1, "OR C", 1, 4, IMMEDIATE, "Or C with A"},
	{0xB2, "OR D", 1, 4, IMMEDIATE, "Or D with A"},
	{0xB3, "OR E", 1, 4, IMMEDIATE, "Or E with A"},
	{0xB4, "OR H", 1, 4, IMMEDIATE, "Or H with A"},
	{0xB5, "OR L", 1, 4, IMMEDIATE, "Or L with A"},
	{0xB6, "OR (HL)", 1, 8, INDIRECT, "Or (HL) with A"},
	{0xB7, "OR A", 1, 4, IMMEDIATE, "Or A with A"},
	{0xB8, "CP B", 1, 4, IMMEDIATE, "Compare B with A"}, // Compare with A
	{0xB9, "CP C", 1, 4, IMMEDIATE, "Compare C with A"},
	{0xBA, "CP D", 1, 4, IMMEDIATE, "Compare D with A"},
	{0xBB, "CP E", 1, 4, IMMEDIATE, "Compare E with A"},
	{0xBC, "CP H", 1, 4, IMMEDIATE, "Compare H with A"},
	{0xBD, "CP L", 1, 4, IMMEDIATE, "Compare L with A"},
	{0xBE, "CP (HL)", 1, 8, INDIRECT, "Compare (HL) with A"},
	{0xBF, "CP A", 1, 4, IMMEDIATE, "Compare A with A"},

	{0xC0, "RET NZ", 1, 8, NONE, "Return if non-Zero"},
	{0xC1, "POP BC", 1, 12, NONE, "Pop BC from stack"},
	{0xC2, "JP NZ, $%04X", 3, 12, ABSOLUTE, "Jump to $%04X if non-Zero"},
	{0xC3, "JP $%04X", 3, 12, ABSOLUTE, "Jump to $%04X"},
	{0xC4, "CALL NZ, $%04X", 3, 12, NONE, "Call subroutine $%04X if non-Zero"},
	{0xC5, "PUSH BC", 1, 16, NONE, "Push BC to stack"},
	{0xC6, "ADD A, #%02X", 2, 8, IMMEDIATE, "Add #%02X to A"},
	{0xC7, "RST $00", 1, 32, NONE, "Restart at $0000"},
	{0xC8, "RET Z", 1, 8, NONE, "Return if Zero"},
	{0xC9, "RET", 1, 8, NONE, "Return"},
	{0xCA, "JP Z, $%04X", 3, 12, ABSOLUTE, "Jump absolute if Zero"},
	{0xCB, "PAGE1+ ", 0, 0, EXTENDED, "Extended Instruction"},
	{0xCC, "CALL Z, $%04X", 3, 12, NONE, "Call subroutine $%04X if Zero"},
	{0xCD, "CALL $%04X", 3, 12, NONE, "Call subroutine at $%04X"},
	{0xCE, "ADC A, #%02X", 2, 8, IMMEDIATE, "Add #%02X to A with Carry"},
	{0xCF, "RST $08", 1, 32, NONE, "Restart at $0008"},

	{0xD0, "RET NC", 1, 8, NONE, "Return if no-Carry"},
	{0xD1, "POP DE", 1, 12, NONE, "Pop DE from stack"},
	{0xD2, "JP NC, $%04X", 3, 12, NONE, "Jump to $%04X if no-Carry"},
	{0xD3, "ILL", 0, 0, ILLEGAL, "Illegal Instruction 0xD3"},
	{0xD4, "CALL NC, $%04X", 3, 12, ABSOLUTE, "Call subroutine $%04X if no-Carry"},
	{0xD5, "PUSH DE", 1, 16, NONE, "Push DE to stack"},
	{0xD6, "SUB #%02X", 2, 8, IMMEDIATE, "Subtract #%02X from A"},
	{0xD7, "RST $10", 1, 32, NONE, "Restart at $0010"},
	{0xD8, "RET C", 1, 8, NONE, "Return if Carry"},
	{0xD9, "RETI", 1, 8, NONE, "Return from Interrupt"},
	{0xDA, "JP C, $%04X", 3, 12, ABSOLUTE, "Jump to $%04X if Carry"},
	{0xDB, "ILL", 0, 0, ILLEGAL, "Illegal Instruction 0xDB"},
	{0xDC, "CALL C, $%04X", 3, 12, NONE, "Call subroutine $%04X if Carry"},
	{0xDD, "ILL", 0, 0, ILLEGAL, "Illegal Instruction 0xDD"},
	{0xDE, "SBC A, #%02X", 2, 8, IMMEDIATE, "Subtract #%02X from A with Carry"},
	{0xDF, "RST $18", 1, 32, NONE, "Restart at $0018"},

	{0xE0, "LDH $%02X, A", 2, 12, INDIRECT, "Load A to ($FF00 + $%02X)"},
	{0xE1, "POP HL", 1, 12, NONE, "Pop HL from stack"},
	{0xE2, "LD (C), A", 1, 8, INDIRECT, "Load A to ($FF00 + C)"},
	{0xE3, "ILL", 0, 0, ILLEGAL, "Illegal Instruction 0xE3"},
	{0xE4, "ILL", 0, 0, ILLEGAL, "Illegal Instruction 0xE4"},
	{0xE5, "PUSH HL", 1, 16, NONE, "Push HL to stack"},
	{0xE6, "AND #%02X", 2, 8, IMMEDIATE, "And #%02X with A"},
	{0xE7, "RST $20", 1, 32, NONE, "Restart at $0020"},
	{0xE8, "ADD SP, #%02X", 2, 16, IMMEDIATE, "Add #%02X to SP"},
	{0xE9, "JP (HL)", 1, 4, ABSOLUTE, "Jump to (HL)"},
	{0xEA, "LD $%04X, A", 3, 16, IMMEDIATE, "Load A to ($%04X)"},
	{0xEB, "ILL", 0, 0, ILLEGAL, "Illegal Instruction 0xEB"},
	{0xEC, "ILL", 0, 0, ILLEGAL, "Illegal Instruction 0xEC"},
	{0xED, "ILL", 0, 0, ILLEGAL, "Illegal Instruction 0xED"},
	{0xEE, "XOR #%02X", 2, 8, IMMEDIATE, "Xor #%02X with A"},
	{0xEF, "RST $28", 1, 32, NONE, "Restart at $0028"},

	{0xF0, "LDH A, $%02X", 2, 12, IMMEDIATE, "Load ($FF00 + $%02X) to A"},
	{0xF1, "POP AF", 1, 12, NONE, "Pop AF from stack"},
	{0xF2, "LD A, (C)", 1, 8, INDIRECT, "Load ($FF00 + C) to A"},
	{0xF3, "DI", 1, 4, NONE, "Disable Interrupt"},
	{0xF4, "ILL", 0, 0, ILLEGAL, "Illegal Instruction 0xF4"},
	{0xF5, "PUSH AF", 1, 16, NONE, "Push AF to stack"},
	{0xF6, "OR #%02X", 2, 8, IMMEDIATE, "Or #%02X with A"},
	{0xF7, "RST $30", 1, 32, NONE, "Restart at $0030"},
	{0xF8, "LD HL, SP + #%02X", 2, 12, IMMEDIATE, "Load SP + #%02X to HL"},
	{0xF9, "LD SP, HL", 1, 8, NONE, "Load HL to SP"},
	{0xFA, "LD A, $%04X", 3, 16, INDIRECT, "Load ($%04X) to A"},
	{0xFB, "EI", 1, 4, NONE, "Enable Interrupt"},
	{0xFC, "ILL", 0, 0, ILLEGAL, "Illegal Instruction 0xFC"},
	{0xFD, "ILL", 0, 0, ILLEGAL, "Illegal Instruction 0xFD"},
	{0xFE, "CP #%02X", 2, 8, IMMEDIATE, "Compare #%02X with A"},
	{0xFF, "RST $38", 1, 32, NONE, "Restart at $0038"}
};


// Extended instruction with 0xCB prefix
const Opcode page1[0x100] = {
	{0x00, "RLC B", 2, 8, IMMEDIATE, "Rotate B Left with Carry"},
	{0x01, "RLC C", 2, 8, IMMEDIATE, "Rotate C Left with Carry"},
	{0x02, "RLC D", 2, 8, IMMEDIATE, "Rotate D Left with Carry"},
	{0x03, "RLC E", 2, 8, IMMEDIATE, "Rotate E Left with Carry"},
	{0x04, "RLC H", 2, 8, IMMEDIATE, "Rotate H Left with Carry"},
	{0x05, "RLC L", 2, 8, IMMEDIATE, "Rotate L Left with Carry"},
	{0x06, "RLC (HL)", 2, 16, INDIRECT, "Rotate (HL) Left with Carry"},
	{0x07, "RLC A", 2, 8, IMMEDIATE, "Rotate A Left with Carry"},
	{0x08, "RRC B", 2, 8, IMMEDIATE, "Rotate B Right with Carry"},
	{0x09, "RRC C", 2, 8, IMMEDIATE, "Rotate C Right with Carry"},
	{0x0A, "RRC D", 2, 8, IMMEDIATE, "Rotate D Right with Carry"},
	{0x0B, "RRC E", 2, 8, IMMEDIATE, "Rotate E Right with Carry"},
	{0x0C, "RRC H", 2, 8, IMMEDIATE, "Rotate H Right with Carry"},
	{0x0D, "RRC L", 2, 8, IMMEDIATE, "Rotate L Right with Carry"},
	{0x0E, "RRC (HL)", 2, 16, INDIRECT, "Rotate (HL) Right with Carry"},
	{0x0F, "RRC A", 2, 8, IMMEDIATE, "Rotate A Right with Carry"},

	{0x10, "RL B", 2, 8, IMMEDIATE, "Rotate B Left"},
	{0x11, "RL C", 2, 8, IMMEDIATE, "Rotate C Left"},
	{0x12, "RL D", 2, 8, IMMEDIATE, "Rotate D Left"},
	{0x13, "RL E", 2, 8, IMMEDIATE, "Rotate E Left"},
	{0x14, "RL H", 2, 8, IMMEDIATE, "Rotate H Left"},
	{0x15, "RL L", 2, 8, IMMEDIATE, "Rotate L Left"},
	{0x16, "RL (HL)", 2, 16, INDIRECT, "Rotate (HL) Left"},
	{0x17, "RL A", 2, 8, IMMEDIATE, "Rotate A Left"},
	{0x18, "RR B", 2, 8, IMMEDIATE, "Rotate B Right"},
	{0x19, "RR C", 2, 8, IMMEDIATE, "Rotate C Right"},
	{0x1A, "RR D", 2, 8, IMMEDIATE, "Rotate D Right"},
	{0x1B, "RR E", 2, 8, IMMEDIATE, "Rotate E Right"},
	{0x1C, "RR H", 2, 8, IMMEDIATE, "Rotate H Right"},
	{0x1D, "RR L", 2, 8, IMMEDIATE, "Rotate L Right"},
	{0x1E, "RR (HL)", 2, 16, INDIRECT, "Rotate (HL) Right"},
	{0x1F, "RR A", 2, 8, IMMEDIATE, "Rotate A Right"},

	{0x20, "SLA B", 2, 8, IMMEDIATE, "Shift B Left"},
	{0x21, "SLA C", 2, 8, IMMEDIATE, "Shift C Left"},
	{0x22, "SLA D", 2, 8, IMMEDIATE, "Shift D Left"},
	{0x23, "SLA E", 2, 8, IMMEDIATE, "Shift E Left"},
	{0x24, "SLA H", 2, 8, IMMEDIATE, "Shift H Left"},
	{0x25, "SLA L", 2, 8, IMMEDIATE, "Shift L Left"},
	{0x26, "SLA (HL)", 2, 16, INDIRECT, "Shift (HL) Left"},
	{0x27, "SLA A", 2, 8, IMMEDIATE, "Shift A Left"},
	{0x28, "SRA B", 2, 8, IMMEDIATE, "Shift B Right"},
	{0x29, "SRA C", 2, 8, IMMEDIATE, "Shift C Right"},
	{0x2A, "SRA D", 2, 8, IMMEDIATE, "Shift D Right"},
	{0x2B, "SRA E", 2, 8, IMMEDIATE, "Shift E Right"},
	{0x2C, "SRA H", 2, 8, IMMEDIATE, "Shift H Right"},
	{0x2D, "SRA L", 2, 8, IMMEDIATE, "Shift L Right"},
	{0x2E, "SRA (HL)", 2, 16, INDIRECT, "Shift (HL) Right"},
	{0x2F, "SRA A", 2, 8, IMMEDIATE, "Shift A Right"},

	{0x30, "SWAP B", 2, 8, IMMEDIATE, "Swap B"},
	{0x31, "SWAP C", 2, 8, IMMEDIATE, "Swap C"},
	{0x32, "SWAP D", 2, 8, IMMEDIATE, "Swap D"},
	{0x33, "SWAP E", 2, 8, IMMEDIATE, "Swap E"},
	{0x34, "SWAP H", 2, 8, IMMEDIATE, "Swap H"},
	{0x35, "SWAP L", 2, 8, IMMEDIATE, "Swap L"},
	{0x36, "SWAP (HL)", 2, 16, INDIRECT, "Swap (HL)"},
	{0x37, "SWAP A", 2, 8, IMMEDIATE, "Swap A"},
	{0x38, "SRL B", 2, 8, IMMEDIATE, "Logical Shift B Right"},
	{0x39, "SRL C", 2, 8, IMMEDIATE, "Logical Shift C Right"},
	{0x3A, "SRL D", 2, 8, IMMEDIATE, "Logical Shift D Right"},
	{0x3B, "SRL E", 2, 8, IMMEDIATE, "Logical Shift E Right"},
	{0x3C, "SRL H", 2, 8, IMMEDIATE, "Logical Shift H Right"},
	{0x3D, "SRL L", 2, 8, IMMEDIATE, "Logical Shift L Right"},
	{0x3E, "SRL (HL)", 2, 16, INDIRECT, "Logical Shift (HL) Right"},
	{0x3F, "SRL A", 2, 8, IMMEDIATE, "Logical Shift A Right"},

	{0x40, "BIT 0, B", 2, 8, IMMEDIATE, "Test bit 0 of register B"},
	{0x41, "BIT 0, C", 2, 8, IMMEDIATE, "Test bit 0 of register C"},
	{0x42, "BIT 0, D", 2, 8, IMMEDIATE, "Test bit 0 of register D"},
	{0x43, "BIT 0, E", 2, 8, IMMEDIATE, "Test bit 0 of register E"},
	{0x44, "BIT 0, H", 2, 8, IMMEDIATE, "Test bit 0 of register H"},
	{0x45, "BIT 0, L", 2, 8, IMMEDIATE, "Test bit 0 of register L"},
	{0x46, "BIT 0, (HL)", 2, 16, INDIRECT, "Test bit 0 of register (HL)"},
	{0x47, "BIT 0, A", 2, 8, IMMEDIATE, "Test bit 0 of register A"},
	{0x48, "BIT 1, B", 2, 8, IMMEDIATE, "Test bit 1 of register B"},
	{0x49, "BIT 1, C", 2, 8, IMMEDIATE, "Test bit 1 of register C"},
	{0x4A, "BIT 1, D", 2, 8, IMMEDIATE, "Test bit 1 of register D"},
	{0x4B, "BIT 1, E", 2, 8, IMMEDIATE, "Test bit 1 of register E"},
	{0x4C, "BIT 1, H", 2, 8, IMMEDIATE, "Test bit 1 of register H"},
	{0x4D, "BIT 1, L", 2, 8, IMMEDIATE, "Test bit 1 of register L"},
	{0x4E, "BIT 1, (HL)", 2, 16, INDIRECT, "Test bit 1 of register (HL)"},
	{0x4F, "BIT 1, A", 2, 8, IMMEDIATE, "Test bit 1 of register A"},

	{0x50, "BIT 2, B", 2, 8, IMMEDIATE, "Test bit 2 of register B"},
	{0x51, "BIT 2, C", 2, 8, IMMEDIATE, "Test bit 2 of register C"},
	{0x52, "BIT 2, D", 2, 8, IMMEDIATE, "Test bit 2 of register D"},
	{0x53, "BIT 2, E", 2, 8, IMMEDIATE, "Test bit 2 of register E"},
	{0x54, "BIT 2, H", 2, 8, IMMEDIATE, "Test bit 2 of register H"},
	{0x55, "BIT 2, L", 2, 8, IMMEDIATE, "Test bit 2 of register L"},
	{0x56, "BIT 2, (HL)", 2, 16, INDIRECT, "Test bit 2 of register (HL)"},
	{0x57, "BIT 2, A", 2, 8, IMMEDIATE, "Test bit 2 of register A"},
	{0x58, "BIT 3, B", 2, 8, IMMEDIATE, "Test bit 3 of register B"},
	{0x59, "BIT 3, C", 2, 8, IMMEDIATE, "Test bit 3 of register C"},
	{0x5A, "BIT 3, D", 2, 8, IMMEDIATE, "Test bit 3 of register D"},
	{0x5B, "BIT 3, E", 2, 8, IMMEDIATE, "Test bit 3 of register E"},
	{0x5C, "BIT 3, H", 2, 8, IMMEDIATE, "Test bit 3 of register H"},
	{0x5D, "BIT 3, L", 2, 8, IMMEDIATE, "Test bit 3 of register L"},
	{0x5E, "BIT 3, (HL)", 2, 16, INDIRECT, "Test bit 3 of register (HL)"},
	{0x5F, "BIT 3, A", 2, 8, IMMEDIATE, "Test bit 3 of register A"},

	{0x60, "BIT 4, B", 2, 8, IMMEDIATE, "Test bit 4 of register B"},
	{0x61, "BIT 4, C", 2, 8, IMMEDIATE, "Test bit 4 of register C"},
	{0x62, "BIT 4, D", 2, 8, IMMEDIATE, "Test bit 4 of register D"},
	{0x63, "BIT 4, E", 2, 8, IMMEDIATE, "Test bit 4 of register E"},
	{0x64, "BIT 4, H", 2, 8, IMMEDIATE, "Test bit 4 of register H"},
	{0x65, "BIT 4, L", 2, 8, IMMEDIATE, "Test bit 4 of register L"},
	{0x66, "BIT 4, (HL)", 2, 16, INDIRECT, "Test bit 4 of register (HL)"},
	{0x67, "BIT 4, A", 2, 8, IMMEDIATE, "Test bit 4 of register A"},
	{0x68, "BIT 5, B", 2, 8, IMMEDIATE, "Test bit 5 of register B"},
	{0x69, "BIT 5, C", 2, 8, IMMEDIATE, "Test bit 5 of register C"},
	{0x6A, "BIT 5, D", 2, 8, IMMEDIATE, "Test bit 5 of register D"},
	{0x6B, "BIT 5, E", 2, 8, IMMEDIATE, "Test bit 5 of register E"},
	{0x6C, "BIT 5, H", 2, 8, IMMEDIATE, "Test bit 5 of register H"},
	{0x6D, "BIT 5, L", 2, 8, IMMEDIATE, "Test bit 5 of register L"},
	{0x6E, "BIT 5, (HL)", 2, 16, INDIRECT, "Test bit 5 of register (HL)"},
	{0x6F, "BIT 5, A", 2, 8, IMMEDIATE, "Test bit 5 of register A"},

	{0x70, "BIT 6, B", 2, 8, IMMEDIATE, "Test bit 6 of register B"},
	{0x71, "BIT 6, C", 2, 8, IMMEDIATE, "Test bit 6 of register C"},
	{0x72, "BIT 6, D", 2, 8, IMMEDIATE, "Test bit 6 of register D"},
	{0x73, "BIT 6, E", 2, 8, IMMEDIATE, "Test bit 6 of register E"},
	{0x74, "BIT 6, H", 2, 8, IMMEDIATE, "Test bit 6 of register H"},
	{0x75, "BIT 6, L", 2, 8, IMMEDIATE, "Test bit 6 of register L"},
	{0x76, "BIT 6, (HL)", 2, 16, INDIRECT, "Test bit 6 of register (HL)"},
	{0x77, "BIT 6, A", 2, 8, IMMEDIATE, "Test bit 6 of register A"},
	{0x78, "BIT 7, B", 2, 8, IMMEDIATE, "Test bit 7 of register B"},
	{0x79, "BIT 7, C", 2, 8, IMMEDIATE, "Test bit 7 of register C"},
	{0x7A, "BIT 7, D", 2, 8, IMMEDIATE, "Test bit 7 of register D"},
	{0x7B, "BIT 7, E", 2, 8, IMMEDIATE, "Test bit 7 of register E"},
	{0x7C, "BIT 7, H", 2, 8, IMMEDIATE, "Test bit 7 of register H"},
	{0x7D, "BIT 7, L", 2, 8, IMMEDIATE, "Test bit 7 of register L"},
	{0x7E, "BIT 7, (HL)", 2, 16, INDIRECT, "Test bit 7 of register (HL)"},
	{0x7F, "BIT 7, A", 2, 8, IMMEDIATE, "Test bit 7 of register A"},

	{0x80, "RES 0, B", 2, 8, IMMEDIATE, "Reset bit 0 of register B"},
	{0x81, "RES 0, C", 2, 8, IMMEDIATE, "Reset bit 0 of register C"},
	{0x82, "RES 0, D", 2, 8, IMMEDIATE, "Reset bit 0 of register D"},
	{0x83, "RES 0, E", 2, 8, IMMEDIATE, "Reset bit 0 of register E"},
	{0x84, "RES 0, H", 2, 8, IMMEDIATE, "Reset bit 0 of register H"},
	{0x85, "RES 0, L", 2, 8, IMMEDIATE, "Reset bit 0 of register L"},
	{0x86, "RES 0, (HL)", 2, 16, INDIRECT, "Reset bit 0 of register (HL)"},
	{0x87, "RES 0, A", 2, 8, IMMEDIATE, "Reset bit 0 of register A"},
	{0x88, "RES 1, B", 2, 8, IMMEDIATE, "Reset bit 1 of register B"},
	{0x89, "RES 1, C", 2, 8, IMMEDIATE, "Reset bit 1 of register C"},
	{0x8A, "RES 1, D", 2, 8, IMMEDIATE, "Reset bit 1 of register D"},
	{0x8B, "RES 1, E", 2, 8, IMMEDIATE, "Reset bit 1 of register E"},
	{0x8C, "RES 1, H", 2, 8, IMMEDIATE, "Reset bit 1 of register H"},
	{0x8D, "RES 1, L", 2, 8, IMMEDIATE, "Reset bit 1 of register L"},
	{0x8E, "RES 1, (HL)", 2, 16, INDIRECT, "Reset bit 1 of register (HL)"},
	{0x8F, "RES 1, A", 2, 8, IMMEDIATE, "Reset bit 1 of register A"},

	{0x90, "RES 2, B", 2, 8, IMMEDIATE, "Reset bit 2 of register B"},
	{0x91, "RES 2, C", 2, 8, IMMEDIATE, "Reset bit 2 of register C"},
	{0x92, "RES 2, D", 2, 8, IMMEDIATE, "Reset bit 2 of register D"},
	{0x93, "RES 2, E", 2, 8, IMMEDIATE, "Reset bit 2 of register E"},
	{0x94, "RES 2, H", 2, 8, IMMEDIATE, "Reset bit 2 of register H"},
	{0x95, "RES 2, L", 2, 8, IMMEDIATE, "Reset bit 2 of register L"},
	{0x96, "RES 2, (HL)", 2, 16, INDIRECT, "Reset bit 2 of register (HL)"},
	{0x97, "RES 2, A", 2, 8, IMMEDIATE, "Reset bit 2 of register A"},
	{0x98, "RES 3, B", 2, 8, IMMEDIATE, "Reset bit 3 of register B"},
	{0x99, "RES 3, C", 2, 8, IMMEDIATE, "Reset bit 3 of register C"},
	{0x9A, "RES 3, D", 2, 8, IMMEDIATE, "Reset bit 3 of register D"},
	{0x9B, "RES 3, E", 2, 8, IMMEDIATE, "Reset bit 3 of register E"},
	{0x9C, "RES 3, H", 2, 8, IMMEDIATE, "Reset bit 3 of register H"},
	{0x9D, "RES 3, L", 2, 8, IMMEDIATE, "Reset bit 3 of register L"},
	{0x9E, "RES 3, (HL)", 2, 16, INDIRECT, "Reset bit 3 of register (HL)"},
	{0x9F, "RES 3, A", 2, 8, IMMEDIATE, "Reset bit 3 of register A"},

	{0xA0, "RES 4, B", 2, 8, IMMEDIATE, "Reset bit 4 of register B"},
	{0xA1, "RES 4, C", 2, 8, IMMEDIATE, "Reset bit 4 of register C"},
	{0xA2, "RES 4, D", 2, 8, IMMEDIATE, "Reset bit 4 of register D"},
	{0xA3, "RES 4, E", 2, 8, IMMEDIATE, "Reset bit 4 of register E"},
	{0xA4, "RES 4, H", 2, 8, IMMEDIATE, "Reset bit 4 of register H"},
	{0xA5, "RES 4, L", 2, 8, IMMEDIATE, "Reset bit 4 of register L"},
	{0xA6, "RES 4, (HL)", 2, 16, INDIRECT, "Reset bit 4 of register (HL)"},
	{0xA7, "RES 4, A", 2, 8, IMMEDIATE, "Reset bit 4 of register A"},
	{0xA8, "RES 5, B", 2, 8, IMMEDIATE, "Reset bit 5 of register B"},
	{0xA9, "RES 5, C", 2, 8, IMMEDIATE, "Reset bit 5 of register C"},
	{0xAA, "RES 5, D", 2, 8, IMMEDIATE, "Reset bit 5 of register D"},
	{0xAB, "RES 5, E", 2, 8, IMMEDIATE, "Reset bit 5 of register E"},
	{0xAC, "RES 5, H", 2, 8, IMMEDIATE, "Reset bit 5 of register H"},
	{0xAD, "RES 5, L", 2, 8, IMMEDIATE, "Reset bit 5 of register L"},
	{0xAE, "RES 5, (HL)", 2, 16, INDIRECT, "Reset bit 5 of register (HL)"},
	{0xAF, "RES 5, A", 2, 8, IMMEDIATE, "Reset bit 5 of register A"},

	{0xB0, "RES 6, B", 2, 8, IMMEDIATE, "Reset bit 6 of register B"},
	{0xB1, "RES 6, C", 2, 8, IMMEDIATE, "Reset bit 6 of register C"},
	{0xB2, "RES 6, D", 2, 8, IMMEDIATE, "Reset bit 6 of register D"},
	{0xB3, "RES 6, E", 2, 8, IMMEDIATE, "Reset bit 6 of register E"},
	{0xB4, "RES 6, H", 2, 8, IMMEDIATE, "Reset bit 6 of register H"},
	{0xB5, "RES 6, L", 2, 8, IMMEDIATE, "Reset bit 6 of register L"},
	{0xB6, "RES 6, (HL)", 2, 16, INDIRECT, "Reset bit 6 of register (HL)"},
	{0xB7, "RES 6, A", 2, 8, IMMEDIATE, "Reset bit 6 of register A"},
	{0xB8, "RES 7, B", 2, 8, IMMEDIATE, "Reset bit 7 of register B"},
	{0xB9, "RES 7, C", 2, 8, IMMEDIATE, "Reset bit 7 of register C"},
	{0xBA, "RES 7, D", 2, 8, IMMEDIATE, "Reset bit 7 of register D"},
	{0xBB, "RES 7, E", 2, 8, IMMEDIATE, "Reset bit 7 of register E"},
	{0xBC, "RES 7, H", 2, 8, IMMEDIATE, "Reset bit 7 of register H"},
	{0xBD, "RES 7, L", 2, 8, IMMEDIATE, "Reset bit 7 of register L"},
	{0xBE, "RES 7, (HL)", 2, 16, INDIRECT, "Reset bit 7 of register (HL)"},
	{0xBF, "RES 7, A", 2, 8, IMMEDIATE, "Reset bit 7 of register A"},

	{0xC0, "SET 0, B", 2, 8, IMMEDIATE, "Set bit 0 of register B"},
	{0xC1, "SET 0, C", 2, 8, IMMEDIATE, "Set bit 0 of register C"},
	{0xC2, "SET 0, D", 2, 8, IMMEDIATE, "Set bit 0 of register D"},
	{0xC3, "SET 0, E", 2, 8, IMMEDIATE, "Set bit 0 of register E"},
	{0xC4, "SET 0, H", 2, 8, IMMEDIATE, "Set bit 0 of register H"},
	{0xC5, "SET 0, L", 2, 8, IMMEDIATE, "Set bit 0 of register L"},
	{0xC6, "SET 0, (HL)", 2, 16, INDIRECT, "Set bit 0 of register (HL)"},
	{0xC7, "SET 0, A", 2, 8, IMMEDIATE, "Set bit 0 of register A"},
	{0xC8, "SET 1, B", 2, 8, IMMEDIATE, "Set bit 1 of register B"},
	{0xC9, "SET 1, C", 2, 8, IMMEDIATE, "Set bit 1 of register C"},
	{0xCA, "SET 1, D", 2, 8, IMMEDIATE, "Set bit 1 of register D"},
	{0xCB, "SET 1, E", 2, 8, IMMEDIATE, "Set bit 1 of register E"},
	{0xCC, "SET 1, H", 2, 8, IMMEDIATE, "Set bit 1 of register H"},
	{0xCD, "SET 1, L", 2, 8, IMMEDIATE, "Set bit 1 of register L"},
	{0xCE, "SET 1, (HL)", 2, 16, INDIRECT, "Set bit 1 of register (HL)"},
	{0xCF, "SET 1, A", 2, 8, IMMEDIATE, "Set bit 1 of register A"},

	{0xD0, "SET 2, B", 2, 8, IMMEDIATE, "Set bit 2 of register B"},
	{0xD1, "SET 2, C", 2, 8, IMMEDIATE, "Set bit 2 of register C"},
	{0xD2, "SET 2, D", 2, 8, IMMEDIATE, "Set bit 2 of register D"},
	{0xD3, "SET 2, E", 2, 8, IMMEDIATE, "Set bit 2 of register E"},
	{0xD4, "SET 2, H", 2, 8, IMMEDIATE, "Set bit 2 of register H"},
	{0xD5, "SET 2, L", 2, 8, IMMEDIATE, "Set bit 2 of register L"},
	{0xD6, "SET 2, (HL)", 2, 16, INDIRECT, "Set bit 2 of register (HL)"},
	{0xD7, "SET 2, A", 2, 8, IMMEDIATE, "Set bit 2 of register A"},
	{0xD8, "SET 3, B", 2, 8, IMMEDIATE, "Set bit 3 of register B"},
	{0xD9, "SET 3, C", 2, 8, IMMEDIATE, "Set bit 3 of register C"},
	{0xDA, "SET 3, D", 2, 8, IMMEDIATE, "Set bit 3 of register D"},
	{0xDB, "SET 3, E", 2, 8, IMMEDIATE, "Set bit 3 of register E"},
	{0xDC, "SET 3, H", 2, 8, IMMEDIATE, "Set bit 3 of register H"},
	{0xDD, "SET 3, L", 2, 8, IMMEDIATE, "Set bit 3 of register L"},
	{0xDE, "SET 3, (HL)", 2, 16, INDIRECT, "Set bit 3 of register (HL)"},
	{0xDF, "SET 3, A", 2, 8, IMMEDIATE, "Set bit 3 of register A"},

	{0xE0, "SET 4, B", 2, 8, IMMEDIATE, "Set bit 4 of register B"},
	{0xE1, "SET 4, C", 2, 8, IMMEDIATE, "Set bit 4 of register C"},
	{0xE2, "SET 4, D", 2, 8, IMMEDIATE, "Set bit 4 of register D"},
	{0xE3, "SET 4, E", 2, 8, IMMEDIATE, "Set bit 4 of register E"},
	{0xE4, "SET 4, H", 2, 8, IMMEDIATE, "Set bit 4 of register H"},
	{0xE5, "SET 4, L", 2, 8, IMMEDIATE, "Set bit 4 of register L"},
	{0xE6, "SET 4, (HL)", 2, 16, INDIRECT, "Set bit 4 of register (HL)"},
	{0xE7, "SET 4, A", 2, 8, IMMEDIATE, "Set bit 4 of register A"},
	{0xE8, "SET 5, B", 2, 8, IMMEDIATE, "Set bit 5 of register B"},
	{0xE9, "SET 5, C", 2, 8, IMMEDIATE, "Set bit 5 of register C"},
	{0xEA, "SET 5, D", 2, 8, IMMEDIATE, "Set bit 5 of register D"},
	{0xEB, "SET 5, E", 2, 8, IMMEDIATE, "Set bit 5 of register E"},
	{0xEC, "SET 5, H", 2, 8, IMMEDIATE, "Set bit 5 of register H"},
	{0xED, "SET 5, L", 2, 8, IMMEDIATE, "Set bit 5 of register L"},
	{0xEE, "SET 5, (HL)", 2, 16, INDIRECT, "Set bit 5 of register (HL)"},
	{0xEF, "SET 5, A", 2, 8, IMMEDIATE, "Set bit 5 of register A"},

	{0xF0, "SET 6, B", 2, 8, IMMEDIATE, "Set bit 6 of register B"},
	{0xF1, "SET 6, C", 2, 8, IMMEDIATE, "Set bit 6 of register C"},
	{0xF2, "SET 6, D", 2, 8, IMMEDIATE, "Set bit 6 of register D"},
	{0xF3, "SET 6, E", 2, 8, IMMEDIATE, "Set bit 6 of register E"},
	{0xF4, "SET 6, H", 2, 8, IMMEDIATE, "Set bit 6 of register H"},
	{0xF5, "SET 6, L", 2, 8, IMMEDIATE, "Set bit 6 of register L"},
	{0xF6, "SET 6, (HL)", 2, 16, INDIRECT, "Set bit 6 of register (HL)"},
	{0xF7, "SET 6, A", 2, 8, IMMEDIATE, "Set bit 6 of register A"},
	{0xF8, "SET 7, B", 2, 8, IMMEDIATE, "Set bit 7 of register B"},
	{0xF9, "SET 7, C", 2, 8, IMMEDIATE, "Set bit 7 of register C"},
	{0xFA, "SET 7, D", 2, 8, IMMEDIATE, "Set bit 7 of register D"},
	{0xFB, "SET 7, E", 2, 8, IMMEDIATE, "Set bit 7 of register E"},
	{0xFC, "SET 7, H", 2, 8, IMMEDIATE, "Set bit 7 of register H"},
	{0xFD, "SET 7, L", 2, 8, IMMEDIATE, "Set bit 7 of register L"},
	{0xFE, "SET 7, (HL)", 2, 16, INDIRECT, "Set bit 7 of register (HL)"},
	{0xFF, "SET 7, A", 2, 8, IMMEDIATE, "Set bit 7 of register A"}
};

#endif
