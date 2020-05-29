#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#include <cstdint>
extern void KernelCopyData(uint32_t dst, uint32_t src, uint32_t len);

void KernelReadPTE(uint32_t outputAddr, int32_t length);

void KernelWritePTE(uint32_t inputAddr, int32_t length);

void KernelNOPAtPhysicalAddress(uint32_t addr);

#ifdef __cplusplus
} // extern "C"
#endif