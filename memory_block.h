/*
 * memory_block.h
 * Copyright (C) 2016 zhangyule <zyl2336709@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef MEMORY_BLOCK_H
#define MEMORY_BLOCK_H

#include <stdio.h>

namespace zyl {
class MemoryBlock {
  public:
    void Init(std::size_t blockSize, unsigned char blocks);
    void* Allocate(std::size_t blockSize);
    void Deallocate(void* p, std::size_t blockSize);
  private:
    char* pData_;
    char blocksAvaliable_;
    char firstAvaliableBlock_;
};
}

#endif /* !MEMORY_BLOCK_H */
