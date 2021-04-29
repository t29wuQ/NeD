#include <iostream>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IRReader/IRReader.h>
#include <llvm/Support/SourceMgr.h>

int main(int argc, char** argv) {
    if (argc < 2) {
        llvm::errs() << "Expected an argument - IR file name\n";
        exit(1);
    }

    llvm::LLVMContext Context;
    llvm::SMDiagnostic Err;
    auto module = llvm::parseIRFile(argv[1], Err, Context);

    if (!module) {
        Err.print(argv[0], llvm::errs());
        return 1;
    }

    auto func = module->getFunction("packet_in");
    std::cout << "function name: " << func->getName().data() << std::endl;
    for (auto &bb: *func) {
        auto i = 0;
        for (auto &instr: bb) {
            std::cout << "%" << i << ": " << instr.getOpcodeName() << std::endl;
            i++;
        }
    }

    return 0;
}
