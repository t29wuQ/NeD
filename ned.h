#include <llvm/IR/BasicBlock.h>

void testPrint();
namespace ned {
    class Node {
        private:
            Node *lhs;
            Node *rhs;
            llvm::BasicBlock *bb;

        public:
            Node(llvm::BasicBlock &bb);
            void show_bb();
    };

}
