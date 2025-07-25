#ifndef GDT_H
#define GDT_H
#include <SmartOS.h>
#ifdef __cplusplus
struct __attribute__((packed)) GDTEntry
{
    uint16_t limit0;
    uint16_t base0;
    uint8_t base1;
    uint8_t access;
    uint8_t limit1: 4;
    uint8_t flags: 4;
    uint8_t base2;
    GDTEntry();
    GDTEntry(uint32_t base, uint32_t limt, uint8_t access, uint8_t flags);
};
struct __attribute__((packed)) GDTSystemEntry
{
    uint16_t limit0;
    uint16_t base0;
    uint8_t base1;
    uint8_t access;
    uint8_t limit1: 4;
    uint8_t flags: 4;
    uint8_t base2;
    uint32_t base3;
    uint32_t rsv;
    GDTSystemEntry();
    GDTSystemEntry(uint64_t base, uint32_t limit, uint8_t access, uint8_t flags);
};
class GDT
{
private:
    GDTEntry gdtEntries[20];
public:
    GDT();
    void load(uint64_t cs, uint64_t ds, uint64_t es, uint64_t fs, uint64_t gs, uint64_t ss);
};
void initializeGDT();
#endif
#endif