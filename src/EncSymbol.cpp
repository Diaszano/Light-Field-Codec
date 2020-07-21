#include "EncSymbol.h"

EncSymbol::EncSymbol(uint bufferSize) : EncBitstreamBuffer(bufferSize){}

EncSymbol::~EncSymbol() {}

void EncSymbol::writeCode2Buffer(Symbol *sym) {
    unsigned int mask = 1 << (sym->len - 1);
    Byte *byte_buf = &this->byte_buf;
    uint *bits_to_go = &this->bits_to_go;
    int i;

    for (i = 0; i <  sym->len; ++i){
        *byte_buf <<= 1u;

        if (sym->bitparttern & mask){
            *byte_buf |= 1u;
        }

        mask >>= 1u;

        if ((--(*bits_to_go)) == 0) {
            *bits_to_go = 8;
            this->buffer[this->byte_pos++] = *byte_buf;
            *byte_buf = 0;
        }
    }
}

int EncSymbol::expGolombEncode_ui(int value) {
    int m = 0, inf = 0;
    Symbol sym{};

    sym.value = value;

    m = floor(log2(sym.value + 1));
    inf = sym.value + 1 - pow(2, m);

    sym.len = (m * 2) + 1;
    sym.bitparttern = sym.value + 1;

    this->writeCode2Buffer(&sym);

    return sym.len;
}