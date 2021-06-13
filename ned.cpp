#include <iostream>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IRReader/IRReader.h>
#include <llvm/Support/SourceMgr.h>

using namespace std;

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

    auto &funcs = module->getFunctionList();
    for (auto &func : funcs) {
        cout << func.getName().str() << endl;
        for (auto &bb: func) {
            auto i = 0;
            for (auto &instr: bb) {
                cout << "%" << i << ": " << instr.getOpcodeName() << endl;
                // instr.dump();
                i++;
            }
        }
    }

    return 0;
}
