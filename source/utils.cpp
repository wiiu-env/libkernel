#include <cstdint>
#include <coreinit/cache.h>
#include <coreinit/memorymap.h>
#include "kernel/kernel.h"

void KernelReadPTE(uint32_t outputAddr, int32_t length) {
    uint32_t dst = (uint32_t) OSEffectiveToPhysical(outputAddr);
    uint32_t src = 0xFFE20000;
    ICInvalidateRange(&dst, 4);
    DCFlushRange(&dst, 4);
    DCFlushRange(&src, 4);
    KernelCopyData(dst, src, length);
    DCFlushRange((void *)outputAddr, length);
    ICInvalidateRange((void *)outputAddr, length);
}

void KernelWritePTE(uint32_t inputAddr, int32_t length) {
    uint32_t dst = 0xFFE20000;
    uint32_t src = (uint32_t) OSEffectiveToPhysical(inputAddr);
    ICInvalidateRange(&src, 4);
    DCFlushRange(&src, 4);
    KernelCopyData(dst, src, length);
}

void KernelNOPAtPhysicalAddress(uint32_t addr) {
    uint32_t dst = 0x60000000;
    ICInvalidateRange(&dst, 4);
    DCFlushRange(&dst, 4);
    KernelCopyData(addr,(uint32_t)OSEffectiveToPhysical((uint32_t)&dst),4);
}

