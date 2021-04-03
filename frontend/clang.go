package frontend

import (
)

type Clang struct {
    bin string
}

func NewClang(bin string) *Clang {
    return &Clang{
        bin,
    }
}

func (clang *Clang) GenLlvmIr(input string) {

}
