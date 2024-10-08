#pragma once

#include "SharedPtrTypes.hpp"
#include <string>
#include <vector>

namespace Assembler {

    struct AsmOperand{
        enum OperandType{
            IMM,
            REG,
            ADDRESSING,
            LABEL
        };

        OperandType type;
        std::wstring value;

    };

    struct AsmInstruction{
        // TODO: Add more instructions
        enum InstructionType{
            LOCAL_LABEL,
            INLINE_ASM,
            NOP,
            PUSH,
            POP,
            MOV,
            LEA,
            ADD,
            SUB,
            BSR,
            BSF,
            XOR,
            OR,
            AND,
            SHR,
            SHL,
            CALL,
            RET,
            SYSCALL,
            CMP,
            TEST,
            JMP,
            JZ,
            JNZ,
            JS,
            JNS,
            JG,
            JGE,
            JL,
            JLE,
            JA,
            JAE,
            JB,
            JBE,
            INC,
            DEC,
            NEG,
            NOT,
            MUL,
            IMUL,
            DIV,
            IDIV,
            SETZ,
            SETNZ,
            SETS,
            SETNS,
            SETG,
            SETGE,
            SETL,
            SETLE,
            SETA,
            SETAE,
            SETB,
            SETBE,
            CBW,
            CWDE,
            CDQE,
            CWD,
            CDQ,
            CMOVZ,
            CMOVNZ,
            CMOVS,
            CMOVG,
            // SIMD
            MOVQ,
            MOVD,
            MOVSD,
            MOVSS,
            CVTSI2SD,
            CVTSD2SI,
            CVTSS2SD,
            CVTSD2SS,
            CVTSI2SS,
            CVTSS2SI,
            ADDSD,
            SUBSD,
            MULSD,
            DIVSD,
            ADDSS,
            SUBSS,
            MULSS,
            DIVSS,
            ROUNDSD,
            ROUNDSS,
        };

        enum InstructionSize{
            IMPLICIT=0, // means the size is determined in registers
            BYTE=1,
            WORD=2,
            DWORD=4,
            QWORD=8,
        };

        InstructionType type;
        InstructionSize size=IMPLICIT;
        std::vector<AsmOperand> operands;
        std::wstring comment=L"";
        std::wstring getAsmText(bool showComment=true);

    };

    struct AsmLabel{
        std::wstring label;
        std::vector<AsmInstruction> instructions;
        std::wstring comment=L"";
        void operator+=(AsmInstruction instruction);
        void operator+=(std::vector<AsmInstruction> instructions);
        std::wstring getAsmText();
    };

    AsmInstruction localLabel(std::wstring label, std::wstring comment=L"");
    AsmInstruction inline_asm(std::wstring _asm, std::wstring comment=L"");
    AsmInstruction nop(std::wstring comment=L"");
    AsmInstruction push(AsmOperand op, std::wstring comment=L"");
    AsmInstruction pop(AsmOperand op, std::wstring comment=L"");
    AsmInstruction mov(AsmOperand d, AsmOperand s, AsmInstruction::InstructionSize size=AsmInstruction::IMPLICIT, std::wstring comment=L"");
    AsmInstruction lea(AsmOperand d, AsmOperand s, AsmInstruction::InstructionSize size=AsmInstruction::IMPLICIT, std::wstring comment=L"");
    AsmInstruction add(AsmOperand d, AsmOperand s, AsmInstruction::InstructionSize size=AsmInstruction::IMPLICIT, std::wstring comment=L"");
    AsmInstruction sub(AsmOperand d, AsmOperand s, std::wstring comment=L"");
    AsmInstruction bsr(AsmOperand d, AsmOperand s, std::wstring comment=L"");
    AsmInstruction bsf(AsmOperand d, AsmOperand s, std::wstring comment=L"");
    AsmInstruction _xor(AsmOperand d, AsmOperand s, std::wstring comment=L"");
    AsmInstruction _or(AsmOperand d, AsmOperand s, std::wstring comment=L"");
    AsmInstruction _and(AsmOperand d, AsmOperand s, std::wstring comment=L"");
    AsmInstruction shr(AsmOperand d, AsmOperand k, std::wstring comment=L"");
    AsmInstruction shl(AsmOperand d, AsmOperand k, std::wstring comment=L"");
    AsmInstruction zero(AsmOperand d, std::wstring comment=L"");
    AsmInstruction call(AsmOperand label, std::wstring comment=L"");
    AsmInstruction ret(std::wstring comment=L"");
    AsmInstruction syscall(std::wstring comment=L"");
    AsmInstruction cmp(AsmOperand s1, AsmOperand s2, std::wstring comment=L"");
    AsmInstruction test(AsmOperand s1, AsmOperand s2, std::wstring comment=L"");
    AsmInstruction jmp(AsmOperand label, std::wstring comment=L"");
    AsmInstruction jz(AsmOperand label, std::wstring comment=L"");
    AsmInstruction jnz(AsmOperand label, std::wstring comment=L"");
    AsmInstruction js(AsmOperand label, std::wstring comment=L"");
    AsmInstruction jns(AsmOperand label, std::wstring comment=L"");
    AsmInstruction jl(AsmOperand label, std::wstring comment=L"");
    AsmInstruction jge(AsmOperand label, std::wstring comment=L"");
    AsmInstruction jb(AsmOperand label, std::wstring comment=L"");
    AsmInstruction inc(AsmOperand d, AsmInstruction::InstructionSize size=AsmInstruction::IMPLICIT, std::wstring comment=L"");
    AsmInstruction dec(AsmOperand d, AsmInstruction::InstructionSize size=AsmInstruction::IMPLICIT, std::wstring comment=L"");
    AsmInstruction neg(AsmOperand d, AsmInstruction::InstructionSize size=AsmInstruction::IMPLICIT, std::wstring comment=L"");
    AsmInstruction _not(AsmOperand d, AsmInstruction::InstructionSize size=AsmInstruction::IMPLICIT, std::wstring comment=L"");
    AsmInstruction mul(AsmOperand s, AsmInstruction::InstructionSize size=AsmInstruction::IMPLICIT, std::wstring comment=L"");
    AsmInstruction imul(AsmOperand s, AsmInstruction::InstructionSize size=AsmInstruction::IMPLICIT, std::wstring comment=L"");
    AsmInstruction div(AsmOperand s, AsmInstruction::InstructionSize size=AsmInstruction::IMPLICIT, std::wstring comment=L"");
    AsmInstruction idiv(AsmOperand s, AsmInstruction::InstructionSize size=AsmInstruction::IMPLICIT, std::wstring comment=L"");
    AsmInstruction setz(AsmOperand s, std::wstring comment=L"");
    AsmInstruction setnz(AsmOperand s, std::wstring comment=L"");
    AsmInstruction sets(AsmOperand s, std::wstring comment=L"");
    AsmInstruction setns(AsmOperand s, std::wstring comment=L"");
    AsmInstruction setg(AsmOperand s, std::wstring comment=L"");
    AsmInstruction setge(AsmOperand s, std::wstring comment=L"");
    AsmInstruction setl(AsmOperand s, std::wstring comment=L"");
    AsmInstruction setle(AsmOperand s, std::wstring comment=L"");
    AsmInstruction seta(AsmOperand s, std::wstring comment=L"");
    AsmInstruction setae(AsmOperand s, std::wstring comment=L"");
    AsmInstruction setb(AsmOperand s, std::wstring comment=L"");
    AsmInstruction setbe(AsmOperand s, std::wstring comment=L"");
    AsmInstruction cbw(std::wstring comment=L"");
    AsmInstruction cwde(std::wstring comment=L"");
    AsmInstruction cdqe(std::wstring comment=L"");
    AsmInstruction cwd(std::wstring comment=L"");
    AsmInstruction cdq(std::wstring comment=L"");
    AsmInstruction cmovz(AsmOperand d, AsmOperand s, AsmInstruction::InstructionSize size=AsmInstruction::IMPLICIT, std::wstring comment=L"");
    AsmInstruction cmovnz(AsmOperand d, AsmOperand s, AsmInstruction::InstructionSize size=AsmInstruction::IMPLICIT, std::wstring comment=L"");
    AsmInstruction cmovs(AsmOperand d, AsmOperand s, AsmInstruction::InstructionSize size=AsmInstruction::IMPLICIT, std::wstring comment=L"");
    AsmInstruction cmovg(AsmOperand d, AsmOperand s, AsmInstruction::InstructionSize size=AsmInstruction::IMPLICIT, std::wstring comment=L"");

    // SIMD
    AsmInstruction movq(AsmOperand d, AsmOperand s, AsmInstruction::InstructionSize size=AsmInstruction::IMPLICIT, std::wstring comment=L"");
    AsmInstruction movd(AsmOperand d, AsmOperand s, AsmInstruction::InstructionSize size=AsmInstruction::IMPLICIT, std::wstring comment=L"");
    AsmInstruction movsd(AsmOperand d, AsmOperand s, AsmInstruction::InstructionSize size=AsmInstruction::IMPLICIT, std::wstring comment=L"");
    AsmInstruction movss(AsmOperand d, AsmOperand s, AsmInstruction::InstructionSize size=AsmInstruction::IMPLICIT, std::wstring comment=L"");
    AsmInstruction cvtsi2sd(AsmOperand d, AsmOperand s, std::wstring comment=L"");
    AsmInstruction cvtsd2si(AsmOperand d, AsmOperand s, std::wstring comment=L"");
    AsmInstruction cvtss2sd(AsmOperand d, AsmOperand s, std::wstring comment=L"");
    AsmInstruction cvtsd2ss(AsmOperand d, AsmOperand s, std::wstring comment=L"");
    AsmInstruction cvtsi2ss(AsmOperand d, AsmOperand s, std::wstring comment=L"");
    AsmInstruction cvtss2si(AsmOperand d, AsmOperand s, std::wstring comment=L"");
    AsmInstruction addsd(AsmOperand d, AsmOperand s, std::wstring comment=L"");
    AsmInstruction subsd(AsmOperand d, AsmOperand s, std::wstring comment=L"");
    AsmInstruction mulsd(AsmOperand d, AsmOperand s, std::wstring comment=L"");
    AsmInstruction divsd(AsmOperand d, AsmOperand s, std::wstring comment=L"");
    AsmInstruction addss(AsmOperand d, AsmOperand s, std::wstring comment=L"");
    AsmInstruction subss(AsmOperand d, AsmOperand s, std::wstring comment=L"");
    AsmInstruction mulss(AsmOperand d, AsmOperand s, std::wstring comment=L"");
    AsmInstruction divss(AsmOperand d, AsmOperand s, std::wstring comment=L"");
    AsmInstruction roundsd(AsmOperand d, AsmOperand s, int roundingMode, std::wstring comment=L"");
    AsmInstruction roundss(AsmOperand d, AsmOperand s, int roundingMode, std::wstring comment=L"");

    AsmInstruction reserveSpaceOnStack(int size, std::wstring comment=L"");
    AsmInstruction removeReservedSpaceFromStack(int size, std::wstring comment=L"");
    std::vector<AsmInstruction> exit(int errorCode, std::wstring comment=L"");

    AsmOperand label(std::wstring label);
    AsmOperand addressMov(AsmOperand op, int offset=0);
    AsmOperand addressLea(std::wstring address);
    AsmOperand imm(std::wstring value);

    AsmOperand XMM0();
    AsmOperand XMM1();
    AsmOperand RAX(int size=AsmInstruction::QWORD);
    AsmOperand RBX(int size=AsmInstruction::QWORD);
    AsmOperand RCX(int size=AsmInstruction::QWORD);
    AsmOperand RDX(int size=AsmInstruction::QWORD);
    AsmOperand RDI(int size=AsmInstruction::QWORD);
    AsmOperand RSI(int size=AsmInstruction::QWORD);
    AsmOperand RSP(int size=AsmInstruction::QWORD);
    AsmOperand RBP(int size=AsmInstruction::QWORD);
    AsmOperand R8(int size=AsmInstruction::QWORD);
    AsmOperand R9(int size=AsmInstruction::QWORD);
    AsmOperand R10(int size=AsmInstruction::QWORD);
    AsmOperand R11(int size=AsmInstruction::QWORD);
    AsmOperand brk_end();

    AsmInstruction::InstructionSize size(int size);
    AsmInstruction::InstructionSize getSizeOfReg(AsmOperand reg);

}