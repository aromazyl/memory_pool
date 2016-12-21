/*
 * memory_block.cc
 * Copyright (C) 2016 zhangyule <zyl2336709@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include "memory_block.h"


namespace zyl {
void MemoryBlock::Init(std::size_t blockSize, unsigned char blocks) {
  pData_ = (char*)malloc(blockSize * blocks * sizeof(char));
  assert(pData_);
  blocksAvaliable_ = blocks;
  firstAvaliableBlock_ = 0;
  char* p = pData_;
  for (std::size_t i = 0; i < blockSize; ++i) {
    *(pData_ + i * blockSize) = i + 1;
  }
}

void* MemoryBlock::Allocate(std::size_t blockSize) {
  if (blocksAvaliable_ == 0) return NULL;
  --blocksAvaliable_;
  char* pRet = pData_ + firstAvaliableBlock_ * blockSize;
  firstAvaliableBlock_ = *pRet;
  return static_cast<void*>(pRet);
}

void MemoryBlock::Deallocate(void* p, std::size_t blockSize) {
  char* toRelease = static_cast<char*>(p);
  assert(toRelease >= pData_);
  assert((toRelease - pData_) % blockSize == 0);
  firstAvaliableBlock_ = static_cast<char*>((toRelease - pData_) / blockSize);
  ++blocksAvaliable_;
}
}
