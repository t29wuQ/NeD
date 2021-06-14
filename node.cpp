#include "ned.h"
#include <iostream>
#include <llvm/IR/BasicBlock.h>

namespace ned {
    Node::Node(llvm::BasicBlock &bb) {
        this->bb = &bb;
    }

    void Node::show_bb() {
        std::cout << "show instruction" << std::endl;
        auto i = 0;
        for (auto &instr: *this->bb) {
            std::cout << "%" << i << ": " << instr.getOpcodeName() << std::endl;
            i++;
        }
    }
};
